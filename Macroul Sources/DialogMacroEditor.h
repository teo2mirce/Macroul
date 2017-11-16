#ifndef DIALOGMACROEDITOR_H
#define DIALOGMACROEDITOR_H

//(*Headers(DialogMacroEditor)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "MacroulMain.h"
class DialogMacroEditor: public wxDialog
{
	public:
	    void *framed;
	    wxCommandEvent wxCE;
	    wxString UID;
        void Fill();
		DialogMacroEditor(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogMacroEditor();

		//(*Declarations(DialogMacroEditor)
		wxButton* m_ButtonEditeaza;
		wxButton* m_ButtonSterge;
		wxButton* m_ButtonAdd;
		wxListView* m_List;
		//*)

	protected:

		//(*Identifiers(DialogMacroEditor)
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(DialogMacroEditor)
		void Onm_ButtonAddClick(wxCommandEvent& event);
		void Onm_ButtonEditeazaClick(wxCommandEvent& event);
		void Onm_ButtonStergeClick(wxCommandEvent& event);
		void Onm_ListItemActivated(wxListEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
