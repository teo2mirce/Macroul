#include "DialogLimbajNatural.h"

//(*InternalHeaders(DialogLimbajNatural)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogLimbajNatural)
const long DialogLimbajNatural::ID_BITMAPBUTTON1 = wxNewId();
const long DialogLimbajNatural::ID_BITMAPBUTTON6 = wxNewId();
const long DialogLimbajNatural::ID_BITMAPBUTTON5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogLimbajNatural,wxDialog)
	//(*EventTable(DialogLimbajNatural)
	//*)
END_EVENT_TABLE()

DialogLimbajNatural::DialogLimbajNatural(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogLimbajNatural)
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	SetBackgroundColour(wxColour(2,32,40));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	m_AddEdit = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("res\\AddEditNLP.bmp"))), wxDefaultPosition, wxSize(200,75), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
	FlexGridSizer1->Add(m_AddEdit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_RunNLP = new wxBitmapButton(this, ID_BITMAPBUTTON6, wxBitmap(wxImage(_T("res\\CautaNLP.bmp"))), wxDefaultPosition, wxSize(200,75), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
	FlexGridSizer1->Add(m_RunNLP, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Exit = new wxBitmapButton(this, ID_BITMAPBUTTON5, wxBitmap(wxImage(_T("res\\5.bmp"))), wxDefaultPosition, wxSize(200,75), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
	FlexGridSizer1->Add(m_Exit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogLimbajNatural::Onm_AddEditClick);
	Connect(ID_BITMAPBUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogLimbajNatural::Onm_RunNLPClick);
	Connect(ID_BITMAPBUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogLimbajNatural::Onm_ExitClick);
	//*)

    this->Layout();
    this->Fit();
    this->SetPosition(wxPoint(10+GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));


}

DialogLimbajNatural::~DialogLimbajNatural()
{
	//(*Destroy(DialogLimbajNatural)
	//*)
}

#include "DialogSablonCauta.h"
void DialogLimbajNatural::Onm_RunNLPClick(wxCommandEvent& event)
{

    DialogSablonCauta x(this);
    x.UID=UID;
    x.Fill();
    x.ShowModal();
}
#include "DialogNLPEditor.h"
void DialogLimbajNatural::Onm_AddEditClick(wxCommandEvent& event)
{
    DialogNLPEditor x(this);
    x.UID=UID;
    x.Fill();
    x.ShowModal();
}


void DialogLimbajNatural::Onm_ExitClick(wxCommandEvent& event)
{
    Close(0);
}
