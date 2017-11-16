#include "DialogLogin.h"

//(*InternalHeaders(DialogLogin)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogLogin)
const long DialogLogin::ID_STATICTEXT1 = wxNewId();
const long DialogLogin::ID_STATICTEXT2 = wxNewId();
const long DialogLogin::ID_TEXTCTRL1 = wxNewId();
const long DialogLogin::ID_STATICTEXT3 = wxNewId();
const long DialogLogin::ID_TEXTCTRL2 = wxNewId();
const long DialogLogin::ID_STATICTEXT4 = wxNewId();
const long DialogLogin::ID_HYPERLINKCTRL1 = wxNewId();
const long DialogLogin::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogLogin,wxDialog)
	//(*EventTable(DialogLogin)
	//*)
END_EVENT_TABLE()

#include "Misc.h"
DialogLogin::DialogLogin(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogLogin)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
	SetBackgroundColour(wxColour(2,32,40));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Autentificare sau Inregistrare"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText1->SetForegroundColour(wxColour(255,255,255));
	wxFont StaticText1Font(14,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Trebuchet MS"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(5, 2, 0, 0);
	FlexGridSizer2->AddGrowableCol(0);
	FlexGridSizer2->AddGrowableCol(1);
	FlexGridSizer2->AddGrowableRow(3);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Email"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText2->SetForegroundColour(wxColour(255,255,255));
	wxFont StaticText2Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Trebuchet MS"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	FlexGridSizer2->Add(StaticText2, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_TextEmail = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer2->Add(m_TextEmail, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Parola"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText3->SetForegroundColour(wxColour(255,255,255));
	wxFont StaticText3Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Trebuchet MS"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	FlexGridSizer2->Add(StaticText3, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_TextPass = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxTE_PROCESS_ENTER|wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer2->Add(m_TextPass, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer3->Add(30,50,1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer3, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_TextError = new wxStaticText(this, ID_STATICTEXT4, _("Parola incorecta"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	m_TextError->SetForegroundColour(wxColour(255,0,0));
	wxFont m_TextErrorFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Trebuchet MS"),wxFONTENCODING_DEFAULT);
	m_TextError->SetFont(m_TextErrorFont);
	FlexGridSizer2->Add(m_TextError, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	HyperlinkCtrl1 = new wxHyperlinkCtrl(this, ID_HYPERLINKCTRL1, _("Am uitat parola"), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE|wxNO_BORDER, _T("ID_HYPERLINKCTRL1"));
	wxFont HyperlinkCtrl1Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Trebuchet MS"),wxFONTENCODING_DEFAULT);
	HyperlinkCtrl1->SetFont(HyperlinkCtrl1Font);
	FlexGridSizer2->Add(HyperlinkCtrl1, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 7);
	m_ButtonAuth = new wxButton(this, ID_BUTTON1, _("Login"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(m_ButtonAuth, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	Center();

	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&DialogLogin::Onm_TextPassText);
	Connect(ID_HYPERLINKCTRL1,wxEVT_COMMAND_HYPERLINK,(wxObjectEventFunction)&DialogLogin::OnHyperlinkCtrl1Click);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogLogin::Onm_ButtonAuthClick);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&DialogLogin::OnClose);
	Connect(wxEVT_KEY_UP,(wxObjectEventFunction)&DialogLogin::OnKeyUp);
	Connect(wxEVT_CHAR,(wxObjectEventFunction)&DialogLogin::OnChar);
	//*)
    m_TextError->Hide();
	if(ReadDatas(0)!="")
        m_TextPass->SetFocus();
	m_TextEmail->SetValue(ReadDatas(0));

    this->SetPosition(wxPoint(GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height) ));

 //   Connect(wxID_ANY,wxEVT_KEY_DOWN,(wxObjectEventFunction)&DialogLogin::Onm_ListKeyDown);

    m_TextEmail->Connect ( ID_TEXTCTRL1, wxEVT_KEY_DOWN, wxKeyEventHandler ( DialogLogin::onm_KeyEmail ),NULL, this );
    m_TextPass->Connect ( ID_TEXTCTRL2, wxEVT_KEY_DOWN, wxKeyEventHandler ( DialogLogin::onm_KeyPass ),NULL, this );


  //  m_TextEmail->SetFocus();
  //  m_TextEmail->SetSelection(-1,-1);
}

void DialogLogin::onm_KeyPass(wxKeyEvent& event)
{
    if(event.GetKeyCode()!=WXK_RETURN && event.GetKeyCode()!=WXK_NUMPAD_ENTER){event.Skip();return;}
    Onm_ButtonAuthClick(wxCE);
}
void DialogLogin::onm_KeyEmail(wxKeyEvent& event)
{
    if(event.GetKeyCode()!=WXK_RETURN && event.GetKeyCode()!=WXK_NUMPAD_ENTER){event.Skip();return;}
    Onm_ButtonAuthClick(wxCE);
}
DialogLogin::~DialogLogin()
{
	//(*Destroy(DialogLogin)
	//*)
}

#include "DialogGetCode.h"
void DialogLogin::Onm_ButtonAuthClick(wxCommandEvent& event)
{
    wxString ret=EncodePassword(m_TextPass->GetValue());
    int r=LogIn(m_TextEmail->GetValue().data().AsChar(),ret.data().AsChar());
    Log("code: ",r);
    if(r==1)
    {
        SaveDatas(m_TextEmail->GetValue().data().AsChar(),0);
        EndModal(666);
    }
    if(r==0)
    {
        wxMessageBox("IP invalid");
        EndModal(0);
    }
    if(r==3)
    {
        wxString temp=RandCode();
        wxString ichar="";
        ichar<<"-t "<<m_TextEmail->GetValue().data().AsChar()<<" -f teo2mircea@gmail.com -ssl -port 465 -auth -smtp smtp.gmail.com -sub Inregistrare -M ";
        ichar<<"\"Buna ziua! Va rugam sa folositi codul urmator: "<<temp.data().AsChar();
        ichar<<"\" -user youremail@gmail.com -pass yourpass ";
        Log(ichar);
        Execute("mailsend1.19.exe","0","1",ichar);


        DialogGetCode dialog(this);
        dialog.expected=temp;
        if(dialog.ShowModal()==666)
        {
            InsetUser(m_TextEmail->GetValue().data().AsChar(),ret.data().AsChar());
            SaveDatas(m_TextEmail->GetValue().data().AsChar(),0);
            EndModal(666);
        }
        else
        {
            EndModal(0);
        }
    }
    m_TextError->Show();
}
#include "DialogParolaNoua.h"
void DialogLogin::OnHyperlinkCtrl1Click(wxCommandEvent& event)
{
    DialogParolaNoua dialog(this);
    if(dialog.ShowModal()==666)
    {
        SaveDatas(dialog.m_TextEmail->GetValue().data().AsChar(),0);
        EndModal(666);
    }
}

void DialogLogin::OnClose(wxCloseEvent& event)
{
    EndModal(0);
}

void DialogLogin::OnChar(wxKeyEvent& event)
{

}

void DialogLogin::OnKeyUp(wxKeyEvent& event)
{

}

void DialogLogin::Onm_TextPassText(wxCommandEvent& event)
{

}
