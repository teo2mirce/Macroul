#ifndef DIALOGMENIURIADDEDIT_H
#define DIALOGMENIURIADDEDIT_H

//(*Headers(DialogMeniuriAddEdit)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogMeniuriAddEdit: public wxDialog
{
	public:

		DialogMeniuriAddEdit(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogMeniuriAddEdit();

		//(*Declarations(DialogMeniuriAddEdit)
		wxChoice* Choice5;
		wxChoice* Choice3;
		wxTextCtrl* m_Text;
		wxStaticText* StaticText1;
		wxChoice* Choice7;
		wxChoice* Choice8;
		wxChoice* Choice9;
		wxChoice* Choice4;
		wxButton* m_ButtonOK;
		wxChoice* Choice6;
		wxButton* m_ButtonCancel;
		wxChoice* Choice1;
		wxChoice* Choice2;
		//*)

	protected:

		//(*Identifiers(DialogMeniuriAddEdit)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_CHOICE1;
		static const long ID_CHOICE2;
		static const long ID_CHOICE3;
		static const long ID_CHOICE4;
		static const long ID_CHOICE5;
		static const long ID_CHOICE6;
		static const long ID_CHOICE7;
		static const long ID_CHOICE8;
		static const long ID_CHOICE9;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(DialogMeniuriAddEdit)
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
