#ifndef DIALOGEDITORWEBSITE_H
#define DIALOGEDITORWEBSITE_H

//(*Headers(DialogEditorWebsite)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogEditorWebsite: public wxDialog
{
	public:

		DialogEditorWebsite(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogEditorWebsite();

		//(*Declarations(DialogEditorWebsite)
		wxTextCtrl* m_Website;
		wxStaticText* StaticText1;
		wxButton* m_ButtonOK;
		wxButton* m_ButtonCancel;
		//*)

	protected:

		//(*Identifiers(DialogEditorWebsite)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(DialogEditorWebsite)
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
