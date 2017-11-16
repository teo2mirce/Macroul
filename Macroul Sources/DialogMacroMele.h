#ifndef DIALOGMACROMELE_H
#define DIALOGMACROMELE_H

//(*Headers(DialogMacroMele)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogMacroMele: public wxDialog
{
	public:
	    wxString UID;
        void Fill();
        wxCommandEvent wxCE;

		DialogMacroMele(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogMacroMele();

		//(*Declarations(DialogMacroMele)
		wxButton* m_ButtonActivator;
		wxListView* m_List;
		//*)

	protected:

		//(*Identifiers(DialogMacroMele)
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(DialogMacroMele)
		void Onm_ButtonActivatorClick(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		void Onm_ListItemActivated(wxListEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
