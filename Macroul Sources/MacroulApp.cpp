/***************************************************************
 * Name:      MacroulApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2016-10-14
 * Copyright:  ()
 * License:
 **************************************************************/

#include "MacroulApp.h"

//(*AppHeaders
#include "MacroulMain.h"
#include <wx/image.h>
//*)
#include <wx/textfile.h>
#include <wx/filename.h>
#include "Misc.h"

IMPLEMENT_APP(MacroulApp);

bool MacroulApp::OnInit()
{

    if(wxApp::argc!=1)
    {
        wxTextFile f;
        if (f.Open(wxApp::argv[1]) == false)
            exit(1);
        for(int a=0;a<f.GetLineCount();a++)
        {
            wxString da=f.GetLine(a);
            if(da.IsEmpty())
                da="|||Asteapta(1)";
            int poz=da.find("|||");
            wxString q1=da.substr(0,poz);
            wxString q2=da.substr(poz+3);
            q1.Replace("<nl>","\n");
            q2.Replace("<nl>","\n");
            runLine(q2,123,"-1");///todo maybe
        }
        f.Close();
        exit(0);
    }

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	MacroulFrame* Frame = new MacroulFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    	Frame->ARGV0=wxApp::argv[0];
    }
    //*)

    return wxsOK;

}
