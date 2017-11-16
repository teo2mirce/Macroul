#ifndef DIALOGMENIURI_H
#define DIALOGMENIURI_H

//(*Headers(DialogMeniuri)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogMeniuri: public wxDialog
{
	public:
        wxString UID;
        void Fill();

		DialogMeniuri(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogMeniuri();

		//(*Declarations(DialogMeniuri)
		wxButton* m_ButtonSet;
		wxButton* m_ButtonEdit;
		wxButton* m_ButtonAdd;
		wxButton* m_ButtonDelete;
		wxListView* m_List;
		//*)

	protected:

		//(*Identifiers(DialogMeniuri)
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON5;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(DialogMeniuri)
		void Onm_ButtonAddClick(wxCommandEvent& event);
		void Onm_ButtonEditClick(wxCommandEvent& event);
		void Onm_ButtonDeleteClick(wxCommandEvent& event);
		void Onm_ButtonSetClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
