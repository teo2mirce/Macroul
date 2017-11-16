#include "DialogEditorEmail.h"

//(*InternalHeaders(DialogEditorEmail)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogEditorEmail)
const long DialogEditorEmail::ID_STATICTEXT1 = wxNewId();
const long DialogEditorEmail::ID_TEXTCTRL1 = wxNewId();
const long DialogEditorEmail::ID_STATICTEXT2 = wxNewId();
const long DialogEditorEmail::ID_TEXTCTRL2 = wxNewId();
const long DialogEditorEmail::ID_BUTTON1 = wxNewId();
const long DialogEditorEmail::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogEditorEmail,wxDialog)
	//(*EventTable(DialogEditorEmail)
	//*)
END_EVENT_TABLE()

DialogEditorEmail::DialogEditorEmail(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogEditorEmail)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Email"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Email:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_Email = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer3->Add(m_Email, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Mesaj:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_Text = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(200,100), wxTE_PROCESS_ENTER|wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer3->Add(m_Text, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	m_ButtonOK = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(m_ButtonOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonCancel = new wxButton(this, ID_BUTTON2, _("Anuleaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer2->Add(m_ButtonCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditorEmail::Onm_ButtonOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditorEmail::Onm_ButtonCancelClick);
	//*)
}

DialogEditorEmail::~DialogEditorEmail()
{
	//(*Destroy(DialogEditorEmail)
	//*)
}

#include <wx/msgdlg.h>
void DialogEditorEmail::Onm_ButtonOKClick(wxCommandEvent& event)
{
    if(m_Email->GetValue().Find(',')!=wxNOT_FOUND)
    {
        wxMessageBox("Fara virgule in email!");
        return;
    }
    if(m_Text->GetValue().Find('"')!=wxNOT_FOUND)
    {
        wxMessageBox("Fara \" in email!");
        return;
    }
    if(m_Text->GetValue().Find('\\')!=wxNOT_FOUND)
    {
        wxMessageBox("Fara \\ in email!");
        return;
    }
    EndModal(1);
}

void DialogEditorEmail::Onm_ButtonCancelClick(wxCommandEvent& event)
{
    EndModal(0);
}





