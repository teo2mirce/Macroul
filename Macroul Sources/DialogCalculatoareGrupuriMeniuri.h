#ifndef DIALOGCALCULATOAREGRUPURIMENIURI_H
#define DIALOGCALCULATOAREGRUPURIMENIURI_H

//(*Headers(DialogCalculatoareGrupuriMeniuri)
#include <wx/sizer.h>
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
//*)

class DialogCalculatoareGrupuriMeniuri: public wxDialog
{
	public:
        wxString UID;
		DialogCalculatoareGrupuriMeniuri(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogCalculatoareGrupuriMeniuri();

		//(*Declarations(DialogCalculatoareGrupuriMeniuri)
		wxBitmapButton* m_ButtonMeniuri;
		wxBitmapButton* m_Exit;
		wxBitmapButton* m_ButtonGrupuri;
		wxBitmapButton* m_ButtonCalculatoare;
		//*)

	protected:

		//(*Identifiers(DialogCalculatoareGrupuriMeniuri)
		static const long ID_BITMAPBUTTON6;
		static const long ID_BITMAPBUTTON1;
		static const long ID_BITMAPBUTTON2;
		static const long ID_BITMAPBUTTON5;
		//*)

	private:

		//(*Handlers(DialogCalculatoareGrupuriMeniuri)
		void Onm_ButtonCalculatoareClick(wxCommandEvent& event);
		void Onm_ButtonGrupuriClick(wxCommandEvent& event);
		void Onm_ButtonMeniuriClick(wxCommandEvent& event);
		void Onm_ExitClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
