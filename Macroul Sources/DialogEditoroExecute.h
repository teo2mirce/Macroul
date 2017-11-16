#ifndef DIALOGEDITOROEXECUTE_H
#define DIALOGEDITOROEXECUTE_H

//(*Headers(DialogEditoroExecute)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/filepicker.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogEditoroExecute: public wxDialog
{
	public:

		DialogEditoroExecute(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogEditoroExecute();

		//(*Declarations(DialogEditoroExecute)
		wxStaticText* StaticText2;
		wxTextCtrl* m_Arguments;
		wxStaticText* StaticText1;
		wxCheckBox* m_Ascunde;
		wxFilePickerCtrl* m_File;
		wxButton* m_ButtonOK;
		wxButton* m_ButtonCancel;
		wxCheckBox* m_Asteapta;
		//*)

	protected:

		//(*Identifiers(DialogEditoroExecute)
		static const long ID_STATICTEXT2;
		static const long ID_FILEPICKERCTRL1;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(DialogEditoroExecute)
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		void Onm_ButtonOKClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
