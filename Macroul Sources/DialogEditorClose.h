#ifndef DIALOGEDITORCLOSE_H
#define DIALOGEDITORCLOSE_H

//(*Headers(DialogEditorClose)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogEditorClose: public wxDialog
{
	public:

		DialogEditorClose(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogEditorClose();

		//(*Declarations(DialogEditorClose)
		wxRadioBox* m_Radio;
		wxTextCtrl* m_Text;
		wxStaticText* StaticText1;
		wxButton* m_ButtonOK;
		wxButton* m_ButtonCancel;
		//*)

	protected:

		//(*Identifiers(DialogEditorClose)
		static const long ID_RADIOBOX4;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(DialogEditorClose)
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
