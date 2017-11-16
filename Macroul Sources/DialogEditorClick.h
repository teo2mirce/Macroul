#ifndef DIALOGEDITORCLICK_H
#define DIALOGEDITORCLICK_H

//(*Headers(DialogEditorClick)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/timer.h>
//*)

class DialogEditorClick: public wxDialog
{
	public:

        wxCommandEvent wxCE;
		void onm_KeyEmail(wxKeyEvent& event);
		void onm_KeyPass(wxKeyEvent& event);


        void onFoc1(wxFocusEvent& event);
        void onFoc2(wxFocusEvent& event);


		DialogEditorClick(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogEditorClick();

		//(*Declarations(DialogEditorClick)
		wxSpinCtrl* m_XMAX;
		wxStaticText* StaticText2;
		wxCheckBox* m_CheckRandom;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxRadioBox* m_RadioStMjDr;
		wxSpinCtrl* m_YMAX;
		wxStaticText* StaticText5;
		wxSpinCtrl* m_Y;
		wxButton* m_ButtonOK;
		wxButton* m_ButtonCancel;
		wxSpinCtrl* m_X;
		wxRadioBox* m_RadioApRiAm;
		wxStaticText* StaticText4;
		wxTimer Timer1;
		//*)

	protected:

		//(*Identifiers(DialogEditorClick)
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT1;
		static const long ID_SPINCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_SPINCTRL2;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT3;
		static const long ID_SPINCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_SPINCTRL4;
		static const long ID_RADIOBOX3;
		static const long ID_RADIOBOX4;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_TIMER1;
		//*)

	private:

		//(*Handlers(DialogEditorClick)
		void OnTimer1Trigger(wxTimerEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_CheckRandomClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
