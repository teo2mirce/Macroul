#ifndef DIALOGACTIVATOR_H
#define DIALOGACTIVATOR_H

//(*Headers(DialogActivator)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/datectrl.h>
#include <wx/spinctrl.h>
#include <wx/statline.h>
#include <wx/dateevt.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/timer.h>
//*)
#include <wx/timectrl.h>
class DialogActivator: public wxDialog
{
	public:
        bool keyStatus;
		DialogActivator(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogActivator();

		//(*Declarations(DialogActivator)
		wxCheckBox* m_CheckVoce;
		wxButton* m_Button10;
		wxTimePickerCtrl* m_TimePicker;
		wxTextCtrl* m_CardCode;
		wxButton* m_ButtonScan;
		wxStaticText* StaticText1;
		wxCheckBox* m_CheckCard;
		wxTextCtrl* m_VoiceText;
		wxButton* m_ButtonSave;
		wxStaticLine* StaticLine4;
		wxStaticLine* StaticLine2;
		wxCheckBox* m_CheckProgram;
		wxCheckBox* m_CheckTaste;
		wxDatePickerCtrl* m_DatePicker;
		wxStaticLine* StaticLine3;
		wxStaticLine* StaticLine1;
		wxButton* m_Inregistreaza;
		wxButton* m_ButtonTastatura;
		wxSpinCtrl* m_Times;
		wxTextCtrl* m_Tastatura;
		wxTimer Timer1;
		//*)

	protected:

		//(*Identifiers(DialogActivator)
		static const long ID_CHECKBOX1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_STATICLINE1;
		static const long ID_CHECKBOX2;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON3;
		static const long ID_STATICLINE2;
		static const long ID_CHECKBOX3;
		static const long ID_DATEPICKERCTRL1;
		static const long ID_CUSTOM1;
		static const long ID_BUTTON4;
		static const long ID_STATICLINE3;
		static const long ID_CHECKBOX4;
		static const long ID_TEXTCTRL4;
		static const long ID_BUTTON5;
		static const long ID_STATICLINE4;
		static const long ID_STATICTEXT1;
		static const long ID_SPINCTRL1;
		static const long ID_BUTTON2;
		static const long ID_TIMER1;
		//*)

	private:

		//(*Handlers(DialogActivator)
		void OnTimer1Trigger(wxTimerEvent& event);
		void Onm_InregistreazaClick(wxCommandEvent& event);
		void Onm_ButtonSaveClick(wxCommandEvent& event);
		void Onm_ButtonScanClick(wxCommandEvent& event);
		void Onm_ButtonTastaturaClick(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		void Onm_Button10Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
