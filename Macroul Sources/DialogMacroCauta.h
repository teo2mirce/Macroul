#ifndef DIALOGMACROCAUTA_H
#define DIALOGMACROCAUTA_H

//(*Headers(DialogMacroCauta)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class DialogMacroCauta: public wxDialog
{
	public:
	    wxString UID;
        void Fill();
        wxCommandEvent wxCE;

		DialogMacroCauta(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogMacroCauta();

		//(*Declarations(DialogMacroCauta)
		wxButton* m_ButtonAdauga;
		wxButton* m_ButtonView;
		wxStaticText* StaticText1;
		wxSpinCtrl* m_Search;
		wxButton* m_ButtonCauta;
		wxListView* m_List;
		//*)

	protected:

		//(*Identifiers(DialogMacroCauta)
		static const long ID_LISTVIEW1;
		static const long ID_STATICTEXT1;
		static const long ID_SPINCTRL1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(DialogMacroCauta)
		void Onm_ButtonAdaugaClick(wxCommandEvent& event);
		void Onm_ButtonViewClick(wxCommandEvent& event);
		void Onm_SearchText(wxCommandEvent& event);
		void Onm_ButtonCautaClick(wxCommandEvent& event);
		void Onm_ListItemActivated(wxListEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
