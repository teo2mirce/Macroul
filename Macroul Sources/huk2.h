#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

wxString whatToShow2;

class MyHook2{
public:
	//single ton
	static MyHook2& Instance(){
	    //whatToShow2="";
		static MyHook2 MyHook2;
		return MyHook2;
	}
	HHOOK hook1; // handle to the hook
	HHOOK hook2; // handle to the hook
	void InstallHook(); // function to install our hook
	void UninstallHook(); // function to uninstall our hook

	MSG msg; // struct with information about all messages in our queue
	int Messsages(); // function to "deal" with our messages
};
LRESULT WINAPI MyMouseCallback2(int nCode, WPARAM wParam, LPARAM lParam); //callback declaration
LRESULT WINAPI MyKeyCallback2(int nCode, WPARAM wParam, LPARAM lParam); //callback declaration
int MyHook2::Messsages(){


	//while (msg.message != WM_QUIT){ //while we do not close our application
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Sleep(3);
	//}
}
void MyHook2::InstallHook(){
	/*
	SetWindowHookEx(
	WM_MOUSE_LL = mouse low level hook type,
	MyMouseCallback2 = our callback function that will deal with system messages about mouse
	NULL, 0);

	c++ note: we can check the return SetWindowsHookEx like this because:
	If it return NULL, a NULL value is 0 and 0 is false.
	*/
	if (!(hook1 = SetWindowsHookEx(WH_MOUSE_LL, MyMouseCallback2, NULL, 0)))
		printf("Error: %x \n", GetLastError());
	if (!(hook2 = SetWindowsHookEx(WH_KEYBOARD_LL, MyKeyCallback2, NULL, 0)))
		printf("Error: %x \n", GetLastError());
}
void MyHook2::UninstallHook(){
	/*
	uninstall our hook using the hook handle
	*/
	UnhookWindowsHookEx(hook1);
	UnhookWindowsHookEx(hook2);
}
int DD2 = GetDoubleClickTime();

unsigned long L2,M2,R2;
unsigned long LU2,MU2,RU2;
unsigned long LX2,LY2,MX2,MY2,RX2,RY2;
LRESULT WINAPI MyMouseCallback2(int nCode, WPARAM wParam, LPARAM lParam){
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

			if(L2>LU2 && pMouseStruct->pt.x!=LX2 && pMouseStruct->pt.y!=LY2 && ichar.IsEmpty()==false)
                whatToShow2=ichar+"Drag";
			if(M2>MU2 && pMouseStruct->pt.x!=MX2 && pMouseStruct->pt.y!=MY2)
                whatToShow2=ichar+"Drag Middle";
			if(R2>RU2 && pMouseStruct->pt.x!=RX2 && pMouseStruct->pt.y!=RY2)
                whatToShow2=ichar+"Drag Right";

		}
		switch (wParam){
        case WM_LBUTTONDBLCLK:
            wxMessageBox("double click");break;
		//case WM_LBUTTONUP:printf("LEFT CLICK UP\n");break;
		case WM_MBUTTONDOWN:
		    if(clock()-M2<DD2 && pMouseStruct->pt.x==MX2 && pMouseStruct->pt.y==MY2)
                whatToShow2=ichar+"Double Click Middle";
            else
                whatToShow2=ichar+"Click Middle";
		    M2=clock();MX2=pMouseStruct->pt.x;MY2=pMouseStruct->pt.y;break;
		case WM_LBUTTONDOWN:
		    if(clock()-L2<DD2 && pMouseStruct->pt.x==LX2 && pMouseStruct->pt.y==LY2)
                whatToShow2=ichar+"Double Click";
            else
                if(ichar.IsEmpty()==false)
                    whatToShow2=ichar+"Click";
                L2=clock();LX2=pMouseStruct->pt.x;LY2=pMouseStruct->pt.y;break;
		case WM_RBUTTONDOWN:
		    if(clock()-R2<DD2 && pMouseStruct->pt.x==RX2 && pMouseStruct->pt.y==RY2)
                whatToShow2=ichar+"Double Click Right";
            else
                if(ichar.IsEmpty()==false)
                    whatToShow2=ichar+"Click Right";
            R2=clock();RX2=pMouseStruct->pt.x;RY2=pMouseStruct->pt.y;break;

        case WM_MBUTTONUP:MU2=clock();break;
        case WM_LBUTTONUP:LU2=clock();break;
        case WM_RBUTTONUP:RU2=clock();break;

		case WM_MOUSEWHEEL:
            ;
		    if ((short)HIWORD(pMouseStruct->mouseData) > 0)
                whatToShow2=ichar+"Mouse Wheel Up";
            if ((short)HIWORD(pMouseStruct->mouseData) < 0)
                whatToShow2=ichar+"Mouse Wheel Down";
		    break;
		}
	}
	sf:;
	return CallNextHookEx(MyHook2::Instance().hook1, nCode, wParam, lParam);
}
LRESULT WINAPI MyKeyCallback2(int nCode, WPARAM wParam, LPARAM lParam){
	KBDLLHOOKSTRUCT * pMouseStruct = (KBDLLHOOKSTRUCT *)lParam; // WH_MOUSE_LL struct
	if (nCode == 0)	{ // we have information in wParam/lParam ? If yes, let's check it:

        if(pMouseStruct->vkCode==VK_RSHIFT || pMouseStruct->vkCode==VK_LSHIFT ||
        pMouseStruct->vkCode==VK_LCONTROL || pMouseStruct->vkCode==VK_RCONTROL ||
        pMouseStruct->vkCode==VK_LMENU || pMouseStruct->vkCode==VK_RMENU ||
        pMouseStruct->vkCode==VK_LWIN || pMouseStruct->vkCode==VK_RWIN)
            {
                return CallNextHookEx(MyHook2::Instance().hook2, nCode, wParam, lParam);
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



        //if(pMouseStruct->vkCode==VK_RETURN && pMouseStruct->flags){whatToShow2=ichar + "Enter";;;goto iesi;}
        //if(pMouseStruct->vkCode==VK_RETURN  ){whatToShow2=ichar + "Return";;;goto iesi;}
        //if(pMouseStruct->vkCode==VK_OEM_3  ){whatToShow2=ichar + "Tilda (~)";;;goto iesi;}


            TCHAR lpszName[256];
            DWORD dwMsg = 1;

            dwMsg += pMouseStruct->scanCode << 16;
            dwMsg += pMouseStruct->flags << 24;
            int i = GetKeyNameText(dwMsg , lpszName, 255);

            whatToShow2=ichar +  lpszName;


		}
	}
	iesi:;
	return CallNextHookEx(MyHook2::Instance().hook2, nCode, wParam, lParam);
}
