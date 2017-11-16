#ifndef DIALOGEDITORKEY_H
#define DIALOGEDITORKEY_H

//(*Headers(DialogEditorKey)
#include <wx/sizer.h>
#include <wx/radiobox.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogEditorKey: public wxDialog
{
	public:

		DialogEditorKey(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogEditorKey();

		//(*Declarations(DialogEditorKey)
		wxChoice* m_ChoiceKey;
		wxStaticBoxSizer* StaticBoxSizer2;
		wxCheckBox* m_OneByOne;
		wxCheckBox* m_WIN;
		wxTextCtrl* m_Text;
		wxCheckBox* m_CTRL;
		wxRadioBox* m_ChoiceTaste;
		wxCheckBox* m_SHIFT;
		wxRadioBox* m_State;
		wxCheckBox* m_ALT;
		wxButton* m_ButtonOK;
		wxStaticBoxSizer* StaticBoxSizer1;
		wxButton* m_ButtonCancel;
		//*)

	protected:

		//(*Identifiers(DialogEditorKey)
		static const long ID_RADIOBOX1;
		static const long ID_CHOICE1;
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX4;
		static const long ID_CHECKBOX3;
		static const long ID_CHECKBOX2;
		static const long ID_RADIOBOX4;
		static const long ID_TEXTCTRL1;
		static const long ID_CHECKBOX5;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	public:

		//(*Handlers(DialogEditorKey)
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		void OnM_ChoiceTasteSelect(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
