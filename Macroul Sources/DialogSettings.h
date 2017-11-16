#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H

//(*Headers(DialogSettings)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
//*)

class DialogSettings: public wxDialog
{
	public:

		DialogSettings(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogSettings();

		//(*Declarations(DialogSettings)
		wxCheckBox* m_Program;
		wxStaticText* StaticText10;
		wxStaticText* StaticText9;
		wxCheckBox* m_TrimitePrint;
		wxStaticText* StaticText13;
		wxStaticText* StaticText2;
		wxStaticText* StaticText14;
		wxSpinCtrl* m_ExeWait;
		wxButton* Button1;
		wxStaticText* StaticText6;
		wxComboBox* m_COM;
		wxStaticText* StaticText8;
		wxStaticText* StaticText11;
		wxSpinCtrl* m_Calitate;
		wxCheckBox* m_Voce;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxCheckBox* m_Card;
		wxTextCtrl* m_UID;
		wxSpinCtrl* m_Viteza;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxCheckBox* m_AskPass;
		wxStaticText* StaticText12;
		wxCheckBox* m_Hotkeys;
		wxStaticText* StaticText4;
		//*)

	protected:

		//(*Identifiers(DialogSettings)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_SPINCTRL1;
		static const long ID_STATICTEXT6;
		static const long ID_COMBOBOX1;
		static const long ID_STATICTEXT5;
		static const long ID_CHECKBOX2;
		static const long ID_STATICTEXT11;
		static const long ID_STATICTEXT2;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT10;
		static const long ID_SPINCTRL2;
		static const long ID_STATICTEXT13;
		static const long ID_STATICTEXT12;
		static const long ID_SPINCTRL3;
		static const long ID_STATICTEXT14;
		static const long ID_STATICTEXT4;
		static const long ID_CHECKBOX3;
		static const long ID_STATICTEXT7;
		static const long ID_CHECKBOX4;
		static const long ID_STATICTEXT8;
		static const long ID_CHECKBOX5;
		static const long ID_STATICTEXT9;
		static const long ID_CHECKBOX6;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(DialogSettings)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
