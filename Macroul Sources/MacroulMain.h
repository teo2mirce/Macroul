/***************************************************************
 * Name:      MacroulMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2016-10-14
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef MACROULMAIN_H
#define MACROULMAIN_H

//(*Headers(MacroulFrame)
#include <wx/sizer.h>
#include <wx/bmpbuttn.h>
#include <wx/frame.h>
//*)

#include <Shlobj.h>


class MacroulFrame: public wxFrame
{
    public:
        wxString ARGV0;

	    wxCommandEvent wxCE;
        static wxString UID;
        static wxArrayString voceData;
        static wxArrayString voceID;
        static wxArrayInt    voceRepeat;

        static wxArrayString tasteData;
        static wxArrayString tasteID;
        static wxArrayInt    tasteRepeat;

        static wxArrayString programData;
        static wxArrayString programID;
        static wxArrayInt    programRepeat;

        static wxArrayString cardData;
        static wxArrayString cardID;
        static wxArrayInt    cardRepeat;


        static void initTriggers();
        static unsigned int __stdcall  T1(void *x);
        static unsigned int __stdcall  T2(void *x);
        static unsigned int __stdcall  T3(void *x);
        static unsigned int __stdcall  T4(void *x);
        static unsigned int __stdcall  T5(void *x);
        static unsigned int __stdcall  T6(void *x);

        void StartThreads();
//        void PauseThreads();
  //      void ResumeThreads();
        static bool pause;
        int done;


        MacroulFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~MacroulFrame();

    private:

        //(*Handlers(MacroulFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void Onm_MyMacrosClick(wxCommandEvent& event);
        void Onm_SearchClick(wxCommandEvent& event);
        void Onm_EditMacroClick(wxCommandEvent& event);
        void Onm_ExitClick(wxCommandEvent& event);
        void Onm_ButtonSettingsClick(wxCommandEvent& event);
        void Onm_ButtonSetariClick(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void Onm_ButtonCalculatoareGrupuriClick(wxCommandEvent& event);
        void Onm_ButtonNLPClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(MacroulFrame)
        static const long ID_BITMAPBUTTON3;
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON6;
        static const long ID_BITMAPBUTTON7;
        static const long ID_BITMAPBUTTON4;
        static const long ID_BITMAPBUTTON5;
        //*)

        //(*Declarations(MacroulFrame)
        wxBitmapButton* m_Exit;
        wxBitmapButton* m_ButtonCalculatoareGrupuri;
        wxBitmapButton* m_ButtonSettings;
        wxBitmapButton* m_Search;
        wxBitmapButton* m_ButtonNLP;
        wxBitmapButton* m_MyMacros;
        wxBitmapButton* m_EditMacro;
        //*)

        DECLARE_EVENT_TABLE()
};


#endif // MACROULMAIN_H
