#include "DialogEditoroExecute.h"

//(*InternalHeaders(DialogEditoroExecute)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogEditoroExecute)
const long DialogEditoroExecute::ID_STATICTEXT2 = wxNewId();
const long DialogEditoroExecute::ID_FILEPICKERCTRL1 = wxNewId();
const long DialogEditoroExecute::ID_STATICTEXT1 = wxNewId();
const long DialogEditoroExecute::ID_TEXTCTRL1 = wxNewId();
const long DialogEditoroExecute::ID_CHECKBOX1 = wxNewId();
const long DialogEditoroExecute::ID_CHECKBOX2 = wxNewId();
const long DialogEditoroExecute::ID_BUTTON1 = wxNewId();
const long DialogEditoroExecute::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogEditoroExecute,wxDialog)
	//(*EventTable(DialogEditoroExecute)
	//*)
END_EVENT_TABLE()

DialogEditoroExecute::DialogEditoroExecute(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogEditoroExecute)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Executa"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	FlexGridSizer3->AddGrowableCol(1);
	FlexGridSizer3->AddGrowableRow(0);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Fisier"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_File = new wxFilePickerCtrl(this, ID_FILEPICKERCTRL1, wxEmptyString, wxEmptyString, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN|wxFLP_USE_TEXTCTRL, wxDefaultValidator, _T("ID_FILEPICKERCTRL1"));
	FlexGridSizer3->Add(m_File, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Argumente:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_Arguments = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(300,50), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer3->Add(m_Arguments, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Ascunde = new wxCheckBox(this, ID_CHECKBOX1, _("Ascunde"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	m_Ascunde->SetValue(false);
	FlexGridSizer3->Add(m_Ascunde, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_Asteapta = new wxCheckBox(this, ID_CHECKBOX2, _("Asteapta terminarea executarii"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	m_Asteapta->SetValue(false);
	FlexGridSizer3->Add(m_Asteapta, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	m_ButtonOK = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(m_ButtonOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonCancel = new wxButton(this, ID_BUTTON2, _("Anuleaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer2->Add(m_ButtonCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditoroExecute::Onm_ButtonOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditoroExecute::Onm_ButtonCancelClick);
	//*)
}

DialogEditoroExecute::~DialogEditoroExecute()
{
	//(*Destroy(DialogEditoroExecute)
	//*)
}


void DialogEditoroExecute::Onm_ButtonCancelClick(wxCommandEvent& event)
{
    EndModal(0);
}
#include <wx/msgdlg.h>
void DialogEditoroExecute::Onm_ButtonOKClick(wxCommandEvent& event)
{
    if(m_File->GetPath().Find(',')!=wxNOT_FOUND)
    {
        wxMessageBox("Fara virgule in adresa!");
        return;
    }
    EndModal(1);
}
