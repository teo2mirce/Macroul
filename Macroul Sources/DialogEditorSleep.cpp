#include "DialogEditorSleep.h"

//(*InternalHeaders(DialogEditorSleep)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogEditorSleep)
const long DialogEditorSleep::ID_STATICTEXT1 = wxNewId();
const long DialogEditorSleep::ID_SPINCTRL1 = wxNewId();
const long DialogEditorSleep::ID_BUTTON1 = wxNewId();
const long DialogEditorSleep::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogEditorSleep,wxDialog)
	//(*EventTable(DialogEditorSleep)
	//*)
END_EVENT_TABLE()

DialogEditorSleep::DialogEditorSleep(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogEditorSleep)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Asteapta (milisecunde)"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Milisecunde de asteptat:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Milisec = new wxSpinCtrl(this, ID_SPINCTRL1, _T("1000"), wxDefaultPosition, wxDefaultSize, 0, 0, 1000000000, 1000, _T("ID_SPINCTRL1"));
	m_Milisec->SetValue(_T("1000"));
	FlexGridSizer3->Add(m_Milisec, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	m_ButtonOK = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(m_ButtonOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonCancel = new wxButton(this, ID_BUTTON2, _("Anuleaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer2->Add(m_ButtonCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditorSleep::Onm_ButtonOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditorSleep::Onm_ButtonCancelClick);
	//*)
}

DialogEditorSleep::~DialogEditorSleep()
{
	//(*Destroy(DialogEditorSleep)
	//*)
}


void DialogEditorSleep::Onm_ButtonOKClick(wxCommandEvent& event)
{
    EndModal(1);
}

void DialogEditorSleep::Onm_ButtonCancelClick(wxCommandEvent& event)
{
    EndModal(0);
}
