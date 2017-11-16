#include "DialogEditorPower.h"

//(*InternalHeaders(DialogEditorPower)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogEditorPower)
const long DialogEditorPower::ID_STATICTEXT2 = wxNewId();
const long DialogEditorPower::ID_RADIOBOX4 = wxNewId();
const long DialogEditorPower::ID_STATICTEXT1 = wxNewId();
const long DialogEditorPower::ID_SPINCTRL1 = wxNewId();
const long DialogEditorPower::ID_BUTTON1 = wxNewId();
const long DialogEditorPower::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogEditorPower,wxDialog)
	//(*EventTable(DialogEditorPower)
	//*)
END_EVENT_TABLE()

DialogEditorPower::DialogEditorPower(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogEditorPower)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Power"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Actiune:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	wxString __wxRadioBoxChoices_1[3] =
	{
		_("Shutdown"),
		_("Restart"),
		_("Hibernate")
	};
	m_Radio = new wxRadioBox(this, ID_RADIOBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX4"));
	m_Radio->SetSelection(0);
	FlexGridSizer3->Add(m_Radio, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Label = new wxStaticText(this, ID_STATICTEXT1, _("Timp (s)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer3->Add(m_Label, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_Spin = new wxSpinCtrl(this, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 315360000, 0, _T("ID_SPINCTRL1"));
	m_Spin->SetValue(_T("0"));
	FlexGridSizer3->Add(m_Spin, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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

	Connect(ID_RADIOBOX4,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&DialogEditorPower::Onm_RadioSelect);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditorPower::Onm_ButtonOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditorPower::Onm_ButtonCancelClick);
	//*)
}

DialogEditorPower::~DialogEditorPower()
{
	//(*Destroy(DialogEditorPower)
	//*)
}


void DialogEditorPower::Onm_ButtonOKClick(wxCommandEvent& event)
{
    EndModal(1);
}

void DialogEditorPower::Onm_ButtonCancelClick(wxCommandEvent& event)
{
    EndModal(0);
}

void DialogEditorPower::Onm_RadioSelect(wxCommandEvent& event)
{
    if(m_Radio->GetSelection()==2)
        m_Label->Hide(),m_Spin->Hide();
    else
        m_Label->Show(),m_Spin->Show();
}
