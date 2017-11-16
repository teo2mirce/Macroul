#include "Misc.h"
extern wxString CWD;

DWORD FindProcessId(const std::wstring& processName)
{
  PROCESSENTRY32 processInfo;
  processInfo.dwSize = sizeof(processInfo);

  HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
  if ( processesSnapshot == INVALID_HANDLE_VALUE )
    return 0;

  Process32First(processesSnapshot, &processInfo);
  if ( !processName.compare(processInfo.szExeFile) )
  {
    CloseHandle(processesSnapshot);
    return processInfo.th32ProcessID;
  }

  while ( Process32Next(processesSnapshot, &processInfo) )
  {
    if ( !processName.compare(processInfo.szExeFile) )
    {
      CloseHandle(processesSnapshot);
      return processInfo.th32ProcessID;
    }
  }

  CloseHandle(processesSnapshot);
  return 0;
}

vector<wxString> split(wxString tok,wxString sep)
{
    vector<wxString> ret;
    while(tok.find(sep)!=-1)
    {
        size_t cate=tok.find(sep);
        ret.push_back(tok.substr(0,cate));
        tok=tok.substr(cate+sep.Len());
    }
    ret.push_back(tok);
    return ret;
}

#include<wx/file.h>
void Log(wxString v)
{
    ///return;
    wxFile fout(CWD+"\\log.txt",wxFile::write_append);
   time_t now = time(0);
   wxString wr;
   tm *ltm = localtime(&now);
   wr <<  ltm->tm_mday << "/";
   wr <<  1 + ltm->tm_mon<< "/";
   wr << 1900 + ltm->tm_year << " ";
   wr << 1 + ltm->tm_hour << ":";
   wr << 1 + ltm->tm_min << ":";
   wr << 1 + ltm->tm_sec << " ";
   wr << v << '\n';
   fout.Write(wr);
   fout.Close();
}
void Log(wxString v,long x)
{
    v<<" "<<x;
    Log(v);
}
#include <wx/textfile.h>
#include <wx/filename.h>
wxString ITOWS(int x)
{
    wxString ret;
    ret<<x;
    return ret;
}


#include <wx/stdpaths.h>

///User   0
///pcName 1
///wait   2
///com    3
///printscreen 4
///voce 5
///hotkey 6
///Planificari/Program 7
///Card 8
///Calitate 9
///Viteza 10
wxCriticalSection CS;
wxString ReadDatas(int x)
{
    CS.Enter();
    //Log("Current: "+wxGetCwd());
    wxTextFile f;
    wxString temp;
    if(wxFileName::FileExists(CWD+"\\config.ini")==false)
    {
        char tempys[300];
        strcpy(tempys,"ftype maky=");
        strcat(tempys,wxStandardPaths::Get().GetExecutablePath().data().AsChar());
        strcat(tempys," \"%1\"");
        system(tempys);
        system("assoc .Macrou=maky");

        f.Create(CWD+"\\config.ini");
        for(int a=0;a<15;a++)
        f.AddLine("");
        f.Write();
    }
    else
    {
        f.Open(CWD+"\\config.ini");
        temp=f.GetLine(x);
    }
    f.Close();
    CS.Leave();
    return temp;
}
void SaveDatas(wxString user,int x)
{
    CS.Enter();
    wxTextFile f;
    if(wxFileName::FileExists(CWD+"\\config.ini")==false)
    {
        CS.Leave();
        return;
    }
    f.Open(CWD+"\\config.ini");
    f.RemoveLine(x);
    f.InsertLine(user,x);
    f.Write();
    f.Close();
    CS.Leave();
}




///incepe distractia à la alta.h

int PrinScri(const char *pszFile) {
    HWND hStatic=GetDesktopWindow();
    BITMAPFILEHEADER bmfh = {0};
    BITMAPINFOHEADER bmih = {0};
    RECT rc = {0};
    HDC hdc1;
    HDC hdc2;
    HBITMAP aBmp;
    BITMAPINFO bi;
    HGDIOBJ OldObj;
    void *dibvalues;
    HANDLE fileHandle;
    DWORD bytes_write;
    DWORD bytes_written;
    int w;
    int h;

    hdc1 = GetWindowDC(hStatic);
    hdc2 = CreateCompatibleDC(hdc1);
    GetWindowRect(hStatic, &rc);
    w = rc.right-rc.left;
    h = rc.bottom-rc.top;

    bmih.biSize = sizeof(BITMAPINFOHEADER);
    bmih.biWidth = w;
    bmih.biHeight = h;
    bmih.biPlanes = 1;
    bmih.biBitCount = 24;
    bmih.biCompression = BI_RGB;
    bmih.biSizeImage = ((((bmih.biWidth * bmih.biBitCount) + 31) & ~31) >> 3) * bmih.biHeight;
    bi.bmiHeader = bmih;

    aBmp = CreateDIBSection(hdc1, &bi ,DIB_RGB_COLORS, (void**)&dibvalues, NULL, NULL);
    OldObj = SelectObject(hdc2, aBmp);
    BitBlt(hdc2, 0, 0, w, h, hdc1, 0, 0, SRCCOPY);
    bmfh.bfOffBits = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
    bmfh.bfSize = (3*bmih.biHeight*bmih.biWidth)+sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
    bmfh.bfType = 0x4d42;

    fileHandle = CreateFileA(pszFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    bytes_write = sizeof(BITMAPFILEHEADER);
    WriteFile(fileHandle, &bmfh, bytes_write, &bytes_written, NULL);
    bytes_write = sizeof(BITMAPINFOHEADER);
    WriteFile(fileHandle, &bmih, bytes_write, &bytes_written, NULL);
    bytes_write = bmih.biSizeImage;
    WriteFile(fileHandle, (void*)dibvalues, bytes_write, &bytes_written, NULL);

    CloseHandle(fileHandle);
    DeleteObject(SelectObject(hdc2,OldObj));
    DeleteDC(hdc2);
    ReleaseDC(hStatic, hdc1);
    return 0;
}
void move(int x,int y)
{
    POINT p;
    while(p.x!=x || p.y!=y)
    {
        GetCursorPos(&p);
        if(abs(1.0*p.x-x)>abs(1.0*p.y-y) && rand()%10==0)
        {
            if(p.x>x)
                SetCursorPos(p.x-1,p.y);
            if(p.x<x)
                SetCursorPos(p.x+1,p.y);
            for(int a=1;a<=15000+rand()%10000-5000;a++);
        }
        else
        if(rand()%10==0)
        {
            if(p.y>y)
                SetCursorPos(p.x,p.y-1);
            if(p.y<y)
                SetCursorPos(p.x,p.y+1);
            for(int a=1;a<=15000+rand()%10000-5000;a++);
        }
    }
}
void openWebsite(wchar_t *url)
{
    ShellExecute(0, 0, url, 0, 0 , SW_SHOW );
}
void Execute(wxString a,wxString b,wxString c,wxString d)
{
    SHELLEXECUTEINFO ShExecInfo = {0};
    ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
    if(b[0]=='1')
        ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
    ShExecInfo.fMask |= SEE_MASK_NOZONECHECKS;
    ShExecInfo.hwnd = NULL;
    ShExecInfo.lpVerb = NULL;
    ShExecInfo.lpFile = a;
    ShExecInfo.lpParameters = d;
    ShExecInfo.lpDirectory = NULL;
    if(c[0]=='1')
        ShExecInfo.nShow = SW_HIDE;
    else
        ShExecInfo.nShow = SW_SHOW;
    ShExecInfo.hInstApp = NULL;
    ShellExecuteEx(&ShExecInfo);
    if(b[0]=='1')
        WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
}
#include "CRSonMicro.h"

wxArrayString PrintAllPorts()
{
    wxArrayString x;
    {
        int nSize = 1024;
        for (int i = 0; i < 10; i++)
        {
            char* szBuffer = new char[nSize];
            int nRes = QueryDosDeviceA(NULL, szBuffer, nSize);
            if (nRes != 0)
            {
                char *pPos = szBuffer;
                while (*pPos != NULL)
                {
                    if (strstr(pPos, "COM") != NULL)
                        x.Add(pPos);
                        //wxMessageBox(wxString::FromAscii(pPos));
                    pPos += strlen(pPos) + 1;
                }
                delete[] szBuffer;
                break;
            }
            else
            {
                nRes = GetLastError();
                if (nRes == ERROR_INSUFFICIENT_BUFFER)
                {
                    nSize *= 2;
                    delete[] szBuffer;
                    continue;
                }
                else
                {
    //                LERROR("Could not get COM ports: %d", nRes);
                    delete[] szBuffer;
                    break;
                }
            }
        }
    }
    return x;
}

unsigned long long CardReader()
{
    ///asta iti zice care porturi sunt disponibile
    string SelectionPort  = "COM3";
    string nSelectionBaud = "9600";
    CCRSonMicro cardReader(NULL, SelectionPort.c_str());

    if (!cardReader.Initialize(wxAtoi(nSelectionBaud.c_str())))
    {
        Log("Invalid port specified, or no card reader present!");
//        LWARN("Invalid port specified, or no card reader present!");
        return -1;
    }
    unsigned long long m_nCardCode=0;
    if ((&cardReader) == NULL)
    {
        Log("Card reader error");
        (&cardReader)->Stop();
        return -1;
    }
    else
    {
        while(1)
        {
            (&cardReader)->Start(m_nCardCode);
            m_nCardCode=0;
            int i=0;
            while(m_nCardCode==0)
            {
                if(i>50)
                    return -1;
                i++;
                Sleep(10);
            }
            (&cardReader)->Stop();
            return m_nCardCode;
        }

    }
    (&cardReader)->Stop();
    return -1;
    //exit(0);
}
























#include <wx/tokenzr.h>

int GetVK(wxString x)
{
    if(x.length()==1)
    {
        if(x[0]>="A" && x[0]<="Z")
            return VkKeyScan(x[0]);
        if(x[0]>="0" && x[0]<="9")
            return VkKeyScan(x[0]);
    }
    if(x=="DEL")return VK_DELETE;
    if(x=="END")return VK_END;
    if(x=="HOME")return VK_HOME;
    if(x=="BACKSPACE")return VK_BACK;
    if(x=="TAB")return VK_TAB;
    if(x=="ENTER")return VK_RETURN;
    if(x=="ESC")return VK_ESCAPE;
    if(x=="SPACEBAR")return VK_SPACE;
    if(x=="PAGE_UP")return VK_PRIOR;
    if(x=="PAGE_DOWN")return VK_NEXT;
    if(x=="LEFT")return VK_LEFT;
    if(x=="UP")return VK_UP;
    if(x=="RIGHT")return VK_RIGHT;
    if(x=="DOWN")return VK_DOWN;
    if(x=="F1")return VK_F1;
    if(x=="F2")return VK_F2;
    if(x=="F3")return VK_F3;
    if(x=="F4")return VK_F4;
    if(x=="F5")return VK_F5;
    if(x=="F6")return VK_F6;
    if(x=="F7")return VK_F7;
    if(x=="F8")return VK_F8;
    if(x=="F9")return VK_F9;
    if(x=="F10")return VK_F10;
    if(x=="F11")return VK_F11;
    if(x=="F12")return VK_F12;
    if(x=="CTRL")return VK_CONTROL;
    if(x=="WIN")return VK_LWIN;
    if(x=="ALT")return VK_MENU;
    if(x=="SHIFT")return VK_SHIFT;
    if(x=="+")return VK_ADD;
    return 0x1A;
    Log("I dont know what the f is "+x);
}


void killProcessByName(wchar_t *ProcessName)
{
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof (pEntry);
    BOOL hRes = Process32First(hSnapShot, &pEntry);
    while (hRes)
    {
        if (wcscmp(pEntry.szExeFile, ProcessName) == 0)
        {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
                                          (DWORD) pEntry.th32ProcessID);
            if (hProcess != NULL)
            {
                TerminateProcess(hProcess, 9);
                CloseHandle(hProcess);
            }
        }
        hRes = Process32Next(hSnapShot, &pEntry);
    }
    CloseHandle(hSnapShot);
}
void killWindow(wchar_t *window)
{
    HWND x=FindWindow(NULL,window);
    PostMessage(x, WM_CLOSE, 0, 0);
    //DestroyWindow(x);
    return ;
    DWORD* processID = new DWORD;
	GetWindowThreadProcessId(x, processID);
	HANDLE handy;
	handy =OpenProcess(SYNCHRONIZE|PROCESS_TERMINATE, TRUE,*processID);
	TerminateProcess(handy,0);
}



#include <random>

#include "Editor.h"
void runLine(wxString input,int slip,wxString UID)
{
    wxString res;
    input.RemoveLast();
    if(input.StartsWith("Click(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString x,y,a1,a2;
        x=tok.GetNextToken();
        y=tok.GetNextToken();
        a1=tok.GetNextToken();
        a2=tok.GetNextToken();

        if(x.Contains("|"))
        {
            srand(GetTickCount());
            wxStringTokenizer xxx(x,"|");
            wxStringTokenizer yyy(y,"|");

            std::mt19937 rng(GetTickCount());
            int xmin=wxAtoi(xxx.GetNextToken()),xmax=wxAtoi(xxx.GetNextToken());
            int ymin=wxAtoi(yyy.GetNextToken()),ymax=wxAtoi(yyy.GetNextToken());

            std::uniform_int_distribution<int> genx(xmin,xmax);
            std::uniform_int_distribution<int> geny(ymin,ymax);
            int x=genx(rng);
            int y=geny(rng);
            SetCursorPos(x,y);
        }
        else
            SetCursorPos(wxAtoi(x),wxAtoi(y));
        if(a1=="Stanga")
        {
            if(a2=="Apasa")
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0,0,0);
            if(a2=="Ridica")
                mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
            if(a2=="Ambele")
                mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0,0,0);
        }
        if(a1=="Dreapta")
        {
            if(a2=="Apasa")
                mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0,0,0);
            if(a2=="Ridica")
                mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
            if(a2=="Ambele")
                mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0,0,0);
        }
        if(a1=="Mijloc")
        {
            if(a2=="Apasa")
                mouse_event(MOUSEEVENTF_MIDDLEDOWN, 0, 0,0,0);
            if(a2=="Ridica")
                mouse_event(MOUSEEVENTF_MIDDLEUP,0,0,0,0);
            if(a2=="Ambele")
                mouse_event(MOUSEEVENTF_MIDDLEDOWN|MOUSEEVENTF_MIDDLEUP, 0, 0,0,0);
        }
    }
    if(input.StartsWith("Muta(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString x,y,a1,a2;
        x=tok.GetNextToken();
        y=tok.GetNextToken();
        a1=tok.GetNextToken();
        if(a1=="Instant")
            SetCursorPos(wxAtoi(x),wxAtoi(y));
        if(a1=="Normal")
            move(wxAtoi(x),wxAtoi(y));
    }
    if(input.StartsWith("Email(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString x,y,a1,a2;
        x=tok.GetNextToken();

        y=tok.GetString();
        wxString ichar="";
        ichar<<"-t "<<x<<" -f teo2mircea@gmail.com -ssl -port 465 -auth -smtp smtp.gmail.com -sub \"Notificare Macrou\" -M \"";
        ichar<<y<<"\" -user youremail@gmail.com -pass yourpassword ";
        Log("altu");
        Log(ichar);
        Execute("mailsend1.19.exe","0","1",ichar);
    }


    if(input.StartsWith("Asteapta_schimbare(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString x;
        x=tok.GetNextToken();
        int ch1=0,ch2=0;
        if(x=="Fereastra")
            ch1=1;
        if(x=="Pixel")
            ch1=2;
        x=tok.GetNextToken();
        if(x!="Asteapta sa apara")///!=
            ch2=1;
        if(ch1==0)
        {
            x=tok.GetNextToken();
            std::wstring ws(x.size(), L' '); // Overestimate number of code points.
            ws.resize(std::mbstowcs(&ws[0], x.c_str(), x.size())); // Shrink to fit.
            if(ch2==0)
                while(FindProcessId(ws)==0)
                    Sleep(123);
            else
                while(FindProcessId(ws)!=0)
                    Sleep(123);
        }
        if(ch1==1)
        {
            x=tok.GetNextToken();
            if(ch2==0)
                while(FindWindowA(NULL,x)==0)
                    Sleep(123);
            else
                while(FindWindowA(NULL,x)!=0)
                    Sleep(123);
        }
        if(ch1==2)
        {
            x=tok.GetNextToken();
            wxString y=tok.GetNextToken();
            if(ch2==0)///sa apara
            {
                wxString R,G,B;
                R=tok.GetNextToken();
                G=tok.GetNextToken();
                B=tok.GetNextToken();
                COLORREF color;
                do
                {
                    Sleep(50);
                    HDC dc = GetDC(NULL);
                    color = GetPixel(dc, wxAtoi(x), wxAtoi(y));
                    ReleaseDC(NULL, dc);
                }while(wxAtoi(R)!=(int)GetRValue(color) || wxAtoi(G)!=(int)GetGValue(color) || wxAtoi(B)!=(int)GetBValue(color));
            }
            if(ch2==1)///sa se schimbe
            {
                HDC dc = GetDC(NULL);
                COLORREF color = GetPixel(dc, wxAtoi(x), wxAtoi(y));
                ReleaseDC(NULL, dc);
                int r=(int)GetRValue(color),g=(int)GetGValue(color),b=(int)GetBValue(color);
                do
                {
                    Sleep(50);
                    GetDC(NULL);
                    color = GetPixel(dc, wxAtoi(x), wxAtoi(y));
                    ReleaseDC(NULL, dc);
                }while(r==(int)GetRValue(color) && g==(int)GetGValue(color) && b==(int)GetBValue(color));
            }
        }
    }
    if(input.StartsWith("Asteapta(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString x;
        x=tok.GetNextToken();
        Sleep(wxAtoi(x));
    }
    if(input.StartsWith("Power(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString x,y;
        x=tok.GetNextToken();
        y=tok.GetNextToken();
        wxString ichar="";
        ichar<<"shutdown /";
        if(x=="Shutdown")
            ichar<<"s /t "<<y;
        if(x=="Restart")
            ichar<<"r /t "<<y;
        if(x=="Hibernate")
            ichar<<"h";
        ichar<<" /f";
        system(ichar);
    }
    if(input.StartsWith("Website(",&res))
    {
        ShellExecute(NULL, L"open", res,NULL, NULL, SW_SHOWNORMAL);
    }
    if(input.StartsWith("Executa(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString a,b,c,d;
        a=tok.GetNextToken();
        b=tok.GetNextToken();//asteapta
        c=tok.GetNextToken();//ascunde
        d=tok.GetString();//argumente

        wxString Ast,Asc;
        if(b=="Sync")
            Ast="1";
        else
            Ast="0";
        if("Ascunde"==c)
            Asc="1";
        else
            Asc="0";
        Execute(a,Ast,Asc,d);
    }
    if(input.StartsWith("Redimensionare(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString a,b,c,d,e;
        a=tok.GetNextToken();
        b=tok.GetNextToken();//asteapta
        c=tok.GetNextToken();//ascunde
        d=tok.GetNextToken();//ascunde
        e=tok.GetString();//argumente
        SetWindowPos(FindWindowA(NULL,e),0,atoi(a),atoi(b),atoi(c),atoi(d),SWP_SHOWWINDOW|SWP_NOZORDER);
    }
    if(input.StartsWith("Inchide(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString a,b,c,d;
        a=tok.GetNextToken();
        b=tok.GetString();
        if(a=="Proces")
            killProcessByName(b.wchar_str());
        else
            killWindow(b.wchar_str());
    }
    if(input.StartsWith("SSH(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString a,b,c,d,e,ichar="";
        a=tok.GetNextToken();
        b=tok.GetNextToken();
        c=tok.GetNextToken();
        d=tok.GetNextToken();
        e=tok.GetString();


        wxString file="ssh/";
        file<<RandCode();
        ofstream fout(file);
        fout<<e;
        fout.close();
        ichar<<b<<" -l "<<c<<" -pw "<<d<<" -m "<<file;

        wxString tip="";
        if(a=="Sync")
            tip="1";
        else
            tip="0";
        Execute("putty.exe",tip,"1",ichar);

        //putty.exe 192.168.2.102 -l pi -pw raspberry -m c2.txt
    }

    ///TREBUIE SA FACI 2 LISTE DE WXSTRINGURI CU CE E PE FIECARE LINIE/COLOANA CA ASTIA NU POT TINE MAI MULTE DE 400 CHARS PE WXlISTITEM!!!
   // wxListItem
//    input=fmm;
    if(input.StartsWith("Taste(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString x,y;
        x=tok.GetNextToken();
        if(x.StartsWith("O tasta"))
        {
            y=tok.GetNextToken();
            wxArrayString v;
            while (tok.HasMoreTokens())
                v.Add(tok.GetNextToken());
            if(y=="Apasa")
            {
                for(int a=0;a<v.size();a++)keybd_event(GetVK(v[a]),0xb8,KEYEVENTF_EXTENDEDKEY,0);
            }
            if(y=="Ridica")
            {
                for(int a=0;a<v.size();a++)
                    keybd_event(GetVK(v[a]),0xb8,KEYEVENTF_KEYUP|KEYEVENTF_EXTENDEDKEY,0);
            }
            if(y=="Ambele")
            {
                for(int a=0;a<v.size();a++)
                {
                    keybd_event(GetVK(v[a]),0xb8,KEYEVENTF_EXTENDEDKEY,0);

                }
                Sleep(5);
                for(int a=0;a<v.size();a++)
                {
                    keybd_event(GetVK(v[a]),0xb8,KEYEVENTF_KEYUP|KEYEVENTF_EXTENDEDKEY,0);
                }
            }
        }
        else
        {
            wxString temp= tok.GetNextToken();
            wxString temp2= tok.GetString();
            if(temp=="Deodata")
            {
                temp2.Replace("<nl>","\n");
                temp2.Replace("\n","\r\n");
                const wchar_t* v = temp2;
                const size_t len = wcslen(v) + 1;
                HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len*sizeof(wchar_t));
                memcpy(GlobalLock(hMem), v, len*sizeof(wchar_t));
                GlobalUnlock(hMem);
                OpenClipboard(0);
                EmptyClipboard();
                SetClipboardData(CF_UNICODETEXT, hMem);
                CloseClipboard();
                keybd_event(0x11, 0, 0, 0); // press ctrl
                keybd_event(0x56, 0, 0, 0); // press v
                keybd_event(0x56, 0, 2, 0); // release v
                keybd_event(0x11, 0, 2, 0); // release ctrl
            }
            else
            {
                for(int a=0;a<temp2.size();a++)
                {
                    char r=(int)temp2[a];
                    char print=-1;
                    if(r>='A' && r<='Z')
                    {
                        keybd_event(VK_SHIFT,0xb8,0,0);
                        Sleep(10);
                        print=r;
                    }
                    if(isalnum(r) || isspace(r))
                    {
                        keybd_event(VkKeyScan(r),0xb8,0,0);
                        Sleep(10);
                        keybd_event(VkKeyScan(r),0xb8,KEYEVENTF_KEYUP,0);
                        Sleep(75);
                    }
                    if(r>='A' && r<='Z')
                    {
                        keybd_event(VK_SHIFT,0xb8,KEYEVENTF_KEYUP,0);
                        Sleep(10);
                    }
                }
            }
        }
    }
    if(input.StartsWith("Macrou(",&res))
        DoTheTruffleShuffle(res,1,UID);
    if(input.StartsWith("Sablon(",&res))
    {
        map<wxString,vector<wxString> > Variabile;
        wxString input=res;
        int i=0;

        wxString CodMacrou;
        wxString Text;
        wxString Forma;
        wxString temp="select CodMacrou,Text,Forma from sablon where UserID="+UID+" and LEFT(Inceput,CHAR_LENGTH(Inceput)) = LEFT('"+res+"',CHAR_LENGTH(Inceput))";
        {
            Connection conn(false);
            if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
            {
                Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
                if (StoreQueryResult res = query.store())
                    if(res.num_rows())
                    CodMacrou=utf8_decode(res[0][0].c_str()),
                    Text=utf8_decode(res[0][1].c_str()),
                    Forma=utf8_decode(res[0][2].c_str());
                    else
                    {
                        wxMessageBox("Nu am gasit sablon care incepe asa");
                        return;
                    }
                    else
                        return;
            }
        }
        wxArrayString TIP,SEPARATOR,NUME;
        {
            wxStringTokenizer tok(Text, "\n");
            while(tok.HasMoreTokens())
            {
                wxString da=tok.GetNextToken();
                int poz=da.find("<|MAC|>");
                wxString q1=da.substr(0,poz);
                wxString q=da.substr(poz+7);
                int poz2=q.find("<|MAC|>");
                wxString q2=q.substr(0,poz2);
                wxString q3=q.substr(poz2+7);
                TIP.Add(q1);
                SEPARATOR.Add(q2);
                NUME.Add(q3);
            }
        }
        int n=NUME.size();
        if(TIP[n-1]!="Text")
            n--;
        vector<wxString> NumeVariabile;
        for(int a=0;a<n;a++)///sigur se termina cu text
        {
            wxString left=input.substr(i);
            wxString tip=TIP[a];
            wxString nume=NUME[a];
            wxString sep=SEPARATOR[a];
            if(tip=="Text")
            {
                wxString tocomp=left.substr(0,nume.size());
                if(nume.compare(tocomp))
                {
                    wxMessageBox("\""+left+"\" nu seamana cu \""+nume+"\"");
                    return;
                }
                i+=nume.size();
            }
            else
            {
                NumeVariabile.push_back(nume);
                if(TIP[a]=="Variabila simpla")
                {
                    vector<wxString> Var;
                    wxString next=NUME[a+1];///urmatorul text
                    if(left.find(next)==-1)
                    {
                        wxMessageBox("Nu am mai gasit textul asteptat: \""+next+"\"");
                        return;
                    }
                    size_t cate=left.find(next);
                    Var.push_back(left.substr(0,cate));
                    Variabile[nume]=Var;
                    i+=cate;
                }
                else///var multipla
                {
                    vector<wxString> Var;
                    wxString next=NUME[a+1];///urmatorul text
                    if(left.find(next)==-1)
                    {
                        wxMessageBox("Nu am mai gasit textul asteptat: \""+next+"\"");
                        return;
                    }
                    size_t cate=left.find(next);
                    wxString tot=left.substr(0,cate);

                    Var=split(tot,sep);///qqq

//                    wxStringTokenizer tok(tot,sep);
//                    while(tok.HasMoreTokens())
//                        Var.push_back(tok.GetNextToken());
                    Variabile[nume]=Var;
                    i+=cate;
                }
            }
        }
        int nm1=NUME.size()-1;
        if(TIP[nm1]=="Variabila simpla")
        {
            NumeVariabile.push_back(NUME[nm1]);
            wxString left=input.substr(i);
            vector<wxString> Var;
            Var.push_back(left);
            Variabile[NUME[nm1]]=Var;
        }
        if(TIP[nm1]=="Variabila multipla")
        {
            NumeVariabile.push_back(NUME[nm1]);
            wxString left=input.substr(i);
            vector<wxString> Var;
            wxString tot=left;
            Var=split(tot,SEPARATOR[nm1]);///qqq

//            wxStringTokenizer tok(tot,SEPARATOR[nm1]);
//            while(tok.HasMoreTokens())
//                Var.push_back(tok.GetNextToken());
            Variabile[NUME[nm1]]=Var;
        }
        Log("Eu zic ca sunt urmatoarele var:");
        for(int a=0;a<NumeVariabile.size();a++)
        {
            Log("Pt: "+NumeVariabile[a]);
            for(int b=0;b<Variabile[NumeVariabile[a]].size();b++)
                Log("\t\t- |"+Variabile[NumeVariabile[a]][b]+"|");
        }

        wxString Exe=CodMacrou;
        wxStringTokenizer tok(Exe, "\n");
        while(tok.HasMoreTokens())
        {
            wxString toexe=tok.GetNextToken();
            ///todo sa vad daca e variabila inauntru, de care si cu ce trebuie inlocuita
            vector<posibilitate> posibilitati;
            posibilitati.push_back(posibilitate(toexe,0));
            bool done;
            do
            {
                done=true;
                for(int a=0;a<posibilitati.size();a++)
                {
                    int p=-1,care=-1;
                    posibilitate x=posibilitati[a];
                    wxString acum=x.str.substr(x.poz);
                    for(int b=0;b<NumeVariabile.size();b++)
                    if(acum.find(NumeVariabile[b])!=-1)
                    {
                        if(p==-1 || acum.find(NumeVariabile[b])<p)
                        {
                            p=acum.find(NumeVariabile[b]);
                            care=b;
                        }
                    }
                    if(p!=-1)
                    {
                        wxString numeVar=NumeVariabile[care];
                        wxString str=x.str;
                        int poz=x.poz;
                        vector<wxString> valori = Variabile[numeVar];
                        wxString inceput=str.substr(0,poz+p);
                        wxString sfarsit=str.substr(poz+p+numeVar.size());
                        for(int b=0;b<valori.size();b++)
                        {
                            wxString tot=inceput+valori[b]+sfarsit;
                            int poz=tot.size()-sfarsit.size();
                            posibilitati.push_back(posibilitate(tot,poz));
                        }
                        done=false;
                        posibilitati.erase(posibilitati.begin()+a);
                        a--;
                    }
                }
            }while(done==false);
            ///Log("Posibilitati:");
            for(int a=0;a<posibilitati.size();a++)
                runLine(posibilitati[a].str,slip,UID);
        }
    }
    Sleep(slip);
}



#include <wx/tokenzr.h>
#include "Editor.h"
void DoTheTruffleShuffle(wxString ID,int Repeat,wxString UID)
{
    ///this->SetCursor(wxCursor(wxCURSOR_WAIT));
    wxArrayString Exe;
    wxString CodMacrou="";
    wxString temp="select CodMacrou from macrou where UserID="+UID+" and ID="+ID;
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
                CodMacrou=utf8_decode(res[0][0].c_str());
        }
    }
    wxStringTokenizer tok(CodMacrou, "\n");
    int a=0;
    while(tok.HasMoreTokens())
    {
        wxString da=tok.GetNextToken();
        if(da.IsEmpty())
            da="|||Asteapta(1)";
        int poz=da.find("|||");
        wxString q1=da.substr(0,poz);
        wxString q2=da.substr(poz+3);
        //q2.Replace("|||","");
        q1.Replace("<nl>","\n");
        q2.Replace("<nl>","\n");
        Exe.Insert(q2,a);
        a++;
    }

    int slip=30;
    if(ReadDatas(2)!="")
        slip=atoi(ReadDatas(2).data().AsChar());

    for(int c=0;c<Repeat;c++)
        for(int a=0;a<Exe.size();a++)
            runLine(Exe[a],slip,UID);
    ///this->SetCursor(wxCursor(wxCURSOR_WAIT));
    ///this->SetCursor(wxCursor(*wxSTANDARD_CURSOR));
}

