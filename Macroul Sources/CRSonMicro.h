#ifndef CRSONMICRO_H
#define CRSONMICRO_H

#include <wx/frame.h>
#if defined(__UNIX__)
    #include <pthread.h>
#elif defined(__WXMSW__)
    #include <windows.h>
    #include <wx/msw/winundef.h>
#endif

#define CODE_LENGTH 64

extern wxEventType TAG_RECEIVED;

class CCRSonMicro
{
public:
    CCRSonMicro(wxWindow* pParent, const char* szPort, int iTimeoutInMs = 2000);
    virtual ~CCRSonMicro();

    // opens and sets parameters for the specified RS232 serial port
	// returns false if the operation fails
	bool Initialize(bool bBaud9600 = true);

    // start the cardreader by creating the thread
    // returns false if the operation fails
	bool Start(unsigned long long& nCardCode);

	// stops the card reader (by destroying the thread)
	void Stop();

    // sends the data to the serial port
	int SendData(unsigned char* pData, int iByteCount);

	// receives data from the serial port
	int ReceiveData(unsigned char* pBuffer, int iByteCount);

public:
    wxWindow* m_pParent;
    int m_iRetryCount;
    volatile bool m_bMustExit;

protected:
    char* m_szPort;
    int m_iTimeoutInMs;
    bool m_bThreadCreated;
    #if defined(__UNIX__)
        pthread_t m_Thread;
        pthread_mutex_t m_Mutex;
        int m_Device;
    #elif defined(__WXMSW__)
        HANDLE m_Thread;
        HANDLE m_Mutex;
        HANDLE m_Device;
    #endif
};

#endif
