#include "DialogEditorWebsite.h"

//(*InternalHeaders(DialogEditorWebsite)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogEditorWebsite)
const long DialogEditorWebsite::ID_STATICTEXT1 = wxNewId();
const long DialogEditorWebsite::ID_TEXTCTRL1 = wxNewId();
const long DialogEditorWebsite::ID_BUTTON1 = wxNewId();
const long DialogEditorWebsite::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogEditorWebsite,wxDialog)
	//(*EventTable(DialogEditorWebsite)
	//*)
END_EVENT_TABLE()

DialogEditorWebsite::DialogEditorWebsite(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogEditorWebsite)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Website"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Website:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Website = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer3->Add(m_Website, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditorWebsite::Onm_ButtonOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditorWebsite::Onm_ButtonCancelClick);
	//*)
}

DialogEditorWebsite::~DialogEditorWebsite()
{
	//(*Destroy(DialogEditorWebsite)
	//*)
}

#include <wx/msgdlg.h>
void DialogEditorWebsite::Onm_ButtonOKClick(wxCommandEvent& event)
{
    if(m_Website->GetValue().StartsWith("www.") || m_Website->GetValue().StartsWith("http://") || m_Website->GetValue().StartsWith("https://"))
        EndModal(1);
    else
        wxMessageBox("Trebuie sa inceapa cu www. sau http:// sau https://");
}

void DialogEditorWebsite::Onm_ButtonCancelClick(wxCommandEvent& event)
{
    EndModal(0);
}
