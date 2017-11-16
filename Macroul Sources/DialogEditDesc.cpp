#include "DialogEditDesc.h"

//(*InternalHeaders(DialogEditDesc)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogEditDesc)
const long DialogEditDesc::ID_STATICTEXT1 = wxNewId();
const long DialogEditDesc::ID_TEXTCTRL1 = wxNewId();
const long DialogEditDesc::ID_STATICTEXT2 = wxNewId();
const long DialogEditDesc::ID_TEXTCTRL2 = wxNewId();
const long DialogEditDesc::ID_STATICTEXT3 = wxNewId();
const long DialogEditDesc::ID_CHECKBOX1 = wxNewId();
const long DialogEditDesc::ID_BUTTON1 = wxNewId();
const long DialogEditDesc::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogEditDesc,wxDialog)
	//(*EventTable(DialogEditDesc)
	//*)
END_EVENT_TABLE()

DialogEditDesc::DialogEditDesc(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogEditDesc)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Nume"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_Nume = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer2->Add(m_Nume, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Descriere"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_Descriere = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer2->Add(m_Descriere, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Public"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer2->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_Public = new wxCheckBox(this, ID_CHECKBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	m_Public->SetValue(true);
	FlexGridSizer2->Add(m_Public, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
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

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditDesc::Onm_ButtonOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditDesc::Onm_ButtonCancelClick);
	//*)
}

DialogEditDesc::~DialogEditDesc()
{
	//(*Destroy(DialogEditDesc)
	//*)
}

#include "wx/msgdlg.h"
void DialogEditDesc::Onm_ButtonOKClick(wxCommandEvent& event)
{
    if(m_Nume->GetValue()=="")
    {
        wxMessageBox("Numele nu poate sa fie gol!");
    }
    else
    {
        EndModal(1);
    }
}
void DialogEditDesc::Onm_ButtonCancelClick(wxCommandEvent& event)
{
    EndModal(0);
}

