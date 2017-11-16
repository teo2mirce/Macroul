#include "DialogActivator.h"

//(*InternalHeaders(DialogActivator)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogActivator)
const long DialogActivator::ID_CHECKBOX1 = wxNewId();
const long DialogActivator::ID_TEXTCTRL1 = wxNewId();
const long DialogActivator::ID_BUTTON1 = wxNewId();
const long DialogActivator::ID_STATICLINE1 = wxNewId();
const long DialogActivator::ID_CHECKBOX2 = wxNewId();
const long DialogActivator::ID_TEXTCTRL2 = wxNewId();
const long DialogActivator::ID_BUTTON3 = wxNewId();
const long DialogActivator::ID_STATICLINE2 = wxNewId();
const long DialogActivator::ID_CHECKBOX3 = wxNewId();
const long DialogActivator::ID_DATEPICKERCTRL1 = wxNewId();
const long DialogActivator::ID_CUSTOM1 = wxNewId();
const long DialogActivator::ID_BUTTON4 = wxNewId();
const long DialogActivator::ID_STATICLINE3 = wxNewId();
const long DialogActivator::ID_CHECKBOX4 = wxNewId();
const long DialogActivator::ID_TEXTCTRL4 = wxNewId();
const long DialogActivator::ID_BUTTON5 = wxNewId();
const long DialogActivator::ID_STATICLINE4 = wxNewId();
const long DialogActivator::ID_STATICTEXT1 = wxNewId();
const long DialogActivator::ID_SPINCTRL1 = wxNewId();
const long DialogActivator::ID_BUTTON2 = wxNewId();
const long DialogActivator::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogActivator,wxDialog)
	//(*EventTable(DialogActivator)
	//*)
END_EVENT_TABLE()
#include <wx/timectrl.h>
DialogActivator::DialogActivator(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogActivator)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer9;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer7;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer2->AddGrowableCol(0);
	FlexGridSizer5 = new wxFlexGridSizer(0, 4, 0, 0);
	FlexGridSizer5->AddGrowableCol(2);
	m_CheckVoce = new wxCheckBox(this, ID_CHECKBOX1, _("Voce"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	m_CheckVoce->SetValue(false);
	FlexGridSizer5->Add(m_CheckVoce, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_VoiceText = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(250,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	m_VoiceText->Disable();
	FlexGridSizer5->Add(m_VoiceText, 1, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	m_Inregistreaza = new wxButton(this, ID_BUTTON1, _("Inregistreaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer5->Add(m_Inregistreaza, 1, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	FlexGridSizer2->Add(StaticLine1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6 = new wxFlexGridSizer(0, 6, 0, 0);
	FlexGridSizer6->AddGrowableCol(2);
	m_CheckTaste = new wxCheckBox(this, ID_CHECKBOX2, _("Taste"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	m_CheckTaste->SetValue(false);
	FlexGridSizer6->Add(m_CheckTaste, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Tastatura = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(250,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	m_Tastatura->Disable();
	FlexGridSizer6->Add(m_Tastatura, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonTastatura = new wxButton(this, ID_BUTTON3, _("Scaneaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer6->Add(m_ButtonTastatura, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	FlexGridSizer2->Add(StaticLine2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 4, 0, 0);
	FlexGridSizer3->AddGrowableCol(1);
	FlexGridSizer3->AddGrowableCol(2);
	m_CheckProgram = new wxCheckBox(this, ID_CHECKBOX3, _("Program"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	m_CheckProgram->SetValue(false);
	FlexGridSizer3->Add(m_CheckProgram, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_DatePicker = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxSize(100,21), wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
	FlexGridSizer3->Add(m_DatePicker, 1, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	m_TimePicker = new wxTimePickerCtrl(this,ID_CUSTOM1,wxDefaultDateTime,wxDefaultPosition,wxSize(100,21),wxDP_DEFAULT,wxDefaultValidator,_T("ID_CUSTOM1"));
	FlexGridSizer3->Add(m_TimePicker, 1, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	m_Button10 = new wxButton(this, ID_BUTTON4, _("peste 10 minute"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	FlexGridSizer3->Add(m_Button10, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine3 = new wxStaticLine(this, ID_STATICLINE3, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
	FlexGridSizer2->Add(StaticLine3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7 = new wxFlexGridSizer(0, 4, 0, 0);
	FlexGridSizer7->AddGrowableCol(1);
	m_CheckCard = new wxCheckBox(this, ID_CHECKBOX4, _("Card"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
	m_CheckCard->SetValue(false);
	FlexGridSizer7->Add(m_CheckCard, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_CardCode = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	m_CardCode->Disable();
	FlexGridSizer7->Add(m_CardCode, 1, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonScan = new wxButton(this, ID_BUTTON5, _("Scaneaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	FlexGridSizer7->Add(m_ButtonScan, 1, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine4 = new wxStaticLine(this, ID_STATICLINE4, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE4"));
	FlexGridSizer2->Add(StaticLine4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer9 = new wxFlexGridSizer(0, 4, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Numar de repetitii la activare"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer9->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Times = new wxSpinCtrl(this, ID_SPINCTRL1, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 100000, 1, _T("ID_SPINCTRL1"));
	m_Times->SetValue(_T("1"));
	FlexGridSizer9->Add(m_Times, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer9, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	m_ButtonSave = new wxButton(this, ID_BUTTON2, _("Salveaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer4->Add(m_ButtonSave, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	Timer1.SetOwner(this, ID_TIMER1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogActivator::Onm_InregistreazaClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogActivator::Onm_ButtonTastaturaClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogActivator::Onm_Button10Click);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogActivator::Onm_ButtonScanClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogActivator::Onm_ButtonSaveClick);
	Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&DialogActivator::OnTimer1Trigger);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&DialogActivator::OnClose);
	//*)

//	m_TimePicker = new wxDateTimePickerCtrl(this);
//	FlexGridSizer3->Add(m_TimePicker, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
//    MSWCreateDateTimePicker(this);
    keyStatus=false;
}

DialogActivator::~DialogActivator()
{
	//(*Destroy(DialogActivator)
	//*)
}
#include <fstream>
using namespace std;

#include "Misc.h"
void DialogActivator::Onm_ButtonSaveClick(wxCommandEvent& event)
{
    if(m_CheckVoce->GetValue())
        if(m_VoiceText->GetValue().IsEmpty())
        {
            wxMessageBox("Trebuie sa existe o inregistrare");
            return;
        }
    if(m_CheckTaste->GetValue())
        if(m_Tastatura->GetValue().IsEmpty())
        {
            wxMessageBox("Trebuie sa existe o combinatie de taste");
            return;
        }
    if(m_CheckCard->GetValue())
        if(m_CardCode->GetValue().IsEmpty())
        {
            wxMessageBox("Trebuie sa existe un cod pentru card");
            return;
        }
    if(keyStatus==true)
    {
        wxMessageBox("Trebuie sa opresti scanarea tastelor");
        return;
    }
    //initTriggers();


    EndModal(666);
}
void DialogActivator::Onm_ButtonScanClick(wxCommandEvent& event)
{
    this->SetCursor(wxCursor(wxCURSOR_WAIT));
    wxString ichar="";
    unsigned long long x = CardReader();
    unsigned long long y = -1;
    if(x==y)
        m_CardCode->SetValue("Verificati setarile si repetati");
    else
    {
        ichar<<x;
        m_CardCode->SetValue(ichar);
    }
    this->SetCursor(wxCursor(*wxSTANDARD_CURSOR));
}
#include <wx/textfile.h>
#include <wx/filename.h>
void DialogActivator::Onm_InregistreazaClick(wxCommandEvent& event)
{
    this->SetCursor(wxCursor(wxCURSOR_WAIT));
    remove("workfile");
    Execute("spici\\spici.exe","1","1","ro-RO");
    wxTextFile f;
    if(wxFileName::FileExists("workfile")==false)
    {
        m_VoiceText->SetValue("");
        this->SetCursor(wxCursor(*wxSTANDARD_CURSOR));
        return;
    }
    f.Open("workfile");
    wxString temp=f.GetLine(0);
    f.Close();
    m_VoiceText->SetValue(temp);
    remove("workfile");
    this->SetCursor(wxCursor(*wxSTANDARD_CURSOR));
}
#include "huk.h"
void DialogActivator::Onm_ButtonTastaturaClick(wxCommandEvent& event)
{
    if(keyStatus==false)
    {
        MyHook::Instance().InstallHook();
        m_ButtonTastatura->SetLabel("Opreste");
        Timer1.Start(10);
        keyStatus=true;
    }
    else
    {
        keyStatus=false;
        MyHook::Instance().UninstallHook();
        Timer1.Stop();
        m_ButtonTastatura->SetLabel("Scaneaza");
    }
}
void DialogActivator::OnTimer1Trigger(wxTimerEvent& event)
{
    Timer1.Stop();
    MyHook::Instance().Messsages();
    m_Tastatura->SetValue(whatToShow);
    Timer1.Start(30);
}

void DialogActivator::OnClose(wxCloseEvent& event)
{
    EndModal(0);
}

void DialogActivator::Onm_Button10Click(wxCommandEvent& event)
{
    time_t temp=wxDateTime::Now().GetTicks()+10*60;
    wxDateTime DT;
    DT.Set(temp);
    m_TimePicker->SetTime(DT.GetHour(),DT.GetMinute(),DT.GetSecond());
    m_DatePicker->SetValue(DT);
}
