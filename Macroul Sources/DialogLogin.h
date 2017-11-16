#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

//(*Headers(DialogLogin)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/hyperlink.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogLogin: public wxDialog
{
	public:
		void onm_KeyEmail(wxKeyEvent& event);
		void onm_KeyPass(wxKeyEvent& event);
		wxCommandEvent wxCE;

		DialogLogin(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogLogin();

		//(*Declarations(DialogLogin)
		wxStaticText* StaticText2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxHyperlinkCtrl* HyperlinkCtrl1;
		wxTextCtrl* m_TextEmail;
		wxTextCtrl* m_TextPass;
		wxStaticText* m_TextError;
		wxButton* m_ButtonAuth;
		//*)

	protected:

		//(*Identifiers(DialogLogin)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT4;
		static const long ID_HYPERLINKCTRL1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(DialogLogin)
		void Onm_ButtonAuthClick(wxCommandEvent& event);
		void OnHyperlinkCtrl1Click(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnChar(wxKeyEvent& event);
		void OnKeyUp(wxKeyEvent& event);
		void Onm_TextPassText(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
