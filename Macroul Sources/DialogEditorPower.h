#ifndef DIALOGEDITORPOWER_H
#define DIALOGEDITORPOWER_H

//(*Headers(DialogEditorPower)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogEditorPower: public wxDialog
{
	public:

		DialogEditorPower(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogEditorPower();

		//(*Declarations(DialogEditorPower)
		wxRadioBox* m_Radio;
		wxStaticText* StaticText2;
		wxStaticText* m_Label;
		wxButton* m_ButtonOK;
		wxButton* m_ButtonCancel;
		wxSpinCtrl* m_Spin;
		//*)

	protected:

		//(*Identifiers(DialogEditorPower)
		static const long ID_STATICTEXT2;
		static const long ID_RADIOBOX4;
		static const long ID_STATICTEXT1;
		static const long ID_SPINCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(DialogEditorPower)
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		void Onm_RadioSelect(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
