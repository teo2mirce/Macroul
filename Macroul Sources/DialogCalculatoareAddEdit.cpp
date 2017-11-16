#include "DialogCalculatoareAddEdit.h"

//(*InternalHeaders(DialogCalculatoareAddEdit)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogCalculatoareAddEdit)
const long DialogCalculatoareAddEdit::ID_STATICTEXT1 = wxNewId();
const long DialogCalculatoareAddEdit::ID_TEXTCTRL1 = wxNewId();
const long DialogCalculatoareAddEdit::ID_BUTTON1 = wxNewId();
const long DialogCalculatoareAddEdit::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogCalculatoareAddEdit,wxDialog)
	//(*EventTable(DialogCalculatoareAddEdit)
	//*)
END_EVENT_TABLE()

DialogCalculatoareAddEdit::DialogCalculatoareAddEdit(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogCalculatoareAddEdit)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Nume calculator:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_Text = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	m_Text->SetMaxLength(50);
	FlexGridSizer2->Add(m_Text, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	m_ButtonOK = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(m_ButtonOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonCancel = new wxButton(this, ID_BUTTON2, _("Anuleaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer3->Add(m_ButtonCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogCalculatoareAddEdit::Onm_ButtonOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogCalculatoareAddEdit::Onm_ButtonCancelClick);
	//*)
    this->Layout();
    this->Fit();
    this->SetPosition(wxPoint(GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));

}

DialogCalculatoareAddEdit::~DialogCalculatoareAddEdit()
{
	//(*Destroy(DialogCalculatoareAddEdit)
	//*)
}


#include "wx/msgdlg.h"
void DialogCalculatoareAddEdit::Onm_ButtonOKClick(wxCommandEvent& event)
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

void DialogCalculatoareAddEdit::Onm_ButtonCancelClick(wxCommandEvent& event)
{
    EndModal(0);
}
