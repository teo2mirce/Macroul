#include "DialogEditorAsteapta.h"

//(*InternalHeaders(DialogEditorAsteapta)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogEditorAsteapta)
const long DialogEditorAsteapta::ID_RADIOBOX4 = wxNewId();
const long DialogEditorAsteapta::ID_RADIOBOX1 = wxNewId();
const long DialogEditorAsteapta::ID_STATICTEXT1 = wxNewId();
const long DialogEditorAsteapta::ID_TEXTCTRL1 = wxNewId();
const long DialogEditorAsteapta::ID_STATICTEXT2 = wxNewId();
const long DialogEditorAsteapta::ID_SPINCTRL1 = wxNewId();
const long DialogEditorAsteapta::ID_STATICTEXT3 = wxNewId();
const long DialogEditorAsteapta::ID_SPINCTRL2 = wxNewId();
const long DialogEditorAsteapta::ID_STATICTEXT5 = wxNewId();
const long DialogEditorAsteapta::ID_STATICTEXT6 = wxNewId();
const long DialogEditorAsteapta::ID_SPINCTRL3 = wxNewId();
const long DialogEditorAsteapta::ID_STATICTEXT7 = wxNewId();
const long DialogEditorAsteapta::ID_SPINCTRL4 = wxNewId();
const long DialogEditorAsteapta::ID_STATICTEXT8 = wxNewId();
const long DialogEditorAsteapta::ID_SPINCTRL5 = wxNewId();
const long DialogEditorAsteapta::ID_STATICTEXT4 = wxNewId();
const long DialogEditorAsteapta::ID_BUTTON1 = wxNewId();
const long DialogEditorAsteapta::ID_BUTTON2 = wxNewId();
const long DialogEditorAsteapta::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogEditorAsteapta,wxDialog)
	//(*EventTable(DialogEditorAsteapta)
	//*)
END_EVENT_TABLE()

DialogEditorAsteapta::DialogEditorAsteapta(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogEditorAsteapta)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer10;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer9;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Asteapta"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer4 = new wxFlexGridSizer(0, 4, 0, 0);
	FlexGridSizer10 = new wxFlexGridSizer(0, 1, 0, 0);
	wxString __wxRadioBoxChoices_1[3] =
	{
		_("Proces"),
		_("Fereastra"),
		_("Pixel")
	};
	m_Radio = new wxRadioBox(this, ID_RADIOBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX4"));
	m_Radio->SetSelection(0);
	FlexGridSizer10->Add(m_Radio, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	wxString __wxRadioBoxChoices_2[2] =
	{
		_("Asteapta sa apara"),
		_("Asteapta sa dispara")
	};
	RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_2, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
	RadioBox1->SetSelection(0);
	FlexGridSizer10->Add(RadioBox1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(FlexGridSizer10, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer5 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Nume:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer5->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Text = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(250,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer5->Add(m_Text, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(FlexGridSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer6 = new wxFlexGridSizer(3, 4, 0, 0);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("x: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer6->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_X = new wxSpinCtrl(this, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxDefaultSize, 0, -5000, 5000, 0, _T("ID_SPINCTRL1"));
	m_X->SetValue(_T("0"));
	FlexGridSizer6->Add(m_X, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("y:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer6->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Y = new wxSpinCtrl(this, ID_SPINCTRL2, _T("0"), wxDefaultPosition, wxDefaultSize, 0, -5000, 5000, 0, _T("ID_SPINCTRL2"));
	m_Y->SetValue(_T("0"));
	FlexGridSizer6->Add(m_Y, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7->Add(FlexGridSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("hue"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer7->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(FlexGridSizer7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer8 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer9 = new wxFlexGridSizer(3, 2, 0, 0);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("r: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer9->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrl1 = new wxSpinCtrl(this, ID_SPINCTRL3, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 255, 0, _T("ID_SPINCTRL3"));
	SpinCtrl1->SetValue(_T("0"));
	FlexGridSizer9->Add(SpinCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("g:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer9->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrl2 = new wxSpinCtrl(this, ID_SPINCTRL4, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 255, 0, _T("ID_SPINCTRL4"));
	SpinCtrl2->SetValue(_T("0"));
	FlexGridSizer9->Add(SpinCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("b:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer9->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SpinCtrl3 = new wxSpinCtrl(this, ID_SPINCTRL5, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 255, 0, _T("ID_SPINCTRL5"));
	SpinCtrl3->SetValue(_T("0"));
	FlexGridSizer9->Add(SpinCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer8->Add(FlexGridSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("hue"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer8->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(FlexGridSizer8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(FlexGridSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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

	Connect(ID_RADIOBOX4,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&DialogEditorAsteapta::Onm_RadioSelect);
	Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&DialogEditorAsteapta::OnRadioBox1Select);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditorAsteapta::Onm_ButtonOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditorAsteapta::Onm_ButtonCancelClick);
	Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&DialogEditorAsteapta::OnTimer1Trigger);
	//*)

    FlexGridSizer5->Show(true);
    FlexGridSizer7->Show(false);
    FlexGridSizer8->Show(false);
}

DialogEditorAsteapta::~DialogEditorAsteapta()
{
	//(*Destroy(DialogEditorAsteapta)
	//*)
}


void DialogEditorAsteapta::Onm_ButtonOKClick(wxCommandEvent& event)
{
    EndModal(1);
}

void DialogEditorAsteapta::Onm_ButtonCancelClick(wxCommandEvent& event)
{
    EndModal(0);
}

void DialogEditorAsteapta::OnTimer1Trigger(wxTimerEvent& event)
{
    POINT p;
    GetCursorPos(&p);
    wxString ichar="";
    ichar<<"("<<p.x<<","<<p.y<<")";
    StaticText5->SetLabel(ichar);
    ichar="";


    HDC dc = GetDC(NULL);
    COLORREF color = GetPixel(dc, p.x, p.y);
    ReleaseDC(NULL, dc);
    ichar<<"RGB("<<(int)GetRValue(color)<<","<<(int)GetGValue(color)<<","<<(int)GetBValue(color)<<")";
    StaticText4->SetLabel(ichar);

    Fit();
    Refresh();
    Layout();
}

void DialogEditorAsteapta::Onm_RadioSelect(wxCommandEvent& event)
{
    if(m_Radio->GetSelection()<2)
    {
        FlexGridSizer5->Show(true);
        FlexGridSizer7->Show(false);
        FlexGridSizer8->Show(false);
        RadioBox1->SetString(1,"Asteapta sa dispara");
    }
    else
    {
        FlexGridSizer5->Show(false);
        FlexGridSizer7->Show(true);
        FlexGridSizer8->Show(true);
        RadioBox1->SetSelection(0);
        RadioBox1->SetString(1,"Asteapta sa se schimbe");
    }
}

void DialogEditorAsteapta::OnRadioBox1Select(wxCommandEvent& event)
{
    if(m_Radio->GetSelection()==2)
    {
        if(RadioBox1->GetSelection()==0)
            FlexGridSizer8->Show(true);
        else
            FlexGridSizer8->Show(false);
    }
}
