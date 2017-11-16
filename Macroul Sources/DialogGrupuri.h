#ifndef DIALOGGRUPURI_H
#define DIALOGGRUPURI_H

//(*Headers(DialogGrupuri)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogGrupuri: public wxDialog
{
	public:
        wxString UID;
        void Fill();
		DialogGrupuri(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogGrupuri();

		//(*Declarations(DialogGrupuri)
		wxButton* m_ButtonEdit;
		wxButton* m_ButtonAdd;
		wxButton* m_ButtonDelete;
		wxListView* m_List;
		//*)

	protected:

		//(*Identifiers(DialogGrupuri)
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON5;
		//*)

	private:

		//(*Handlers(DialogGrupuri)
		void Onm_ButtonAddClick(wxCommandEvent& event);
		void Onm_ButtonEditClick(wxCommandEvent& event);
		void Onm_ButtonDeleteClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
