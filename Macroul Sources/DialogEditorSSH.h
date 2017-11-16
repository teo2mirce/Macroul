#ifndef DIALOGEDITORSSH_H
#define DIALOGEDITORSSH_H

//(*Headers(DialogEditorSSH)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogEditorSSH: public wxDialog
{
	public:

		DialogEditorSSH(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogEditorSSH();

		//(*Declarations(DialogEditorSSH)
		wxTextCtrl* m_Comenzi;
		wxTextCtrl* m_User;
		wxStaticText* StaticText2;
		wxTextCtrl* m_Parola;
		wxTextCtrl* m_IP;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxStaticText* StaticText5;
		wxButton* m_ButtonOK;
		wxButton* m_ButtonCancel;
		wxCheckBox* m_Asteapta;
		wxStaticText* StaticText4;
		//*)

	protected:

		//(*Identifiers(DialogEditorSSH)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT5;
		static const long ID_CHECKBOX1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(DialogEditorSSH)
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
