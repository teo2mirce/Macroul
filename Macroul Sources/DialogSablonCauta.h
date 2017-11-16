#ifndef DIALOGSABLONCAUTA_H
#define DIALOGSABLONCAUTA_H

//(*Headers(DialogSablonCauta)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogSablonCauta: public wxDialog
{
	public:
	    wxString UID;
        void Fill();
        wxCommandEvent wxCE;

		DialogSablonCauta(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogSablonCauta();

		//(*Declarations(DialogSablonCauta)
		wxButton* m_ButtonAdauga;
		wxStaticText* StaticText1;
		wxSpinCtrl* m_Search;
		wxButton* m_ButtonCauta;
		wxListView* m_List;
		//*)

	protected:

		//(*Identifiers(DialogSablonCauta)
		static const long ID_LISTVIEW1;
		static const long ID_STATICTEXT1;
		static const long ID_SPINCTRL1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		//*)

	private:

		//(*Handlers(DialogSablonCauta)
		void Onm_ButtonCautaClick(wxCommandEvent& event);
		void Onm_ButtonAdaugaClick(wxCommandEvent& event);
		void Onm_ListItemActivated(wxListEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
