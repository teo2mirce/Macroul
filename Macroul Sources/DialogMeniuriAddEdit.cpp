#include "DialogMeniuriAddEdit.h"

//(*InternalHeaders(DialogMeniuriAddEdit)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogMeniuriAddEdit)
const long DialogMeniuriAddEdit::ID_STATICTEXT1 = wxNewId();
const long DialogMeniuriAddEdit::ID_TEXTCTRL1 = wxNewId();
const long DialogMeniuriAddEdit::ID_CHOICE1 = wxNewId();
const long DialogMeniuriAddEdit::ID_CHOICE2 = wxNewId();
const long DialogMeniuriAddEdit::ID_CHOICE3 = wxNewId();
const long DialogMeniuriAddEdit::ID_CHOICE4 = wxNewId();
const long DialogMeniuriAddEdit::ID_CHOICE5 = wxNewId();
const long DialogMeniuriAddEdit::ID_CHOICE6 = wxNewId();
const long DialogMeniuriAddEdit::ID_CHOICE7 = wxNewId();
const long DialogMeniuriAddEdit::ID_CHOICE8 = wxNewId();
const long DialogMeniuriAddEdit::ID_CHOICE9 = wxNewId();
const long DialogMeniuriAddEdit::ID_BUTTON1 = wxNewId();
const long DialogMeniuriAddEdit::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogMeniuriAddEdit,wxDialog)
	//(*EventTable(DialogMeniuriAddEdit)
	//*)
END_EVENT_TABLE()

DialogMeniuriAddEdit::DialogMeniuriAddEdit(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogMeniuriAddEdit)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(1);
	FlexGridSizer2 = new wxFlexGridSizer(1, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Nume meniu:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_Text = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	m_Text->SetMaxLength(50);
	FlexGridSizer2->Add(m_Text, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(3, 3, 0, 0);
	FlexGridSizer4->AddGrowableCol(0);
	FlexGridSizer4->AddGrowableCol(1);
	FlexGridSizer4->AddGrowableCol(2);
	FlexGridSizer4->AddGrowableRow(0);
	FlexGridSizer4->AddGrowableRow(1);
	FlexGridSizer4->AddGrowableRow(2);
	Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	FlexGridSizer4->Add(Choice1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice2 = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	FlexGridSizer4->Add(Choice2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice3 = new wxChoice(this, ID_CHOICE3, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	FlexGridSizer4->Add(Choice3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice4 = new wxChoice(this, ID_CHOICE4, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
	FlexGridSizer4->Add(Choice4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice5 = new wxChoice(this, ID_CHOICE5, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
	FlexGridSizer4->Add(Choice5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice6 = new wxChoice(this, ID_CHOICE6, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE6"));
	FlexGridSizer4->Add(Choice6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice7 = new wxChoice(this, ID_CHOICE7, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE7"));
	FlexGridSizer4->Add(Choice7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice8 = new wxChoice(this, ID_CHOICE8, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE8"));
	FlexGridSizer4->Add(Choice8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice9 = new wxChoice(this, ID_CHOICE9, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE9"));
	FlexGridSizer4->Add(Choice9, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer4, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(1, 2, 0, 0);
	m_ButtonOK = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(m_ButtonOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonCancel = new wxButton(this, ID_BUTTON2, _("Anuleaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer3->Add(m_ButtonCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogMeniuriAddEdit::Onm_ButtonOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogMeniuriAddEdit::Onm_ButtonCancelClick);
	//*)
    this->SetPosition(wxPoint(GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));

	//this->Layout();
	//this->Fit();
}

DialogMeniuriAddEdit::~DialogMeniuriAddEdit()
{
	//(*Destroy(DialogMeniuriAddEdit)
	//*)
}

#include "wx/msgdlg.h"

void DialogMeniuriAddEdit::Onm_ButtonOKClick(wxCommandEvent& event)
{
    if(m_Text->GetValue()=="")
    {
        wxMessageBox("Numele nu poate sa fie gol!");
    }
    else
    {
        EndModal(1);
    }
}

void DialogMeniuriAddEdit::Onm_ButtonCancelClick(wxCommandEvent& event)
{
    EndModal(0);
}
