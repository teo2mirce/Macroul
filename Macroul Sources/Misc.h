
#ifndef MISC_H
#define MISC_H

#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Database.h"
#include <windows.h>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>
#include <string.h>
#include <wx/string.h>
using namespace std;
void Log(wxString v);
void Log(wxString v,long x);

wxString ITOWS(int x);
struct posibilitate
{
    wxString str;
    int poz;
    posibilitate(wxString x,int y)
    {
        str=x;
        poz=y;
    }
};

DWORD FindProcessId(const std::wstring& processName);

vector<wxString> split(wxString tok,wxString sep);

wxString ReadDatas(int x);
void SaveDatas(wxString user,int x);

int PrinScri(const char *pszFile);
//#define click(a,b) SetCursorPos(a,b);mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0,0,0);Sleep(2);mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
//#define clickd(a,b) SetCursorPos(a,b);mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0,0,0);Sleep(2);mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
#define ra(a,b) rand()%(b-a)+a
void move(int x,int y);
void openWebsite(wchar_t *url);
void Execute(wxString a,wxString b,wxString c,wxString d);
unsigned long long CardReader();
wxArrayString PrintAllPorts();
void runLine(wxString input,int slip,wxString UID);
void DoTheTruffleShuffle(wxString ID,int Repeat,wxString UID);

#endif
