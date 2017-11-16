#ifndef DIALOGEDITOREMAIL_H
#define DIALOGEDITOREMAIL_H

//(*Headers(DialogEditorEmail)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogEditorEmail: public wxDialog
{
	public:

		DialogEditorEmail(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogEditorEmail();

		//(*Declarations(DialogEditorEmail)
		wxStaticText* StaticText2;
		wxTextCtrl* m_Text;
		wxStaticText* StaticText1;
		wxTextCtrl* m_Email;
		wxButton* m_ButtonOK;
		wxButton* m_ButtonCancel;
		//*)

	protected:

		//(*Identifiers(DialogEditorEmail)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(DialogEditorEmail)
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
