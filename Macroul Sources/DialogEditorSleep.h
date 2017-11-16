#ifndef DIALOGEDITORSLEEP_H
#define DIALOGEDITORSLEEP_H

//(*Headers(DialogEditorSleep)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogEditorSleep: public wxDialog
{
	public:

		DialogEditorSleep(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogEditorSleep();

		//(*Declarations(DialogEditorSleep)
		wxSpinCtrl* m_Milisec;
		wxStaticText* StaticText1;
		wxButton* m_ButtonOK;
		wxButton* m_ButtonCancel;
		//*)

	protected:

		//(*Identifiers(DialogEditorSleep)
		static const long ID_STATICTEXT1;
		static const long ID_SPINCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(DialogEditorSleep)
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
