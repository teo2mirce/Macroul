#include "DialogEditorMove.h"

//(*InternalHeaders(DialogEditorMove)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogEditorMove)
const long DialogEditorMove::ID_STATICTEXT1 = wxNewId();
const long DialogEditorMove::ID_SPINCTRL1 = wxNewId();
const long DialogEditorMove::ID_RADIOBOX1 = wxNewId();
const long DialogEditorMove::ID_STATICTEXT2 = wxNewId();
const long DialogEditorMove::ID_SPINCTRL2 = wxNewId();
const long DialogEditorMove::ID_RADIOBOX2 = wxNewId();
const long DialogEditorMove::ID_RADIOBOX4 = wxNewId();
const long DialogEditorMove::ID_BUTTON1 = wxNewId();
const long DialogEditorMove::ID_BUTTON2 = wxNewId();
const long DialogEditorMove::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogEditorMove,wxDialog)
	//(*EventTable(DialogEditorMove)
	//*)
END_EVENT_TABLE()

DialogEditorMove::DialogEditorMove(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogEditorMove)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Muta"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer5 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer3 = new wxFlexGridSizer(3, 3, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("X: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_X = new wxSpinCtrl(this, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxDefaultSize, 0, -5000, 5000, 0, _T("ID_SPINCTRL1"));
	m_X->SetValue(_T("0"));
	FlexGridSizer3->Add(m_X, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	wxString __wxRadioBoxChoices_1[2] =
	{
		_("Pixeli"),
		_("Procente")
	};
	RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
	RadioBox1->Disable();
	RadioBox1->Hide();
	FlexGridSizer3->Add(RadioBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Y:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Y = new wxSpinCtrl(this, ID_SPINCTRL2, _T("0"), wxDefaultPosition, wxDefaultSize, 0, -5000, 5000, 0, _T("ID_SPINCTRL2"));
	m_Y->SetValue(_T("0"));
	FlexGridSizer3->Add(m_Y, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	wxString __wxRadioBoxChoices_2[2] =
	{
		_("Pixeli"),
		_("Procente")
	};
	RadioBox2 = new wxRadioBox(this, ID_RADIOBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_2, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX2"));
	RadioBox2->Disable();
	RadioBox2->Hide();
	FlexGridSizer3->Add(RadioBox2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	wxString __wxRadioBoxChoices_3[2] =
	{
		_("Normal"),
		_("Instant")
	};
	RadioBox4 = new wxRadioBox(this, ID_RADIOBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_3, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX4"));
	RadioBox4->SetSelection(0);
	FlexGridSizer4->Add(RadioBox4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	m_ButtonOK = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(m_ButtonOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonCancel = new wxButton(this, ID_BUTTON2, _("Anuleaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer2->Add(m_ButtonCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	Timer1.SetOwner(this, ID_TIMER1);
	Timer1.Start(100, false);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditorMove::Onm_ButtonOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditorMove::Onm_ButtonCancelClick);
	Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&DialogEditorMove::OnTimer1Trigger);
	//*)
}

DialogEditorMove::~DialogEditorMove()
{
	//(*Destroy(DialogEditorMove)
	//*)
}


void DialogEditorMove::OnTimer1Trigger(wxTimerEvent& event)
{
    POINT p;
    GetCursorPos(&p);
    wxString x="x: ";x<<p.x;
    wxString y="y: ";y<<p.y;
    StaticText1->SetLabelText(x);
    StaticText2->SetLabelText(y);
    Fit();
    Refresh();
    Layout();
}

void DialogEditorMove::Onm_ButtonOKClick(wxCommandEvent& event)
{
    EndModal(1);
}

void DialogEditorMove::Onm_ButtonCancelClick(wxCommandEvent& event)
{
    EndModal(0);
}
