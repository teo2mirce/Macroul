#include "DialogCalculatoareGrupuriMeniuri.h"

//(*InternalHeaders(DialogCalculatoareGrupuriMeniuri)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogCalculatoareGrupuriMeniuri)
const long DialogCalculatoareGrupuriMeniuri::ID_BITMAPBUTTON6 = wxNewId();
const long DialogCalculatoareGrupuriMeniuri::ID_BITMAPBUTTON1 = wxNewId();
const long DialogCalculatoareGrupuriMeniuri::ID_BITMAPBUTTON2 = wxNewId();
const long DialogCalculatoareGrupuriMeniuri::ID_BITMAPBUTTON5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogCalculatoareGrupuriMeniuri,wxDialog)
	//(*EventTable(DialogCalculatoareGrupuriMeniuri)
	//*)
END_EVENT_TABLE()

DialogCalculatoareGrupuriMeniuri::DialogCalculatoareGrupuriMeniuri(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogCalculatoareGrupuriMeniuri)
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	SetBackgroundColour(wxColour(2,32,40));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	m_ButtonCalculatoare = new wxBitmapButton(this, ID_BITMAPBUTTON6, wxBitmap(wxImage(_T("res\\calc.bmp"))), wxDefaultPosition, wxSize(200,75), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
	FlexGridSizer1->Add(m_ButtonCalculatoare, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonGrupuri = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("res\\grup.bmp"))), wxDefaultPosition, wxSize(200,75), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
	FlexGridSizer1->Add(m_ButtonGrupuri, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonMeniuri = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("res\\meniuri.bmp"))), wxDefaultPosition, wxSize(200,75), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
	FlexGridSizer1->Add(m_ButtonMeniuri, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Exit = new wxBitmapButton(this, ID_BITMAPBUTTON5, wxBitmap(wxImage(_T("res\\5.bmp"))), wxDefaultPosition, wxSize(200,75), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
	FlexGridSizer1->Add(m_Exit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BITMAPBUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogCalculatoareGrupuriMeniuri::Onm_ButtonCalculatoareClick);
	Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogCalculatoareGrupuriMeniuri::Onm_ButtonGrupuriClick);
	Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogCalculatoareGrupuriMeniuri::Onm_ButtonMeniuriClick);
	Connect(ID_BITMAPBUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogCalculatoareGrupuriMeniuri::Onm_ExitClick);
	//*)
    this->Layout();
    this->Fit();
    this->SetPosition(wxPoint(10+GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));

}

DialogCalculatoareGrupuriMeniuri::~DialogCalculatoareGrupuriMeniuri()
{
	//(*Destroy(DialogCalculatoareGrupuriMeniuri)
	//*)
}

#include "DialogCalculatoare.h"
void DialogCalculatoareGrupuriMeniuri::Onm_ButtonCalculatoareClick(wxCommandEvent& event)
{
    DialogCalculatoare x(this);
    x.UID=UID;
    x.Fill();
    x.ShowModal();
}
#include "DialogGrupuri.h"
void DialogCalculatoareGrupuriMeniuri::Onm_ButtonGrupuriClick(wxCommandEvent& event)
{
    DialogGrupuri x(this);
    x.UID=UID;
    x.Fill();
    x.ShowModal();
}
#include "DialogMeniuri.h"
void DialogCalculatoareGrupuriMeniuri::Onm_ButtonMeniuriClick(wxCommandEvent& event)
{
    DialogMeniuri x(this);
    x.UID=UID;
    x.Fill();
    x.ShowModal();
}

void DialogCalculatoareGrupuriMeniuri::Onm_ExitClick(wxCommandEvent& event)
{

    Close(0);
}
