/***************************************************************
 * Name:      MacroulMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2016-10-14
 * Copyright:  ()
 * License:
 **************************************************************/

#include "MacroulMain.h"
#include <wx/msgdlg.h>
#include "Database.h"
#include "Misc.h"
#include "Editor.h"
#include "DialogLogin.h"

//(*InternalHeaders(MacroulFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)


wxString CWD;

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(MacroulFrame)
const long MacroulFrame::ID_BITMAPBUTTON3 = wxNewId();
const long MacroulFrame::ID_BITMAPBUTTON1 = wxNewId();
const long MacroulFrame::ID_BITMAPBUTTON2 = wxNewId();
const long MacroulFrame::ID_BITMAPBUTTON6 = wxNewId();
const long MacroulFrame::ID_BITMAPBUTTON7 = wxNewId();
const long MacroulFrame::ID_BITMAPBUTTON4 = wxNewId();
const long MacroulFrame::ID_BITMAPBUTTON5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MacroulFrame,wxFrame)
    //(*EventTable(MacroulFrame)
    //*)
END_EVENT_TABLE()


wxString MacroulFrame::UID;

wxArrayString MacroulFrame::voceData;
wxArrayString MacroulFrame::voceID;
wxArrayInt    MacroulFrame::voceRepeat;

wxArrayString MacroulFrame::tasteData;
wxArrayString MacroulFrame::tasteID;
wxArrayInt    MacroulFrame::tasteRepeat;

wxArrayString MacroulFrame::programData;
wxArrayString MacroulFrame::programID;
wxArrayInt    MacroulFrame::programRepeat;

wxArrayString MacroulFrame::cardData;
wxArrayString MacroulFrame::cardID;
wxArrayInt    MacroulFrame::cardRepeat;
bool MacroulFrame::pause;

#include <wx/tokenzr.h>




#include <wx/textfile.h>
#include<wx/filename.h>

void SablonSpecial(wxString res,int slip,wxString UID)
{
    map<wxString,vector<wxString> > Variabile;
    wxString input=res;
    int i=0;

    wxString CodMacrou;
    wxString Text;
    wxString Forma;
    wxString temp="select CodMacrou,Text,Forma from sablon where UserID="+UID+" and UPPER(Inceput) = UPPER(LEFT('"+res+"',CHAR_LENGTH(Inceput)))";
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
                    wxMessageBox("Nu am gasit sablon care incepe asa\n("+input+")");
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
            nume=nume.Lower();
            tocomp=tocomp.Lower();

//            wxMessageBox(res+ " : |"+nume+"| vs |"+tocomp+"|");
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
//                wxStringTokenizer tok(tot,sep);
//                while(tok.HasMoreTokens())
//                    Var.push_back(tok.GetNextToken());

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
//        wxStringTokenizer tok(tot,SEPARATOR[nm1]);
//        while(tok.HasMoreTokens())
//            Var.push_back(tok.GetNextToken());
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
///voce 1
unsigned int __stdcall  MacroulFrame::T1(void* x)
{
    MacroulFrame* p_foo = static_cast<MacroulFrame*>(x);
    while(1)
    {
        Sleep(50);
        while((p_foo->pause || p_foo->voceData.size()==0) && p_foo->done==0)
            Sleep(333);
        if(p_foo->done)
        {
            p_foo->done++;
            return 0;
        }

        remove("workfile");
        Execute("spici\\spici.exe","1","1","ro-RO");
        if(p_foo->pause)continue;
        wxTextFile f;
        if(wxFileName::FileExists("workfile")==false)continue;
        f.Open("workfile");
        wxString temp=f.GetLine(0);
        Log("scriu in log");
        //wxMessageBox(temp);
        Log(temp);
        Log("Am scris în log");
        f.Close();
        for(int a=0;a<p_foo->voceData.size();a++)
        {
            if(temp.Find(p_foo->voceData[a])!=-1)
                if(p_foo->pause==false)
                {
                    p_foo->pause=true;
                    p_foo->SetCursor(wxCursor(wxCURSOR_WAIT));
                    DoTheTruffleShuffle(p_foo->voceID[a],p_foo->voceRepeat[a],UID);
                    p_foo->SetCursor(wxCursor(*wxSTANDARD_CURSOR));
                    p_foo->pause=false;
                    a=p_foo->voceData.size();
                }
        }
        if(temp.Find(L"șablon")!=-1)
        {
            wxString todo;
            todo<<temp.substr(temp.Find(L"șablon")+7);
//            wxMessageBox(todo);
            SablonSpecial(todo,30,UID);
        }
        Sleep(1);
    }
}
///taste  2
#include "huk2.h"
unsigned int __stdcall  MacroulFrame::T2(void* x)
{
    MyHook2::Instance().InstallHook();
    MacroulFrame* p_foo = static_cast<MacroulFrame*>(x);
    while(1)
    {
        ///Sleep(50);
        ///Log("While1");
        if(p_foo->pause || p_foo->tasteData.size()==0)
        {
            MyHook2::Instance().UninstallHook();
            while((p_foo->pause || p_foo->tasteData.size()==0) && p_foo->done==0)
                Sleep(333);

            if(p_foo->done)
            {
                p_foo->done++;
                return 0;
            }

            MyHook2::Instance().InstallHook();
        }
        if(p_foo->done)
        {
            p_foo->done++;
            return 0;
        }
        ///Log("While2");
        MyHook2::Instance().Messsages();
        ///Log("While3");
        for(int a=0;a<p_foo->tasteData.size();a++)
            if(p_foo->tasteData[a].compare(whatToShow2)==0)
            {
                ///Log("While4");
                whatToShow2="";
                if(p_foo->pause==false)
                {
                    p_foo->pause=true;
                    MyHook2::Instance().UninstallHook();
                    Sleep(300);
                    p_foo->SetCursor(wxCursor(wxCURSOR_WAIT));
                    DoTheTruffleShuffle(p_foo->tasteID[a],p_foo->tasteRepeat[a],UID);
                    p_foo->SetCursor(wxCursor(*wxSTANDARD_CURSOR));
                    MyHook2::Instance().InstallHook();
                    p_foo->pause=false;
                    a=p_foo->tasteData.size();
                }
                ///Log("While3");
            }
       // Sleep(25);
    }
}
///program  3
unsigned int __stdcall  MacroulFrame::T3(void* x)
{
    MacroulFrame* p_foo = static_cast<MacroulFrame*>(x);
    while(1)
    {
        Sleep(50);
        while((p_foo->pause || p_foo->programData.size()==0) && p_foo->done==0)
        {
            Sleep(333);
        }

        if(p_foo->done)
        {
            p_foo->done++;
            return 0;
        }
        wxString ichar="";
        ichar<<wxDateTime::Now().GetTicks();
        for(int a=0;a<p_foo->programData.size();a++)
            if(p_foo->programData[a].compare(ichar)==0)
                if(p_foo->pause==false)
                {
                    p_foo->pause=true;
                    p_foo->SetCursor(wxCursor(wxCURSOR_WAIT));
                    DoTheTruffleShuffle(p_foo->programID[a],p_foo->programRepeat[a],UID);
                    p_foo->SetCursor(wxCursor(*wxSTANDARD_CURSOR));
                    p_foo->pause=false;
                    a=p_foo->programData.size();
                    Sleep(1000);
                }
    }
}
///card 4
unsigned int __stdcall  MacroulFrame::T4(void* x)
{

    MacroulFrame* p_foo = static_cast<MacroulFrame*>(x);
    while(1)
    {
        Sleep(50);
        while((p_foo->pause || p_foo->cardData.size()==0) && p_foo->done==0)
            Sleep(333);


        if(p_foo->done)
        {
            p_foo->done++;
            return 0;
        }
        unsigned long long x = CardReader();
        unsigned long long y = -1;
        if(x!=y)
        {
            wxString ichar="";
            ichar<<x;
            for(int a=0;a<p_foo->cardData.size();a++)
                if(p_foo->cardData[a].compare(ichar)==0)
                    if(p_foo->pause==false)
                    {
                        p_foo->pause=true;
                        p_foo->SetCursor(wxCursor(wxCURSOR_WAIT));
                        DoTheTruffleShuffle(p_foo->cardID[a],p_foo->cardRepeat[a],UID);
                        p_foo->SetCursor(wxCursor(*wxSTANDARD_CURSOR));
                        p_foo->pause=false;
                        a=p_foo->cardData.size();
                    }
        }
        Sleep(123);
    }
}

#include <windows.h>
#include <wininet.h>
#pragma comment(lib, "wininet")



void GetDesktopResolution(int& horizontal, int& vertical)
{
   RECT desktop;
   // Get a handle to the desktop window
   const HWND hDesktop = GetDesktopWindow();
   // Get the size of screen to the variable desktop
   GetWindowRect(hDesktop, &desktop);
   // The top left corner will have coordinates (0,0)
   // and the bottom right corner will have coordinates
   // (horizontal, vertical)
   horizontal = desktop.right;
   vertical = desktop.bottom;
}

#include <wx/dcscreen.h>
#include <wx/dcmemory.h>
#include <wx/image.h>
#include <wx/quantize.h>
#include <wx/bitmap.h>
#include <stdlib.h>
#include <stdio.h>
///send print
unsigned int __stdcall  MacroulFrame::T6(void* x)
{

    MacroulFrame* p_foo = static_cast<MacroulFrame*>(x);
    int i=0;
    int Sl=wxAtoi(ReadDatas(10));
    wxString PCN=ReadDatas(1);
    wxString Print=ReadDatas(4);
    if(Sl<0 || Sl>4000)Sl=4000;
    while(1)
    {
        Sleep(50);
        if(p_foo->done)
        {
            p_foo->done++;
            break;
        }

        if(i%10==0)
        {
            Sl=wxAtoi(ReadDatas(10));
            PCN=ReadDatas(1);
            Print=ReadDatas(4);
            if(Sl<0 || Sl>4000)Sl=4000;
        }
        i++;

        Sleep(Sl);
        if(PCN!="")
        if(Print=="1")///2 sec?
        {
            int timmy=clock();
            //wxMessageBox("Trimit");
            ///PrinScri(CWD+"\\pr.bmp");
            ///Execute(CWD+"\\BMP2JPG.exe","1","1","pr.bmp out.jpg overwrite");



                ///https://forums.wxwidgets.org/viewtopic.php?p=32313

            {


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


                wxBitmap screenshot;
                screenshot.SetHBITMAP(aBmp);
                wxImage toResize=screenshot.ConvertToImage();
                int Qual=atoi(ReadDatas(9));



//                int maxcol=16;
//                int col=toResize.CountColours();
//                wxPalette * pal=NULL;
//                if(col>maxcol)
//                {
//                    wxImage red;
//                    if(wxQuantize::Quantize(toResize,red,&pal,maxcol))
//                    {
//                        ///wxMessageBox("?");
//                        col=red.CountColours();
//                        toResize=red;
//                    }
//                }


                //toResize=toResize.ConvertToGreyscale();
                toResize.SetOption("quality",Qual);
                //toResize.ClearAlpha();
                ///toResize.Scale(w*(Qual/100.0),h*(Qual/100.0));
                toResize.SaveFile(CWD+"\\out.jpg",wxBITMAP_TYPE_JPEG);


                DeleteObject(SelectObject(hdc2,OldObj));
                DeleteDC(hdc2);
                ReleaseDC(hStatic, hdc1);

            }


            ///REPLACE INTO my_table (pk_id, col1) VALUES (5, '123');
            wxString temp="REPLACE INTO `teamviewer`(`UserID_Nume`, `Poza`) VALUES (";
            {

                wxString temp2;
                temp2 <<"0x";
                FILE *f;
                f=fopen(CWD+"\\out.jpg","rb");
                while(!feof(f))
                {
                    uint8_t n;
                    char tmp[3];
                    fread (&n,1,1,f);
                    sprintf(tmp, "%02X", n);
                    temp2 << tmp;
                }
                temp2 << ")";
                fclose(f);

                Connection conn(false);
                if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
                {
                    Query query = conn.query();
                    query<<temp<<" '"<<UID<<"_"<<escape<<PCN.data().AsChar()<<"',"<<temp2;
                    wxString ss=query.str();
                    ///Log(ss.data().AsChar());
                    query.execute();
                }
            }
        }
    }

}
///de pe webs
unsigned int __stdcall  MacroulFrame::T5(void* x)
{
    MacroulFrame* p_foo = static_cast<MacroulFrame*>(x);
    int i=0;
    while(1)
    {
        Sleep(50);
        i++;
        //wxMessageBox("da");
        while((p_foo->pause) && p_foo->done==0)
        {
            Sleep(333);
        }
        if(p_foo->done)
        {
            p_foo->done++;
            return 0;
        }
        Sleep(100);
        if(ReadDatas(1)!="")
        {
            ///team viewer click
            if(ReadDatas(4)=="1")
            {
                wxString temp="SELECT ID,Type,Additional2,Additional3 FROM `activator` WHERE Type>6 and Additional1='"+UID+"' and Data =";
                Connection conn(false);
                if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
                {
                    Query query = conn.query();
                    query<<temp;
                    query<<" '"<<escape<<utf8_encode(ReadDatas(1).wc_str())<<"'";
                    //Log(_T("Query: ")+ query.str());
                    StoreQueryResult res = query.store();
                    if(res && res.num_rows())
                    {
                        //wxMessageBox("Am de facut ceva");
                        for (size_t i = 0; i < res.num_rows(); ++i)
                        ///if(p_foo->pause==false)
                        {
                            ///p_foo->pause=true;
                            wxString tip="";
                            tip<<res[i][1].c_str();
                            char ascii=atoi(res[i][2].c_str());



                            int horizontal = 0;
                            int vertical = 0;
                            GetDesktopResolution(horizontal, vertical);


                            ///left
                            if(tip=="8")
                            {
                                SetCursorPos(1.0*horizontal*atof(res[i][2].c_str()),1.0*vertical*atof(res[i][3].c_str()));
                                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0,0,0),Sleep(5),mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
                            }


                            ///right
                            if(tip=="7")
                            {
                                SetCursorPos(1.0*horizontal*atof(res[i][2].c_str()),1.0*vertical*atof(res[i][3].c_str()));
                                mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0,0,0),Sleep(5),mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
                            }


                            ///dublu click
                            if(tip=="9")
                            {
                                SetCursorPos(1.0*horizontal*atof(res[i][2].c_str()),1.0*vertical*atof(res[i][3].c_str()));
                                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0,0,0),Sleep(5),mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
                                Sleep(20);
                                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0,0,0),Sleep(5),mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
                            }
                            ///key down
                            if(tip=="10")
                            {
                                keybd_event(ascii,0xb8,0,0);
                                Sleep(20);
                            }
                            ///key up
                            if(tip=="11")
                            {
                                keybd_event(ascii,0xb8,KEYEVENTF_KEYUP,0);
                                Sleep(20);
                            }
                            ///string
                            if(tip=="12")
                            {
                                wxString da;
                                da<<"Taste(Text,Deodata,"<<res[i][2].c_str()<<")";
                                runLine(da,30,UID);

                            }
                            ///p_foo->pause=false;
                            Query query2 = conn.query();
                            query2<<"delete from activator where ID = "<<res[i][0].c_str();
                            query2.execute();
                        }
                    }
                }
                conn.disconnect();
            }
            ///comenzile de pe netAna are mere

            {
                wxString temp="SELECT ID,MacrouID FROM `activator` WHERE Type=6 and Data =";
                Connection conn(false);
                if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
                {
                    Query query = conn.query();
                    query<<temp;
                    query<<" '"<<escape<<utf8_encode(ReadDatas(1).wc_str())<<"'";
                    //Log(_T("Query: ")+ query.str());
                    StoreQueryResult res = query.store();
                    if(res && res.num_rows())
                    {
                        p_foo->pause=true;
///                        wxMessageBox("Am de facut ceva");
                        for (size_t i = 0; i < res.num_rows(); ++i)
                        {
                            query.reset();
                            query<<"delete from activator where ID = "<<res[i][0].c_str();
                            query.exec();
                            wxString Lo;
                            Lo<<query.str()<<" "<<query.errnum()<<" "<<query.error()<<" "<<res.num_rows();
                            Log(Lo.data().AsChar());
                        }
                        for (size_t i = 0; i < res.num_rows(); ++i)
                        {
                            p_foo->SetCursor(wxCursor(wxCURSOR_WAIT));
                            DoTheTruffleShuffle(res[i][1].c_str(),1,UID);
                            p_foo->SetCursor(wxCursor(*wxSTANDARD_CURSOR));
                        }
                        p_foo->pause=false;
                    }
                }
            }

            ///comenzi din textbox
            {
                wxString temp="SELECT ID,Additional1 FROM `activator` WHERE MacrouID=-2 and Data =";
                Connection conn(false);
                if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
                {
                    Query query = conn.query();
                    query<<temp;
                    query<<" '"<<escape<<utf8_encode(ReadDatas(1).wc_str())<<"'";
                    //Log(_T("Query: ")+ query.str());
                    StoreQueryResult res = query.store();
                    if(res && res.num_rows())
                    {
                        p_foo->pause=true;
                        p_foo->SetCursor(wxCursor(wxCURSOR_WAIT));
                        for (size_t i = 0; i < res.num_rows(); ++i)
                        {
                            query.reset();
                            query<<"delete from activator where ID = "<<res[i][0].c_str();
                            query.exec();
                            wxString Lo;
                            Lo<<query.str()<<" "<<query.errnum()<<" "<<query.error()<<" "<<res.num_rows();
                            Log(Lo.data().AsChar());
                        }
                        for (size_t i = 0; i < res.num_rows(); ++i)
                        {

                            wxStringTokenizer tok(res[i][1].c_str(), "\n");
                            int a=0;
                            while(tok.HasMoreTokens())
                            {
                                runLine(tok.GetNextToken(),30,UID);
                            }
                        }
                        p_foo->SetCursor(wxCursor(*wxSTANDARD_CURSOR));
                        p_foo->pause=false;
                    }
                }
            }
        }
    }
}
void MacroulFrame::StartThreads()
{
    pause=false;
    _beginthreadex(0, 0, &MacroulFrame::T1, this, 0, 0);
    _beginthreadex(0, 0, &MacroulFrame::T2, this, 0, 0);
    _beginthreadex(0, 0, &MacroulFrame::T3, this, 0, 0);
    _beginthreadex(0, 0, &MacroulFrame::T4, this, 0, 0);
    _beginthreadex(0, 0, &MacroulFrame::T5, this, 0, 0);
    _beginthreadex(0, 0, &MacroulFrame::T6, this, 0, 0);
}
//void MacroulFrame::PauseThreads()
//{
//    pause=true;
//}
//void MacroulFrame::ResumeThreads()
//{
//    pause=false;
//}
void MacroulFrame::initTriggers()
{
    pause=true;
    ///voce  1
    voceData.clear();
    voceID.clear();
    voceRepeat.clear();
    if(ReadDatas(5)=="1")
    {
        wxString temp="select Data,MacrouID,NrTimes from activator where Type=1 and MacrouID in (select ID from macrou where UserID= "+UID+") order by length(Data) desc";
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
            for (size_t i = 0; i < res.num_rows(); ++i)
            {
                wxString ichar="macrou ";
                ichar<<utf8_decode(res[i][0].c_str());
                voceData.Add(ichar);
                voceID.Add(res[i][1].c_str());
                voceRepeat.Add(atoi(res[i][2].c_str()));
            }
        }
    }
    ///taste  2
    tasteData.clear();
    tasteID.clear();
    tasteRepeat.clear();
    if(ReadDatas(6)=="1")
    {
        wxString temp="select Data,MacrouID,NrTimes from activator where Type=2 and MacrouID in (select ID from macrou where UserID= "+UID+")";
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
            for (size_t i = 0; i < res.num_rows(); ++i)
            {
                tasteData.Add(utf8_decode(res[i][0].c_str()));
                tasteID.Add(res[i][1].c_str());
                tasteRepeat.Add(atoi(res[i][2].c_str()));
            }
        }
    }
    ///program  3
    programData.clear();
    programID.clear();
    programRepeat.clear();
    if(ReadDatas(7)=="1")
    {
        wxString temp="select Data,MacrouID,NrTimes from activator where Type=3 and MacrouID in (select ID from macrou where UserID= "+UID+")";
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
            for (size_t i = 0; i < res.num_rows(); ++i)
            {
                programData.Add(utf8_decode(res[i][0].c_str()));
                programID.Add(res[i][1].c_str());
                programRepeat.Add(atoi(res[i][2].c_str()));
            }
        }
    }
    ///card  4
    cardData.clear();
    cardID.clear();
    cardRepeat.clear();
    if(ReadDatas(8)=="1")
    {
        wxString temp="select Data,MacrouID,NrTimes from activator where Type=4 and MacrouID in (select ID from macrou where UserID= "+UID+")";
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
            for (size_t i = 0; i < res.num_rows(); ++i)
            {
                cardData.Add(utf8_decode(res[i][0].c_str()));
                cardID.Add(res[i][1].c_str());
                cardRepeat.Add(atoi(res[i][2].c_str()));
            }
        }
    }
    pause=false;
}




MacroulFrame::MacroulFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MacroulFrame)
    wxFlexGridSizer* FlexGridSizer1;

    Create(parent, id, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("id"));
    SetBackgroundColour(wxColour(2,32,40));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("res/macrou.ico"))));
    	SetIcon(FrameIcon);
    }
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    m_EditMacro = new wxBitmapButton(this, ID_BITMAPBUTTON3, wxBitmap(wxImage(_T("res\\3.bmp"))), wxDefaultPosition, wxSize(200,75), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    FlexGridSizer1->Add(m_EditMacro, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_MyMacros = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("res/1.bmp"))), wxDefaultPosition, wxSize(200,75), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    FlexGridSizer1->Add(m_MyMacros, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_Search = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("res\\2.bmp"))), wxDefaultPosition, wxSize(200,75), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    FlexGridSizer1->Add(m_Search, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_ButtonCalculatoareGrupuri = new wxBitmapButton(this, ID_BITMAPBUTTON6, wxBitmap(wxImage(_T("res\\CGM.bmp"))), wxDefaultPosition, wxSize(200,75), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
    FlexGridSizer1->Add(m_ButtonCalculatoareGrupuri, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_ButtonNLP = new wxBitmapButton(this, ID_BITMAPBUTTON7, wxBitmap(wxImage(_T("res/NLP.bmp"))), wxDefaultPosition, wxSize(200,75), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON7"));
    FlexGridSizer1->Add(m_ButtonNLP, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_ButtonSettings = new wxBitmapButton(this, ID_BITMAPBUTTON4, wxBitmap(wxImage(_T("res\\4.bmp"))), wxDefaultPosition, wxSize(200,75), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
    FlexGridSizer1->Add(m_ButtonSettings, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_Exit = new wxBitmapButton(this, ID_BITMAPBUTTON5, wxBitmap(wxImage(_T("res\\5.bmp"))), wxDefaultPosition, wxSize(200,75), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
    FlexGridSizer1->Add(m_Exit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MacroulFrame::Onm_EditMacroClick);
    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MacroulFrame::Onm_MyMacrosClick);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MacroulFrame::Onm_SearchClick);
    Connect(ID_BITMAPBUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MacroulFrame::Onm_ButtonCalculatoareGrupuriClick);
    Connect(ID_BITMAPBUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MacroulFrame::Onm_ButtonNLPClick);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MacroulFrame::Onm_ButtonSettingsClick);
    Connect(ID_BITMAPBUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MacroulFrame::Onm_ExitClick);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&MacroulFrame::OnClose);
    //*)
    CWD=wxGetCwd();








    wxString ichar="";
    if(DBCheck()==0)
    {
        wxMessageBox("Esti la licenta si s-a oprit serveru cu baze de date... dar tot te las");
        //exit(0);
    }
    else
    {
        if(ReadDatas(0)!="")
        {
            wxString temp="select AskForPass from users where Email='"+ReadDatas(0)+"'";
            Connection conn(false);
            if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
            {
                Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
                if (StoreQueryResult res = query.store())
                if((atoi(res[0][0].c_str()))==1)
                {
                    DialogLogin x(this);
                    wxIcon FrameIcon;
                    FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("res/macrou.ico"))));
                    x.SetIcon(FrameIcon);
                    if(x.ShowModal()==0)
                    {
                        exit(0);
                    }
                }
            }
        }
        else
        {
            DialogLogin x(this);
            wxIcon FrameIcon;
            FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("res/macrou.ico"))));
            x.SetIcon(FrameIcon);
            if(x.ShowModal()==0)
            {
                exit(0);
            }
        }

        {
            wxString temp="select ID from users where Email='"+ReadDatas(0)+"'";
            Connection conn(false);
            if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
            {
                Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
                if (StoreQueryResult res = query.store())
                    UID=res[0][0].c_str();
            }
        }
        if(ReadDatas(1)!="")
        {
            Connection conn(false);
            if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
            {
                Query query = conn.query();
                query<<"select * from calculatoare where UserID="<<UID<<" and Nume='"<<escape<<utf8_encode(ReadDatas(1).wc_str())<<"'";
                Log(_T("Query: ")+ query.str());
                if (StoreQueryResult res = query.store())
                if(res.num_rows()==0)
                {
                    wxMessageBox("Nu mai exista userul: "+ReadDatas(1));
                    SaveDatas("",1);
                    //UID=res[0][0].c_str();
                }
            }
        }


        initTriggers();
        StartThreads();
    }
    this->Layout();
    this->Fit();
    this->SetPosition(wxPoint(GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));


    done=0;




}


MacroulFrame::~MacroulFrame()
{
    //(*Destroy(MacroulFrame)
    //*)
}

void MacroulFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void MacroulFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
#include "DialogMacroMele.h"
void MacroulFrame::Onm_MyMacrosClick(wxCommandEvent& event)
{
//    PauseThreads();

    DialogMacroMele x(this);
    x.UID=UID;
    x.Fill();
    x.ShowModal();


    initTriggers();
    //ResumeThreads();
}
#include "DialogMacroCauta.h"
void MacroulFrame::Onm_SearchClick(wxCommandEvent& event)
{
    DialogMacroCauta x(this);
    x.UID=UID;
    x.Fill();
    x.ShowModal();
}
#include "DialogMacroEditor.h"
void MacroulFrame::Onm_EditMacroClick(wxCommandEvent& event)
{
    DialogMacroEditor y(this);
    y.UID=UID;
    y.Fill();
    y.ShowModal();

//    initTriggers();
}

void MacroulFrame::Onm_ExitClick(wxCommandEvent& event)
{
    Close(0);
}
#include "DialogSettings.h"
//User
//Pass
//pcName
//wait
//com
//member
//ask
void MacroulFrame::Onm_ButtonSettingsClick(wxCommandEvent& event)
{


    DialogSettings x(this);
    x.m_UID->SetValue(UID);
//    x.m_PCName->SetValue(ReadDatas(1));
    x.m_ExeWait->SetValue(ReadDatas(2));
    wxArrayString COM=PrintAllPorts();

//    x.m_COM->SetColumns(COM.size());
    for(int a=0;a<COM.size();a++)
        x.m_COM->Append(COM[a]);
    x.m_COM->SetSelection(COM.Index(ReadDatas(3)));

    //x.m_AskPass->SetValue(ReadData(5).compare("1")==0);
    {
        wxString temp="select AskForPass from users where ID="+UID;
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
                x.m_AskPass->SetValue(atoi(res[0][0].c_str()));
        }
    }

    ///fill nume calculator
    x.m_TrimitePrint->SetValue(atoi(ReadDatas(4)));
    x.m_Voce->SetValue(atoi(ReadDatas(5)));
    x.m_Hotkeys->SetValue(atoi(ReadDatas(6)));
    x.m_Program->SetValue(atoi(ReadDatas(7)));
    x.m_Card->SetValue(atoi(ReadDatas(8)));
    x.m_Calitate->SetValue(atoi(ReadDatas(9)));
    x.m_Viteza->SetValue(atoi(ReadDatas(10)));


    ///fill group data
    {
        wxString temp="select AskForPass from users where ID="+UID;
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
                x.m_AskPass->SetValue(atoi(res[0][0].c_str()));
        }
    }

    if(x.ShowModal()!=666)
    {

        return;
    }

//    SaveDatas(x.m_PCName->GetValue(),1);
    wxString ichar="";
    ichar<<x.m_ExeWait->GetValue();
    SaveDatas(ichar,2);
    SaveDatas(x.m_COM->GetStringSelection(),3);
    ichar="";
    ichar<<(int)x.m_TrimitePrint->GetValue();
    SaveDatas(ichar,4);
    ichar="";
    ichar<<(int)x.m_Voce->GetValue();
    SaveDatas(ichar,5);
    ichar="";
    ichar<<(int)x.m_Hotkeys->GetValue();
    SaveDatas(ichar,6);
    ichar="";
    ichar<<(int)x.m_Program->GetValue();
    SaveDatas(ichar,7);
    ichar="";
    ichar<<(int)x.m_Card->GetValue();
    SaveDatas(ichar,8);
    ichar="";
    ichar<<(int)x.m_Calitate->GetValue();
    SaveDatas(ichar,9);
    ichar="";
    ichar<<(int)x.m_Viteza->GetValue();
    SaveDatas(ichar,10);
    ichar="";
    ichar<<(int)x.m_AskPass->GetValue();
    {
        wxString temp="";
        temp<<"update users set AskForPass="<<(int)(x.m_AskPass->GetValue())<<" where ID="+UID;
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            query.execute();
        }
    }
    initTriggers();
}

void MacroulFrame::Onm_ButtonSetariClick(wxCommandEvent& event)
{

}


void MacroulFrame::OnClose(wxCloseEvent& event)
{
    //ShowWindow(this->GetHWND(),SW_HIDE);
    //done=1;
    //while(done!=5)
    //    Sleep(123);
    Destroy();
}
#include "DialogCalculatoareGrupuriMeniuri.h"
void MacroulFrame::Onm_ButtonCalculatoareGrupuriClick(wxCommandEvent& event)
{
    DialogCalculatoareGrupuriMeniuri x(this);
    x.UID=UID;
    x.ShowModal();
}
#include "DialogLimbajNatural.h"
void MacroulFrame::Onm_ButtonNLPClick(wxCommandEvent& event)
{
    DialogLimbajNatural x(this);
    x.UID=UID;
    x.ShowModal();
}
