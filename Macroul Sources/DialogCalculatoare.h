#ifndef DIALOGCALCULATOARE_H
#define DIALOGCALCULATOARE_H
#include "Misc.h"

//(*Headers(DialogCalculatoare)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogCalculatoare: public wxDialog
{
	public:
        void Fill();
	    wxString UID;
		DialogCalculatoare(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogCalculatoare();

		//(*Declarations(DialogCalculatoare)
		wxButton* m_ButtonSet;
		wxButton* m_ButtonEdit;
		wxButton* m_ButtonAdd;
		wxButton* m_ButtonDelete;
		wxListView* m_List;
		//*)

	protected:

		//(*Identifiers(DialogCalculatoare)
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON5;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(DialogCalculatoare)
		void Onm_ButtonAddClick(wxCommandEvent& event);
		void Onm_ButtonEditClick(wxCommandEvent& event);
		void Onm_ButtonDeleteClick(wxCommandEvent& event);
		void Onm_ButtonSetClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
