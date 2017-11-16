#include "DialogParolaNoua.h"

//(*InternalHeaders(DialogParolaNoua)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogParolaNoua)
const long DialogParolaNoua::ID_STATICTEXT1 = wxNewId();
const long DialogParolaNoua::ID_STATICTEXT2 = wxNewId();
const long DialogParolaNoua::ID_TEXTCTRL1 = wxNewId();
const long DialogParolaNoua::ID_STATICTEXT3 = wxNewId();
const long DialogParolaNoua::ID_TEXTCTRL2 = wxNewId();
const long DialogParolaNoua::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogParolaNoua,wxDialog)
	//(*EventTable(DialogParolaNoua)
	//*)
END_EVENT_TABLE()

DialogParolaNoua::DialogParolaNoua(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogParolaNoua)
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(5, 2, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableCol(1);
	FlexGridSizer1->AddGrowableRow(3);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Schimbare Parola"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Email"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_TextEmail = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(150,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer1->Add(m_TextEmail, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Parola noua"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_TextPass = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(150,-1), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer1->Add(m_TextPass, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonAuth = new wxButton(this, ID_BUTTON1, _("Schimba parola"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer1->Add(m_ButtonAuth, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogParolaNoua::Onm_ButtonAuthClick);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&DialogParolaNoua::OnClose);
	//*)
}

DialogParolaNoua::~DialogParolaNoua()
{
	//(*Destroy(DialogParolaNoua)
	//*)
}
#include "Misc.h"
#include "DialogGetCode.h"

void DialogParolaNoua::Onm_ButtonAuthClick(wxCommandEvent& event)
{
    wxString ret=EncodePassword(m_TextPass->GetValue());



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
        UpdateUser(m_TextEmail->GetValue().data().AsChar(),ret.data().AsChar());
        EndModal(666);
    }
    else
        EndModal(0);
}

void DialogParolaNoua::OnClose(wxCloseEvent& event)
{
    EndModal(0);
}
