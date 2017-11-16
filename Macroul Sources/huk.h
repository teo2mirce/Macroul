#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

wxString whatToShow;

class MyHook{
public:
	//single ton
	static MyHook& Instance(){
	    //whatToShow="";
		static MyHook myHook;
		return myHook;
	}
	HHOOK hook1; // handle to the hook
	HHOOK hook2; // handle to the hook
	void InstallHook(); // function to install our hook
	void UninstallHook(); // function to uninstall our hook

	MSG msg; // struct with information about all messages in our queue
	int Messsages(); // function to "deal" with our messages
};
LRESULT WINAPI MyMouseCallback(int nCode, WPARAM wParam, LPARAM lParam); //callback declaration
LRESULT WINAPI MyKeyCallback(int nCode, WPARAM wParam, LPARAM lParam); //callback declaration
int MyHook::Messsages(){


	//while (msg.message != WM_QUIT){ //while we do not close our application
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Sleep(3);
	//}
}
void MyHook::InstallHook(){
	/*
	SetWindowHookEx(
	WM_MOUSE_LL = mouse low level hook type,
	MyMouseCallback = our callback function that will deal with system messages about mouse
	NULL, 0);

	c++ note: we can check the return SetWindowsHookEx like this because:
	If it return NULL, a NULL value is 0 and 0 is false.
	*/
	if (!(hook1 = SetWindowsHookEx(WH_MOUSE_LL, MyMouseCallback, NULL, 0)))
		printf("Error: %x \n", GetLastError());
	if (!(hook2 = SetWindowsHookEx(WH_KEYBOARD_LL, MyKeyCallback, NULL, 0)))
		printf("Error: %x \n", GetLastError());
}
void MyHook::UninstallHook(){
	/*
	uninstall our hook using the hook handle
	*/
	UnhookWindowsHookEx(hook1);
	UnhookWindowsHookEx(hook2);
}
int DD = GetDoubleClickTime();

unsigned long L,M,R;
unsigned long LU,MU,RU;
unsigned long LX,LY,MX,MY,RX,RY;
LRESULT WINAPI MyMouseCallback(int nCode, WPARAM wParam, LPARAM lParam){
	MSLLHOOKSTRUCT * pMouseStruct = (MSLLHOOKSTRUCT *)lParam; // WH_MOUSE_LL struct
	if (nCode == 0)	{ // we have information in wParam/lParam ? If yes, let's check it:


        wxString ichar="";
        if(GetAsyncKeyState(VK_CONTROL))
            ichar<<"Ctrl + ";
        if(GetAsyncKeyState(VK_MENU))
            ichar<<"Alt + ";
        if(GetAsyncKeyState(VK_SHIFT))
            ichar<<"Shift + ";
        if(GetAsyncKeyState(VK_LWIN) || GetAsyncKeyState(VK_RWIN))
            ichar<<"Win + ";


		if (pMouseStruct != NULL){ // Mouse struct contain information?
			printf("Mouse Coordinates: x = %i | y = %i \n", pMouseStruct->pt.x, pMouseStruct->pt.y);

			if(L>LU && pMouseStruct->pt.x!=LX && pMouseStruct->pt.y!=LY && ichar.IsEmpty()==false)
                whatToShow=ichar+"Drag";
			if(M>MU && pMouseStruct->pt.x!=MX && pMouseStruct->pt.y!=MY)
                whatToShow=ichar+"Drag Middle";
			if(R>RU && pMouseStruct->pt.x!=RX && pMouseStruct->pt.y!=RY)
                whatToShow=ichar+"Drag Right";

		}
		switch (wParam){
        case WM_LBUTTONDBLCLK:
            wxMessageBox("double click");break;
		//case WM_LBUTTONUP:printf("LEFT CLICK UP\n");break;
		case WM_MBUTTONDOWN:
		    if(clock()-M<DD && pMouseStruct->pt.x==MX && pMouseStruct->pt.y==MY)
                whatToShow=ichar+"Double Click Middle";
            else
                whatToShow=ichar+"Click Middle";
		    M=clock();MX=pMouseStruct->pt.x;MY=pMouseStruct->pt.y;break;
		case WM_LBUTTONDOWN:
		    if(clock()-L<DD && pMouseStruct->pt.x==LX && pMouseStruct->pt.y==LY)
                whatToShow=ichar+"Double Click";
            else
                if(ichar.IsEmpty()==false)
                    whatToShow=ichar+"Click";
                L=clock();LX=pMouseStruct->pt.x;LY=pMouseStruct->pt.y;break;
		case WM_RBUTTONDOWN:
		    if(clock()-R<DD && pMouseStruct->pt.x==RX && pMouseStruct->pt.y==RY)
                whatToShow=ichar+"Double Click Right";
            else
                if(ichar.IsEmpty()==false)
                    whatToShow=ichar+"Click Right";
            R=clock();RX=pMouseStruct->pt.x;RY=pMouseStruct->pt.y;break;

        case WM_MBUTTONUP:MU=clock();break;
        case WM_LBUTTONUP:LU=clock();break;
        case WM_RBUTTONUP:RU=clock();break;

		case WM_MOUSEWHEEL:
            ;
		    if ((short)HIWORD(pMouseStruct->mouseData) > 0)
                whatToShow=ichar+"Mouse Wheel Up";
            if ((short)HIWORD(pMouseStruct->mouseData) < 0)
                whatToShow=ichar+"Mouse Wheel Down";
		    break;
		}
	}
	sf:;
	return CallNextHookEx(MyHook::Instance().hook1, nCode, wParam, lParam);
}
 int FocusedControlInActiveWindow()
{

    GUITHREADINFO guiThreadInfoObject;
    guiThreadInfoObject.cbSize=sizeof(GUITHREADINFO);
    DWORD tid = GetWindowThreadProcessId(GetForegroundWindow(),0);
    if(GetGUIThreadInfo(tid,&guiThreadInfoObject))
        if(guiThreadInfoObject.flags && GUI_CARETBLINKING)
            return 1;
        return 0;
}

LRESULT WINAPI MyKeyCallback(int nCode, WPARAM wParam, LPARAM lParam){
	KBDLLHOOKSTRUCT * pMouseStruct = (KBDLLHOOKSTRUCT *)lParam; // WH_MOUSE_LL struct
	if (nCode == 0)	{ // we have information in wParam/lParam ? If yes, let's check it:

        if(pMouseStruct->vkCode==VK_RSHIFT || pMouseStruct->vkCode==VK_LSHIFT ||
        pMouseStruct->vkCode==VK_LCONTROL || pMouseStruct->vkCode==VK_RCONTROL ||
        pMouseStruct->vkCode==VK_LMENU || pMouseStruct->vkCode==VK_RMENU ||
        pMouseStruct->vkCode==VK_LWIN || pMouseStruct->vkCode==VK_RWIN)
            {
                return CallNextHookEx(MyHook::Instance().hook2, nCode, wParam, lParam);
            }
		if (wParam == WM_KEYDOWN){

        wxString ichar="";
        if(GetAsyncKeyState(VK_CONTROL))
            ichar<<"Ctrl + ";
        if(GetAsyncKeyState(VK_CONTROL) || GetAsyncKeyState(VK_SHIFT) || GetAsyncKeyState(VK_LWIN) || GetAsyncKeyState(VK_RWIN))
            if(GetAsyncKeyState(VK_MENU))
                ichar<<"Alt + ";
        if(GetAsyncKeyState(VK_SHIFT))
            ichar<<"Shift + ";
        if(GetAsyncKeyState(VK_LWIN) || GetAsyncKeyState(VK_RWIN))
            ichar<<"Win + ";



        //if(pMouseStruct->vkCode==VK_RETURN && pMouseStruct->flags){whatToShow=ichar + "Enter";;;goto iesi;}
        //if(pMouseStruct->vkCode==VK_RETURN  ){whatToShow=ichar + "Return";;;goto iesi;}
        //if(pMouseStruct->vkCode==VK_OEM_3  ){whatToShow=ichar + "Tilda (~)";;;goto iesi;}


            TCHAR lpszName[256];
            DWORD dwMsg = 1;

            dwMsg += pMouseStruct->scanCode << 16;
            dwMsg += pMouseStruct->flags << 24;
            int i = GetKeyNameText(dwMsg , lpszName, 255);

            whatToShow=ichar +  lpszName;


		}
	}
	iesi:;
	return CallNextHookEx(MyHook::Instance().hook2, nCode, wParam, lParam);
}
