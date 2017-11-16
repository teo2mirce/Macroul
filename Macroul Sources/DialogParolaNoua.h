#ifndef DIALOGPAROLANOUA_H
#define DIALOGPAROLANOUA_H

//(*Headers(DialogParolaNoua)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogParolaNoua: public wxDialog
{
	public:

		DialogParolaNoua(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogParolaNoua();

		//(*Declarations(DialogParolaNoua)
		wxStaticText* StaticText2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxTextCtrl* m_TextEmail;
		wxTextCtrl* m_TextPass;
		wxButton* m_ButtonAuth;
		//*)

	protected:

		//(*Identifiers(DialogParolaNoua)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(DialogParolaNoua)
		void Onm_ButtonAuthClick(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
