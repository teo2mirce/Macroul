#ifndef DIALOGNLPEDITOR_H
#define DIALOGNLPEDITOR_H

//(*Headers(DialogNLPEditor)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogNLPEditor: public wxDialog
{
	public:

	    wxCommandEvent wxCE;

	    wxString UID;
        void Fill();
		DialogNLPEditor(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogNLPEditor();

		//(*Declarations(DialogNLPEditor)
		wxButton* m_ButtonEditeaza;
		wxButton* m_ButtonSterge;
		wxButton* m_ButtonAdd;
		wxListView* m_List;
		//*)

	protected:

		//(*Identifiers(DialogNLPEditor)
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(DialogNLPEditor)
		void Onm_ButtonAddClick(wxCommandEvent& event);
		void Onm_ButtonEditeazaClick(wxCommandEvent& event);
		void Onm_ButtonStergeClick(wxCommandEvent& event);
		void Onm_ListItemActivated(wxListEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
