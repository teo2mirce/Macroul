#ifndef DIALOGGETTEXT_H
#define DIALOGGETTEXT_H

//(*Headers(DialogGetText)
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogGetText: public wxDialog
{
	public:

		DialogGetText(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogGetText();

		//(*Declarations(DialogGetText)
		wxButton* m_ButtonOK;
		wxButton* m_ButtonCancel;
		wxTextCtrl* m_TextCode;
		//*)

	protected:

		//(*Identifiers(DialogGetText)
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(DialogGetText)
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
