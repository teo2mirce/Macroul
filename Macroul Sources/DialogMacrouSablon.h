#ifndef DIALOGMACROUSABLON_H
#define DIALOGMACROUSABLON_H

//(*Headers(DialogMacrouSablon)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogMacrouSablon: public wxDialog
{
	public:

		DialogMacrouSablon(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogMacrouSablon();

		//(*Declarations(DialogMacrouSablon)
		wxRadioBox* m_Radio;
		wxStaticText* m_ST;
		wxChoice* m_Macrou;
		wxStaticText* m_MT;
		wxButton* m_ButtonOK;
		wxButton* m_ButtonCancel;
		wxTextCtrl* m_Sablon;
		//*)

	protected:

		//(*Identifiers(DialogMacrouSablon)
		static const long ID_RADIOBOX4;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	public:

		//(*Handlers(DialogMacrouSablon)
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		void Onm_RadioSelect(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
