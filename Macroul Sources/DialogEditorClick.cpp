#include "DialogEditorClick.h"

//(*InternalHeaders(DialogEditorClick)
#include <wx/intl.h>
#include <wx/string.h>
//*)


#include <wx/event.h>
//(*IdInit(DialogEditorClick)
const long DialogEditorClick::ID_STATICTEXT5 = wxNewId();
const long DialogEditorClick::ID_STATICTEXT1 = wxNewId();
const long DialogEditorClick::ID_SPINCTRL1 = wxNewId();
const long DialogEditorClick::ID_STATICTEXT2 = wxNewId();
const long DialogEditorClick::ID_SPINCTRL2 = wxNewId();
const long DialogEditorClick::ID_CHECKBOX1 = wxNewId();
const long DialogEditorClick::ID_STATICTEXT3 = wxNewId();
const long DialogEditorClick::ID_SPINCTRL3 = wxNewId();
const long DialogEditorClick::ID_STATICTEXT4 = wxNewId();
const long DialogEditorClick::ID_SPINCTRL4 = wxNewId();
const long DialogEditorClick::ID_RADIOBOX3 = wxNewId();
const long DialogEditorClick::ID_RADIOBOX4 = wxNewId();
const long DialogEditorClick::ID_BUTTON1 = wxNewId();
const long DialogEditorClick::ID_BUTTON2 = wxNewId();
const long DialogEditorClick::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogEditorClick,wxDialog)
	//(*EventTable(DialogEditorClick)
	//*)
END_EVENT_TABLE()

DialogEditorClick::DialogEditorClick(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogEditorClick)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer7;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Click cursor"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer5 = new wxFlexGridSizer(0, 1, 0, 0);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer5->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer3 = new wxFlexGridSizer(3, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("x: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_X = new wxSpinCtrl(this, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxDefaultSize, 0, -5000, 5000, 0, _T("ID_SPINCTRL1"));
	m_X->SetValue(_T("0"));
	FlexGridSizer3->Add(m_X, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("y:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Y = new wxSpinCtrl(this, ID_SPINCTRL2, _T("0"), wxDefaultPosition, wxDefaultSize, 0, -5000, 5000, 0, _T("ID_SPINCTRL2"));
	m_Y->SetValue(_T("0"));
	FlexGridSizer3->Add(m_Y, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_CheckRandom = new wxCheckBox(this, ID_CHECKBOX1, _("Aleator"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	m_CheckRandom->SetValue(false);
	FlexGridSizer6->Add(m_CheckRandom, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7 = new wxFlexGridSizer(3, 2, 0, 0);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("X MAX: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer7->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_XMAX = new wxSpinCtrl(this, ID_SPINCTRL3, _T("0"), wxDefaultPosition, wxDefaultSize, 0, -5000, 5000, 0, _T("ID_SPINCTRL3"));
	m_XMAX->SetValue(_T("0"));
	m_XMAX->Disable();
	FlexGridSizer7->Add(m_XMAX, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Y MAX:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer7->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_YMAX = new wxSpinCtrl(this, ID_SPINCTRL4, _T("0"), wxDefaultPosition, wxDefaultSize, 0, -5000, 5000, 0, _T("ID_SPINCTRL4"));
	m_YMAX->SetValue(_T("0"));
	m_YMAX->Disable();
	FlexGridSizer7->Add(m_YMAX, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6->Add(FlexGridSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5->Add(FlexGridSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	wxString __wxRadioBoxChoices_1[3] =
	{
		_("Stanga"),
		_("Dreapta"),
		_("Mijloc")
	};
	m_RadioStMjDr = new wxRadioBox(this, ID_RADIOBOX3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX3"));
	FlexGridSizer4->Add(m_RadioStMjDr, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	wxString __wxRadioBoxChoices_2[3] =
	{
		_("Apasa"),
		_("Ridica"),
		_("Ambele")
	};
	m_RadioApRiAm = new wxRadioBox(this, ID_RADIOBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_2, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX4"));
	m_RadioApRiAm->SetSelection(2);
	FlexGridSizer4->Add(m_RadioApRiAm, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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

	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&DialogEditorClick::Onm_CheckRandomClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditorClick::Onm_ButtonOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditorClick::Onm_ButtonCancelClick);
	Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&DialogEditorClick::OnTimer1Trigger);
	//*)



    m_X->Connect ( ID_SPINCTRL1, wxEVT_SET_FOCUS ,(wxObjectEventFunction)&DialogEditorClick::onFoc1,NULL, this );
    m_Y->Connect ( ID_SPINCTRL2, wxEVT_SET_FOCUS ,(wxObjectEventFunction)&DialogEditorClick::onFoc2,NULL, this );
    //m_X->Connect ( ID_SPINCTRL1, wxEVT_SET_FOCUS ,(wxObjectEventFunction)&DialogEditorClick::onFoc,NULL, this );
    //wxEVT_TEXT_CTRL


    m_X->Connect ( ID_SPINCTRL1, wxEVT_KEY_DOWN, wxKeyEventHandler ( DialogEditorClick::onm_KeyEmail ),NULL, this );
    m_Y->Connect ( ID_SPINCTRL2, wxEVT_KEY_DOWN, wxKeyEventHandler ( DialogEditorClick::onm_KeyPass ),NULL, this );

}

DialogEditorClick::~DialogEditorClick()
{
	//(*Destroy(DialogEditorClick)
	//*)
}


void DialogEditorClick::onm_KeyPass(wxKeyEvent& event)
{
    if(event.GetKeyCode()!=WXK_RETURN){event.Skip();return;}
    Onm_ButtonOKClick(wxCE);
}
void DialogEditorClick::onm_KeyEmail(wxKeyEvent& event)
{
    if(event.GetKeyCode()!=WXK_RETURN){event.Skip();return;}
    Onm_ButtonOKClick(wxCE);
}

void DialogEditorClick::onFoc1(wxFocusEvent& event)
{
     m_X->SetSelection(-1,-1);
     event.Skip();
}
void DialogEditorClick::onFoc2(wxFocusEvent& event)
{
     m_Y->SetSelection(-1,-1);
     event.Skip();
}

void DialogEditorClick::OnTimer1Trigger(wxTimerEvent& event)
{
    POINT p;
    GetCursorPos(&p);
    wxString ichar="";
    ichar<<"x: "<<p.x<<"   y:"<<p.y;
    StaticText5->SetLabel(ichar);

    Fit();
    Refresh();
    Layout();
}

void DialogEditorClick::Onm_ButtonCancelClick(wxCommandEvent& event)
{
    EndModal(0);
}

void DialogEditorClick::Onm_ButtonOKClick(wxCommandEvent& event)
{
    EndModal(1);
}

void DialogEditorClick::Onm_CheckRandomClick(wxCommandEvent& event)
{
    if(m_CheckRandom->GetValue()==1)
    {
        m_XMAX->Enable();
        m_YMAX->Enable();
        StaticText1->SetLabel("x min:");
        StaticText2->SetLabel("y min:");
    }
    else
    {
        m_XMAX->Disable();
        m_YMAX->Disable();
        StaticText1->SetLabel("x:");
        StaticText2->SetLabel("y:");
    }
}
