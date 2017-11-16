#ifndef DIALOGEDITORRESIZE_H
#define DIALOGEDITORRESIZE_H

//(*Headers(DialogEditorResize)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogEditorResize: public wxDialog
{
	public:

		DialogEditorResize(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogEditorResize();

		//(*Declarations(DialogEditorResize)
		wxSpinCtrl* m_h;
		wxStaticText* StaticText2;
		wxTextCtrl* m_Text;
		wxSpinCtrl* m_y;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxStaticText* StaticText5;
		wxButton* m_ButtonOK;
		wxSpinCtrl* m_w;
		wxButton* m_ButtonCancel;
		wxStaticText* StaticText4;
		wxSpinCtrl* m_x;
		//*)

	protected:

		//(*Identifiers(DialogEditorResize)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_SPINCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_SPINCTRL2;
		static const long ID_STATICTEXT4;
		static const long ID_SPINCTRL3;
		static const long ID_STATICTEXT5;
		static const long ID_SPINCTRL4;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(DialogEditorResize)
		void Onm_ButtonOKClick(wxCommandEvent& event);
		void Onm_ButtonCancelClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
