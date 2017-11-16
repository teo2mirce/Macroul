#ifndef DIALOGVARIABILA_H
#define DIALOGVARIABILA_H

//(*Headers(DialogVariabila)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogVariabila: public wxDialog
{
	public:

		DialogVariabila(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogVariabila();

		//(*Declarations(DialogVariabila)
		wxRadioBox* m_Radio;
		wxTextCtrl* m_Text;
		wxStaticText* m_LabelSeparator;
		wxButton* m_ButtonOK;
		wxStaticText* m_LabelText;
		wxTextCtrl* m_Separator;
		wxButton* m_ButtonCancel;
		//*)

	protected:

		//(*Identifiers(DialogVariabila)
		static const long ID_RADIOBOX1;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	public:

		//(*Handlers(DialogVariabila)
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		void Onm_RadioTipSelect(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
