#ifndef DIALOGEDITDESC_H
#define DIALOGEDITDESC_H

//(*Headers(DialogEditDesc)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogEditDesc: public wxDialog
{
	public:

		DialogEditDesc(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogEditDesc();

		//(*Declarations(DialogEditDesc)
		wxStaticText* StaticText2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxTextCtrl* m_Descriere;
		wxTextCtrl* m_Nume;
		wxButton* m_ButtonOK;
		wxButton* m_ButtonCancel;
		wxCheckBox* m_Public;
		//*)

	protected:

		//(*Identifiers(DialogEditDesc)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_CHECKBOX1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(DialogEditDesc)
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		void Onm_ButtonOKClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
