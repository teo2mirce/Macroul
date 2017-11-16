#ifndef DIALOGGRUPURIADDEDIT_H
#define DIALOGGRUPURIADDEDIT_H

//(*Headers(DialogGrupuriAddEdit)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checklst.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogGrupuriAddEdit: public wxDialog
{
	public:

		DialogGrupuriAddEdit(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogGrupuriAddEdit();

		//(*Declarations(DialogGrupuriAddEdit)
		wxTextCtrl* m_Text;
		wxStaticText* StaticText1;
		wxButton* m_ButtonOK;
		wxCheckListBox* m_Check;
		wxButton* m_ButtonCancel;
		//*)

	protected:

		//(*Identifiers(DialogGrupuriAddEdit)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_CHECKLISTBOX1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(DialogGrupuriAddEdit)
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
