#ifndef DIALOGLIMBAJNATURAL_H
#define DIALOGLIMBAJNATURAL_H

//(*Headers(DialogLimbajNatural)
#include <wx/sizer.h>
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
//*)

class DialogLimbajNatural: public wxDialog
{
	public:
        wxString UID;

	    wxCommandEvent wxCE;

		DialogLimbajNatural(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogLimbajNatural();

		//(*Declarations(DialogLimbajNatural)
		wxBitmapButton* m_Exit;
		wxBitmapButton* m_RunNLP;
		wxBitmapButton* m_AddEdit;
		//*)

	protected:

		//(*Identifiers(DialogLimbajNatural)
		static const long ID_BITMAPBUTTON1;
		static const long ID_BITMAPBUTTON6;
		static const long ID_BITMAPBUTTON5;
		//*)

	private:

		//(*Handlers(DialogLimbajNatural)
		void Onm_ExitClick(wxCommandEvent& event);
		void Onm_RunNLPClick(wxCommandEvent& event);
		void Onm_AddEditClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
