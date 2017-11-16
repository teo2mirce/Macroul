#ifndef EDITOR_H
#define EDITOR_H

#include "Misc.h"
#include <wx/msgdlg.h>
//(*Headers(Editor)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/filedlg.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/spinbutt.h>
//*)

// Convert a wide Unicode string to an UTF8 string
std::string utf8_encode(const std::wstring &wstr);
// Convert an UTF8 string to a wide Unicode String
std::wstring utf8_decode(const std::string &str);


class Editor: public wxDialog
{
	public:
	    wxString UID;

	    void OnDragEnd(wxMouseEvent& event);
	    void OnDragQuit(wxMouseEvent& event);

	    int m_drag;
	    wxArrayString Comm,Exec;
	    void Insert(wxString x);
	    wxCommandEvent wxCE;
		Editor(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Editor();

		//(*Declarations(Editor)
		wxStaticText* StaticText10;
		wxStaticText* StaticText9;
		wxButton* m_ButtonComentariu;
		wxBitmapButton* m_ButtonSleep;
		wxButton* m_ButtonExport;
		wxBitmapButton* m_ButtonKey;
		wxStaticText* StaticText13;
		wxStaticText* StaticText2;
		wxFileDialog* m_SaveFile;
		wxBitmapButton* m_ButtonClick;
		wxButton* m_ButtonEditeaza;
		wxStaticText* StaticText6;
		wxStaticText* StaticText8;
		wxBitmapButton* m_ButtonEmail;
		wxStaticText* StaticText11;
		wxSpinButton* m_ButtonSpin;
		wxButton* m_ButtonSterge;
		wxBitmapButton* m_ButtonExecute;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* m_ButtonSave;
		wxBitmapButton* m_ButtonClose;
		wxButton* m_ButtonImport;
		wxButton* m_ButtonTest;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxBitmapButton* m_ButtonPower;
		wxBitmapButton* m_ButtonAsteapta;
		wxStaticText* StaticText12;
		wxBitmapButton* m_ButtonMove;
		wxBitmapButton* m_ButtonWeb;
		wxBitmapButton* m_ButtonMacrou;
		wxFileDialog* m_OpenFile;
		wxStaticText* StaticText4;
		wxBitmapButton* m_ButtonResize;
		wxBitmapButton* m_ButtonSSH;
		wxListView* m_List;
		//*)

	protected:

		//(*Identifiers(Editor)
		static const long ID_LISTVIEW1;
		static const long ID_SPINBUTTON1;
		static const long ID_BITMAPBUTTON2;
		static const long ID_BITMAPBUTTON1;
		static const long ID_BITMAPBUTTON3;
		static const long ID_BITMAPBUTTON4;
		static const long ID_BITMAPBUTTON5;
		static const long ID_BITMAPBUTTON6;
		static const long ID_BITMAPBUTTON7;
		static const long ID_BITMAPBUTTON8;
		static const long ID_BITMAPBUTTON9;
		static const long ID_BITMAPBUTTON10;
		static const long ID_BITMAPBUTTON11;
		static const long ID_BITMAPBUTTON12;
		static const long ID_BITMAPBUTTON13;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT10;
		static const long ID_STATICTEXT11;
		static const long ID_STATICTEXT12;
		static const long ID_STATICTEXT13;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON5;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_BUTTON6;
		static const long ID_BUTTON7;
		//*)

	private:

		//(*Handlers(Editor)
		void Onm_ButtonClickClick(wxCommandEvent& event);
		void Onm_ListItemActivated(wxListEvent& event);
		void Onm_ListKeyDown(wxListEvent& event);
		void Onm_ButtonMoveClick(wxCommandEvent& event);
		void Onm_ButtonSleepClick(wxCommandEvent& event);
		void Onm_ButtonKeyClick(wxCommandEvent& event);
		void Onm_ButtonComentariuClick(wxCommandEvent& event);
		void Onm_ButtonTestClick(wxCommandEvent& event);
		void Onm_ButtonExecuteClick(wxCommandEvent& event);
		void Onm_ButtonWebClick(wxCommandEvent& event);
		void Onm_ButtonEmailClick(wxCommandEvent& event);
		void Onm_ButtonPowerClick(wxCommandEvent& event);
		void Onm_ButtonSSHClick(wxCommandEvent& event);
		void Onm_ButtonCloseClick(wxCommandEvent& event);
		void Onm_ButtonResizeClick(wxCommandEvent& event);
		void Onm_ButtonEditeazaClick(wxCommandEvent& event);
		void Onm_ButtonStergeClick(wxCommandEvent& event);
		void Onm_ButtonExportClick(wxCommandEvent& event);
		void Onm_ButtonImportClick(wxCommandEvent& event);
		void Onm_ButtonSaveClick(wxCommandEvent& event);
		void Onm_ButtonSpinChange(wxSpinEvent& event);
		void OnClose(wxCloseEvent& event);
		void Onm_ButtonAsteaptaClick(wxCommandEvent& event);
		void Onm_ButtonMacrouClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
