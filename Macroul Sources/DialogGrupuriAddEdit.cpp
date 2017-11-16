#include "DialogGrupuriAddEdit.h"

//(*InternalHeaders(DialogGrupuriAddEdit)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogGrupuriAddEdit)
const long DialogGrupuriAddEdit::ID_STATICTEXT1 = wxNewId();
const long DialogGrupuriAddEdit::ID_TEXTCTRL1 = wxNewId();
const long DialogGrupuriAddEdit::ID_CHECKLISTBOX1 = wxNewId();
const long DialogGrupuriAddEdit::ID_BUTTON1 = wxNewId();
const long DialogGrupuriAddEdit::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogGrupuriAddEdit,wxDialog)
	//(*EventTable(DialogGrupuriAddEdit)
	//*)
END_EVENT_TABLE()

DialogGrupuriAddEdit::DialogGrupuriAddEdit(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogGrupuriAddEdit)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableRow(1);
	FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Nume grup:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_Text = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	m_Text->SetMaxLength(50);
	FlexGridSizer2->Add(m_Text, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Check = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
	FlexGridSizer1->Add(m_Check, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	m_ButtonOK = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(m_ButtonOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonCancel = new wxButton(this, ID_BUTTON2, _("Anuleaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer3->Add(m_ButtonCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogGrupuriAddEdit::Onm_ButtonOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogGrupuriAddEdit::Onm_ButtonCancelClick);
	//*)
}

DialogGrupuriAddEdit::~DialogGrupuriAddEdit()
{
	//(*Destroy(DialogGrupuriAddEdit)
	//*)
}

#include "wx/msgdlg.h"
void DialogGrupuriAddEdit::Onm_ButtonOKClick(wxCommandEvent& event)
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

void DialogGrupuriAddEdit::Onm_ButtonCancelClick(wxCommandEvent& event)
{

    EndModal(0);
}
