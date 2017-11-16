#ifndef DIALOGCALCULATOAREADDEDIT_H
#define DIALOGCALCULATOAREADDEDIT_H

//(*Headers(DialogCalculatoareAddEdit)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogCalculatoareAddEdit: public wxDialog
{
	public:

		DialogCalculatoareAddEdit(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogCalculatoareAddEdit();

		//(*Declarations(DialogCalculatoareAddEdit)
		wxTextCtrl* m_Text;
		wxStaticText* StaticText1;
		wxButton* m_ButtonOK;
		wxButton* m_ButtonCancel;
		//*)

	protected:

		//(*Identifiers(DialogCalculatoareAddEdit)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(DialogCalculatoareAddEdit)
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
