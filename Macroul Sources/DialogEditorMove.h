#ifndef DIALOGEDITORMOVE_H
#define DIALOGEDITORMOVE_H

//(*Headers(DialogEditorMove)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/timer.h>
//*)

class DialogEditorMove: public wxDialog
{
	public:

		DialogEditorMove(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogEditorMove();

		//(*Declarations(DialogEditorMove)
		wxStaticText* StaticText2;
		wxRadioBox* RadioBox2;
		wxStaticText* StaticText1;
		wxRadioBox* RadioBox4;
		wxSpinCtrl* m_Y;
		wxButton* m_ButtonOK;
		wxRadioBox* RadioBox1;
		wxButton* m_ButtonCancel;
		wxSpinCtrl* m_X;
		wxTimer Timer1;
		//*)

	protected:

		//(*Identifiers(DialogEditorMove)
		static const long ID_STATICTEXT1;
		static const long ID_SPINCTRL1;
		static const long ID_RADIOBOX1;
		static const long ID_STATICTEXT2;
		static const long ID_SPINCTRL2;
		static const long ID_RADIOBOX2;
		static const long ID_RADIOBOX4;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_TIMER1;
		//*)

	private:

		//(*Handlers(DialogEditorMove)
		void OnTimer1Trigger(wxTimerEvent& event);
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
