#ifndef DIALOGEDITORASTEAPTA_H
#define DIALOGEDITORASTEAPTA_H

//(*Headers(DialogEditorAsteapta)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/timer.h>
//*)

class DialogEditorAsteapta: public wxDialog
{
	public:

		DialogEditorAsteapta(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogEditorAsteapta();

		//(*Declarations(DialogEditorAsteapta)
		wxSpinCtrl* SpinCtrl1;
		wxStaticText* StaticText2;
		wxRadioBox* m_Radio;
		wxStaticText* StaticText6;
		wxTextCtrl* m_Text;
		wxFlexGridSizer* FlexGridSizer5;
		wxStaticText* StaticText8;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxFlexGridSizer* FlexGridSizer7;
		wxSpinCtrl* SpinCtrl3;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxFlexGridSizer* FlexGridSizer8;
		wxSpinCtrl* m_Y;
		wxButton* m_ButtonOK;
		wxSpinCtrl* SpinCtrl2;
		wxRadioBox* RadioBox1;
		wxButton* m_ButtonCancel;
		wxSpinCtrl* m_X;
		wxStaticText* StaticText4;
		wxTimer Timer1;
		//*)

	protected:

		//(*Identifiers(DialogEditorAsteapta)
		static const long ID_RADIOBOX4;
		static const long ID_RADIOBOX1;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_SPINCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_SPINCTRL2;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_SPINCTRL3;
		static const long ID_STATICTEXT7;
		static const long ID_SPINCTRL4;
		static const long ID_STATICTEXT8;
		static const long ID_SPINCTRL5;
		static const long ID_STATICTEXT4;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_TIMER1;
		//*)

	public:

		//(*Handlers(DialogEditorAsteapta)
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		void OnTimer1Trigger(wxTimerEvent& event);
		void Onm_RadioSelect(wxCommandEvent& event);
		void OnRadioBox1Select(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
