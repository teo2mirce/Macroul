#ifndef DIALOGEDITORCOMENTARIU_H
#define DIALOGEDITORCOMENTARIU_H

//(*Headers(DialogEditorComentariu)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogEditorComentariu: public wxDialog
{
	public:

		DialogEditorComentariu(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogEditorComentariu();

		//(*Declarations(DialogEditorComentariu)
		wxStaticText* StaticText1;
		wxTextCtrl* m_Comment;
		wxButton* m_ButtonOK;
		wxButton* m_ButtonCancel;
		//*)

	protected:

		//(*Identifiers(DialogEditorComentariu)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(DialogEditorComentariu)
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
