#include "DialogSettings.h"

//(*InternalHeaders(DialogSettings)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogSettings)
const long DialogSettings::ID_STATICTEXT1 = wxNewId();
const long DialogSettings::ID_TEXTCTRL1 = wxNewId();
const long DialogSettings::ID_STATICTEXT3 = wxNewId();
const long DialogSettings::ID_SPINCTRL1 = wxNewId();
const long DialogSettings::ID_STATICTEXT6 = wxNewId();
const long DialogSettings::ID_COMBOBOX1 = wxNewId();
const long DialogSettings::ID_STATICTEXT5 = wxNewId();
const long DialogSettings::ID_CHECKBOX2 = wxNewId();
const long DialogSettings::ID_STATICTEXT11 = wxNewId();
const long DialogSettings::ID_STATICTEXT2 = wxNewId();
const long DialogSettings::ID_CHECKBOX1 = wxNewId();
const long DialogSettings::ID_STATICTEXT10 = wxNewId();
const long DialogSettings::ID_SPINCTRL2 = wxNewId();
const long DialogSettings::ID_STATICTEXT13 = wxNewId();
const long DialogSettings::ID_STATICTEXT12 = wxNewId();
const long DialogSettings::ID_SPINCTRL3 = wxNewId();
const long DialogSettings::ID_STATICTEXT14 = wxNewId();
const long DialogSettings::ID_STATICTEXT4 = wxNewId();
const long DialogSettings::ID_CHECKBOX3 = wxNewId();
const long DialogSettings::ID_STATICTEXT7 = wxNewId();
const long DialogSettings::ID_CHECKBOX4 = wxNewId();
const long DialogSettings::ID_STATICTEXT8 = wxNewId();
const long DialogSettings::ID_CHECKBOX5 = wxNewId();
const long DialogSettings::ID_STATICTEXT9 = wxNewId();
const long DialogSettings::ID_CHECKBOX6 = wxNewId();
const long DialogSettings::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogSettings,wxDialog)
	//(*EventTable(DialogSettings)
	//*)
END_EVENT_TABLE()

DialogSettings::DialogSettings(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogSettings)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(2, 1, 0, 0);
	FlexGridSizer3 = new wxFlexGridSizer(11, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("ID Utilizator"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_UID = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(150,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	m_UID->Disable();
	FlexGridSizer3->Add(m_UID, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Asteptare (ms) intre comenzi"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer3->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_ExeWait = new wxSpinCtrl(this, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxSize(150,-1), 0, 0, 100000, 0, _T("ID_SPINCTRL1"));
	m_ExeWait->SetValue(_T("0"));
	FlexGridSizer3->Add(m_ExeWait, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Port COM pentru carduri"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer3->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_COM = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxSize(150,-1), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	FlexGridSizer3->Add(m_COM, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Cere parola la logare"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer3->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_AskPass = new wxCheckBox(this, ID_CHECKBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	m_AskPass->SetValue(true);
	FlexGridSizer3->Add(m_AskPass, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Threaduri"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	FlexGridSizer3->Add(StaticText11, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Stream imagine"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	m_TrimitePrint = new wxCheckBox(this, ID_CHECKBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	m_TrimitePrint->SetValue(true);
	FlexGridSizer4->Add(m_TrimitePrint, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer5 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Calitate"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	FlexGridSizer5->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Calitate = new wxSpinCtrl(this, ID_SPINCTRL2, _T("75"), wxDefaultPosition, wxDefaultSize, 0, 1, 100, 75, _T("ID_SPINCTRL2"));
	m_Calitate->SetValue(_T("75"));
	FlexGridSizer5->Add(m_Calitate, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("%"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	FlexGridSizer5->Add(StaticText13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("Viteza"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	FlexGridSizer5->Add(StaticText12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Viteza = new wxSpinCtrl(this, ID_SPINCTRL3, _T("2000"), wxDefaultPosition, wxDefaultSize, 0, 0, 4000, 2000, _T("ID_SPINCTRL3"));
	m_Viteza->SetValue(_T("2000"));
	FlexGridSizer5->Add(m_Viteza, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText14 = new wxStaticText(this, ID_STATICTEXT14, _("ms"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	FlexGridSizer5->Add(StaticText14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6->Add(FlexGridSizer5, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(FlexGridSizer6, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(FlexGridSizer4, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Comanda vocala"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer3->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_Voce = new wxCheckBox(this, ID_CHECKBOX3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	m_Voce->SetValue(true);
	FlexGridSizer3->Add(m_Voce, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Hotkeys"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer3->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_Hotkeys = new wxCheckBox(this, ID_CHECKBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
	m_Hotkeys->SetValue(true);
	FlexGridSizer3->Add(m_Hotkeys, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Planificari (Program)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer3->Add(StaticText8, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_Program = new wxCheckBox(this, ID_CHECKBOX5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
	m_Program->SetValue(true);
	FlexGridSizer3->Add(m_Program, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Card"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer3->Add(StaticText9, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_Card = new wxCheckBox(this, ID_CHECKBOX6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
	m_Card->SetValue(true);
	FlexGridSizer3->Add(m_Card, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(1, 1, 0, 0);
	Button1 = new wxButton(this, ID_BUTTON1, _("Salveaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogSettings::OnButton1Click);
	//*)
    this->SetPosition(wxPoint(GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));
}

DialogSettings::~DialogSettings()
{
	//(*Destroy(DialogSettings)
	//*)
}

#include <wx/msgdlg.h>
void DialogSettings::OnButton1Click(wxCommandEvent& event)
{
    EndModal(666);
}
