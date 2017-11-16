#ifndef DIALOGGETCODE_H
#define DIALOGGETCODE_H

//(*Headers(DialogGetCode)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogGetCode: public wxDialog
{
	public:

        wxString expected;
		DialogGetCode(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogGetCode();

		//(*Declarations(DialogGetCode)
		wxTextCtrl* m_Text;
		wxStaticText* StaticText1;
		wxButton* m_Button;
		//*)

	protected:

		//(*Identifiers(DialogGetCode)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(DialogGetCode)
		void Onm_ButtonClick(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
