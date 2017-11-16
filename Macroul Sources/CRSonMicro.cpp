#include "CRSonMicro.h"
#if defined(__UNIX__)
    #include <string.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <termios.h>
    #include <errno.h>
#elif defined(__WXMSW__)
    #include <windows.h>
#endif
//#include "Logger.h"

//using namespace Dud;
//extern CLogger g_Logger;

wxEventType TAG_RECEIVED = wxNewEventType();

#define SEEK_TAG_COMMAND	{0xFF, 0x00, 0x01, 0x82, 0x83}
#define RESET_COMMAND	    {0xFF, 0x00, 0x01, 0x80, 0x81}

typedef struct
{
    CCRSonMicro* pCardReader;
    unsigned long long* pCode;
} THREAD_ARG;


void* ThreadFunc(void* pArg)
{
    THREAD_ARG* pArgs = static_cast<THREAD_ARG*>(pArg);
    CCRSonMicro* pCardReader = pArgs->pCardReader;
    unsigned long long* pCode = pArgs->pCode;
    delete pArgs;

    unsigned char arrBuffer[CODE_LENGTH];
    memset(arrBuffer, 0, CODE_LENGTH);
    int iErrorCount = 0;
    int nMessageLength = 0;

    // send to the device the command for receiving the card number
    while (true)
    {
        unsigned char FRAME[] = SEEK_TAG_COMMAND;
        if (pCardReader->SendData(FRAME, 5) == -1)
        {
            iErrorCount++;
            if (iErrorCount == pCardReader->m_iRetryCount)
            {
                *pCode = 0;

                wxCommandEvent TagEvent(TAG_RECEIVED);
                wxPostEvent(pCardReader->m_pParent, TagEvent);
                return NULL;
            }
        }
        else
        {
            break;
        }
    }

    // get the immediate response, which says if the command is in progress or failed
    while (true)
    {
        // get message length
        int iResult = pCardReader->ReceiveData(arrBuffer, 3);
        if (iResult <= 0)
        {
            iErrorCount++;
            if (iErrorCount == pCardReader->m_iRetryCount)
            {
                *pCode = 0;

                wxCommandEvent TagEvent(TAG_RECEIVED);
                wxPostEvent(pCardReader->m_pParent, TagEvent);
                return NULL;
            }
        }
        else
        {
            nMessageLength = arrBuffer[2];
            iResult = pCardReader->ReceiveData(arrBuffer, nMessageLength+1); // +1 for Check Sum
            if (iResult <= 0)
            {
                iErrorCount++;
                if (iErrorCount == pCardReader->m_iRetryCount)
                {
                    *pCode = 0;

                    wxCommandEvent TagEvent(TAG_RECEIVED);
                    wxPostEvent(pCardReader->m_pParent, TagEvent);
                    return NULL;
                }
            }
            else
            {
                iErrorCount = 0;
                break;
            }
        }
    }

    // analyze the response (should be command in progress)
    bool bCommandInProgress = false;
    //if (arrBuffer[2] == 0x02)
    if (nMessageLength == 0x02)
    {
        //if (arrBuffer[4] == 0x4C)
        if (arrBuffer[1] == 0x4C)
        {
            bCommandInProgress = true;
        }
        //else if (arrBuffer[4] == 0x55)
        else
        {
            *pCode = 0;
        }
    }
    memset(arrBuffer, 0, CODE_LENGTH);

    // wait for the tag, with the possibility to exit
    if (bCommandInProgress)
    {
        while (!pCardReader->m_bMustExit)
        {
            if (pCardReader->ReceiveData(arrBuffer, CODE_LENGTH) > 0)
            {
                if (arrBuffer[2] == 0x06 || arrBuffer[2] == 0x09)
                {
                    // code received
                    int iCodeLength = arrBuffer[2] - 2; // -1 for Command and -1 for Tag Type
                    // if we copy the bytes from arrBuffer[5] to arrBuffer[5+iCodeLength-1],
                    // they will be reversed in the unigned long long variable, so do the
                    // swapping beforehand
                    for (int i=0; i<iCodeLength/2; i++)
                    {
                        unsigned char aux = arrBuffer[5+i];
                        arrBuffer[5+i] = arrBuffer[5+iCodeLength-1-i];
                        arrBuffer[5+iCodeLength-1-i] = aux;
                    }
                    memcpy(pCode, &arrBuffer[5], iCodeLength);
                }

                break;
            }
        }
    }

    // reset card reader
    while (true)
    {
        unsigned char FRAME[] = RESET_COMMAND;
        if (pCardReader->SendData(FRAME, 5) == -1)
        {
            iErrorCount++;
            if (iErrorCount == pCardReader->m_iRetryCount)
            {
                wxCommandEvent TagEvent(TAG_RECEIVED);
                wxPostEvent(pCardReader->m_pParent, TagEvent);
                return NULL;
            }
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        int iResult = pCardReader->ReceiveData(arrBuffer, CODE_LENGTH);
        if (iResult <= 0)
        {
            iErrorCount++;
            if (iErrorCount == pCardReader->m_iRetryCount)
            {
                wxCommandEvent TagEvent(TAG_RECEIVED);
                wxPostEvent(pCardReader->m_pParent, TagEvent);
                return NULL;
            }
        }
        else
        {
            memset(arrBuffer, 0, CODE_LENGTH);
            break;
        }
    }

    // send the tag to the card reader
    if (!pCardReader->m_bMustExit)
    {
        wxCommandEvent TagEvent(TAG_RECEIVED);
        wxPostEvent(pCardReader->m_pParent, TagEvent);
    }

    return NULL;
}

CCRSonMicro::CCRSonMicro(wxWindow* pParent, const char* szPort, int iTimeoutInMs /*= 2000*/)
: m_pParent(pParent)
, m_iRetryCount(3)
, m_szPort(NULL)
, m_iTimeoutInMs(iTimeoutInMs)
, m_bThreadCreated(false)
{
    #if defined(__UNIX__)
        pthread_mutex_init(&m_Mutex, NULL);
    #elif defined(__WXMSW__)
        m_Mutex = CreateMutex(NULL, FALSE, NULL);
    #endif

    if (szPort != NULL)
    {
        #if defined(__UNIX__)
            m_szPort = new char[strlen(szPort) + 1];
            strcpy(m_szPort, szPort);
        #elif defined(__WXMSW__)
            m_szPort = new char[4 + strlen(szPort) + 1];
            strcpy(m_szPort, "\\\\.\\");
            strcat(m_szPort, szPort);
        #endif
    }
}

CCRSonMicro::~CCRSonMicro()
{
    if (m_bThreadCreated)
    {
        Stop();
    }

    #if defined(__UNIX__)
        pthread_mutex_destroy(&m_Mutex);
    #elif defined(__WXMSW__)
        WaitForSingleObject(m_Mutex, INFINITE);
        ReleaseMutex(m_Mutex);
    #endif

    if (m_szPort != NULL)
    {
        delete[] m_szPort;
    }

    #if defined(__UNIX__)
        int nInvalidValue = -1;
	#elif defined(__WXMSW__)
        void* nInvalidValue = INVALID_HANDLE_VALUE;
    #endif
    if (m_Device != nInvalidValue)
	{
	    #if defined(__UNIX__)
            close(m_Device);
	    #elif defined(__WXMSW__)
	        CloseHandle(m_Device);
	    #endif
	}
}

bool CCRSonMicro::Initialize(bool bBaud9600 /*= true*/)
{
	// open serial port device
	#if defined(__UNIX__)
        m_Device = open(m_szPort, O_RDWR | O_NOCTTY | O_NDELAY);
        int nInvalidValue = -1;
	#elif defined(__WXMSW__)
        //m_Device = CreateFileA(m_szPort, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
        m_Device = CreateFileA(m_szPort, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, 0);
        HANDLE nInvalidValue = INVALID_HANDLE_VALUE;
    #endif
	if (m_Device == nInvalidValue)
	{
	    #if defined(__WXMSW__)
	    int nError = GetLastError();
//	    LERROR("Could not open port %s: %d", m_szPort, nError);
	    #endif // defined
	    return NULL;
	}

    // create the port parameters structure
    #if defined(__UNIX__)
        struct termios sOptions;
        memset(&sOptions, 0, sizeof(sOptions));
    #elif defined(__WXMSW__)
        DCB sOptions = {0};
        sOptions.DCBlength = sizeof(DCB);
    #endif

	// set the parameters
	bool bInvalidValue = false;
	#if defined(__UNIX__)
        // baud rate
        if (bBaud9600)
        {
            cfsetispeed(&sOptions, B9600);
            cfsetospeed(&sOptions, B9600);
        }
        else
        {
            cfsetispeed(&sOptions, B19200);
            cfsetospeed(&sOptions, B19200);
        }
        // enable the receiver and set local mode
        sOptions.c_cflag |= (CLOCAL | CREAD);
        // 8 bit data length
        sOptions.c_cflag &= ~CSIZE;
        sOptions.c_cflag |= CS8;
        // no parity
        sOptions.c_cflag &= ~PARENB;
        // one stop bit
        sOptions.c_cflag &= ~CSTOPB;
        // wait for at leas one character to be received
        sOptions.c_cc[VMIN] = 1;
        sOptions.c_cc[VTIME] = 0;

	    bInvalidValue = (tcsetattr(m_Device, TCSANOW, &sOptions) == -1);
	#elif defined(__WXMSW__)
        if (bBaud9600)
        {
            bInvalidValue = (!BuildCommDCB(_T("9600, n, 8, 1"), &sOptions));
        }
        else
        {
            bInvalidValue = (!BuildCommDCB(_T("19200, n, 8, 1"), &sOptions));
        }
        if (!bInvalidValue)
        {
            sOptions.fBinary = TRUE;
            bInvalidValue = (!SetCommState(m_Device, &sOptions));

            if (!bInvalidValue)
            {
                COMMTIMEOUTS timeouts;
                /*
                timeouts.ReadIntervalTimeout = MAXDWORD;
                timeouts.ReadTotalTimeoutMultiplier = 0;
                timeouts.ReadTotalTimeoutConstant = 0;
                timeouts.WriteTotalTimeoutMultiplier = 0;
                timeouts.WriteTotalTimeoutConstant = 0;
                */
                timeouts.ReadIntervalTimeout = 100;
                timeouts.ReadTotalTimeoutMultiplier = 10;
                timeouts.ReadTotalTimeoutConstant = 100;
                timeouts.WriteTotalTimeoutMultiplier = 10;
                timeouts.WriteTotalTimeoutConstant = 100;

                bInvalidValue = (!SetCommTimeouts(m_Device, &timeouts));
            }
        }
	#endif
	if (bInvalidValue)
	{
	    return false;
	}

    // make the port non-blocking
	#if defined(__UNIX__)
        fcntl(m_Device, F_SETFL, FNDELAY);
	#endif
        // on Windows, the FILE_FLAG_OVERLAPPED flag assures this

    return true;
}

bool CCRSonMicro::Start(unsigned long long& nCardCode)
{
    // create the thread
    THREAD_ARG* pArg = new THREAD_ARG;
    pArg->pCardReader = this;
    pArg->pCode = &nCardCode;

    #if defined(__UNIX__)
        m_bThreadCreated = (pthread_create(&m_Thread, NULL, ThreadFunc, pArg) == 0);
    #elif defined(__WXMSW__)
        DWORD nThreadId;
        m_Thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadFunc, pArg, 0, &nThreadId);
        m_bThreadCreated = (m_Thread != NULL);
    #endif

    if (m_bThreadCreated)
    {
        #if defined(__UNIX__)
            pthread_mutex_lock(&m_Mutex);
        #elif defined(__WXMSW__)
            WaitForSingleObject(m_Mutex, INFINITE);
        #endif
        m_bMustExit = false;
        #if defined(__UNIX__)
            pthread_mutex_unlock(&m_Mutex);
        #elif defined(__WXMSW__)
            ReleaseMutex(m_Mutex);
        #endif
    }

    return m_bThreadCreated;
}

void CCRSonMicro::Stop()
{
    #if defined(__UNIX__)
        pthread_mutex_lock(&m_Mutex);
    #elif defined(__WXMSW__)
        WaitForSingleObject(m_Mutex, INFINITE);
    #endif
    m_bMustExit = true;
    #if defined(__UNIX__)
        pthread_mutex_unlock(&m_Mutex);
    #elif defined(__WXMSW__)
        ReleaseMutex(m_Mutex);
    #endif

    if (m_bThreadCreated)
    {
        #if defined(__UNIX__)
            pthread_join(m_Thread, NULL);
        #elif defined(__WXMSW__)
            WaitForSingleObject(m_Thread, INFINITE);
        #endif

        m_bThreadCreated = false;
    }
}

int CCRSonMicro::SendData(unsigned char* pData, int iByteCount)
{
    #if defined(__WXMSW__)
        OVERLAPPED ovWrite = {0};
        ovWrite.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
        if (ovWrite.hEvent == NULL)
        {
            return -1;
        }
    #endif
    const int DELAY = 200;
    int iSleptInMs = 0;
    int iBytesWritten = -1;

    #if defined(__WXMSW__)
        DWORD nBytesWritten = 0;
        if (!WriteFile(m_Device, pData, iByteCount, &nBytesWritten, &ovWrite))
        {
            if (GetLastError() != ERROR_IO_PENDING)
            {
                // error
                CloseHandle(ovWrite.hEvent);
                return -1;
            }
        }
        else
        {
            // operation returned immediately
            CloseHandle(ovWrite.hEvent);
            return (int)nBytesWritten;
        }
    #endif

    bool bNotCompleted = false;
    while (true)
    {
        #if defined(__UNIX__)
            iBytesWritten = write(m_Device, pData, iByteCount);
            bNotCompleted = (iBytesWritten == -1 && errno == EAGAIN);
        #elif defined(__WXMSW__)
            bNotCompleted = (WaitForSingleObject(ovWrite.hEvent, DELAY) != WAIT_OBJECT_0);
        #endif

        if (bNotCompleted)
        {
            #if defined(__UNIX__)
                usleep(DELAY*1000);
            #endif

            iSleptInMs += DELAY;
            if (iSleptInMs >= m_iTimeoutInMs)
            {
                #if defined(__WXMSW__)
                    // cancel the requested operations
                    if (CancelIo(m_Device))
                    {
                        // check if result wasn't received though
                        DWORD nBytesWritten;
                        if (!GetOverlappedResult(m_Device, &ovWrite, &nBytesWritten, FALSE))
                        {
                            iBytesWritten = -1;
                        }
                        else
                        {
                            iBytesWritten = (int)nBytesWritten;
                        }
                    }
                #endif
                break;
            }
        }
        else
        {
            #if defined(__WXMSW__)
                DWORD nBytesWritten;
                if (!GetOverlappedResult(m_Device, &ovWrite, &nBytesWritten, FALSE))
                {
                    iBytesWritten = -1;
                }
                else
                {
                    iBytesWritten = (int)nBytesWritten;
                }
            #endif

            break;
        }
    }

    #if defined(__WXMSW__)
        CloseHandle(ovWrite.hEvent);
    #endif

    return iBytesWritten;
}

int CCRSonMicro::ReceiveData(unsigned char* pBuffer, int iByteCount)
{
    #if defined(__WXMSW__)
        OVERLAPPED ovRead = {0};
        ovRead.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
        if (ovRead.hEvent == NULL)
        {
            return -1;
        }
    #endif
    const int DELAY = 200;
    int iSleptInMs = 0;
    int iBytesRead = -1;

    #if defined(__WXMSW__)
        DWORD nBytesRead = 0;
        if (!ReadFile(m_Device, pBuffer, iByteCount, &nBytesRead, &ovRead))
        {
            if (GetLastError() != ERROR_IO_PENDING)
            {
                // error
                CloseHandle(ovRead.hEvent);
                return -1;
            }
        }
        else
        {
            // operation returned immediately
            CloseHandle(ovRead.hEvent);
            return (int)nBytesRead;
        }
    #endif

    bool bNotCompleted = false;
    while (true)
    {
        #if defined(__UNIX__)
            iBytesRead = read(m_Device, pBuffer, iByteCount);
            bNotCompleted = (iBytesRead == -1 && errno == EAGAIN);
        #elif defined(__WXMSW__)
            bNotCompleted = (WaitForSingleObject(ovRead.hEvent, DELAY) != WAIT_OBJECT_0);
        #endif

        if (bNotCompleted)
        {
            #if defined(__UNIX__)
                usleep(DELAY*1000);
            #endif

            iSleptInMs += DELAY;
            if (iSleptInMs >= m_iTimeoutInMs)
            {
                #if defined(__WXMSW__)
                    // cancel the requested operations
                    if (CancelIo(m_Device))
                    {
                        // check if result wasn't received though
                        DWORD nBytesRead;
                        if (!GetOverlappedResult(m_Device, &ovRead, &nBytesRead, FALSE))
                        {
                            iBytesRead = -1;
                        }
                        else
                        {
                            iBytesRead = (int)nBytesRead;
                        }
                    }

                #endif
                break;
            }
        }
        else
        {
            #if defined(__WXMSW__)
                DWORD nBytesRead;
                if (!GetOverlappedResult(m_Device, &ovRead, &nBytesRead, FALSE))
                {
                    iBytesRead = -1;
                }
                else
                {
                    iBytesRead = (int)nBytesRead;
                }
            #endif

            break;
        }
    }

    #if defined(__WXMSW__)
        CloseHandle(ovRead.hEvent);
    #endif

    return iBytesRead;
}
