#include "DialogVariabila.h"

//(*InternalHeaders(DialogVariabila)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogVariabila)
const long DialogVariabila::ID_RADIOBOX1 = wxNewId();
const long DialogVariabila::ID_STATICTEXT4 = wxNewId();
const long DialogVariabila::ID_TEXTCTRL4 = wxNewId();
const long DialogVariabila::ID_STATICTEXT3 = wxNewId();
const long DialogVariabila::ID_TEXTCTRL3 = wxNewId();
const long DialogVariabila::ID_BUTTON1 = wxNewId();
const long DialogVariabila::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogVariabila,wxDialog)
	//(*EventTable(DialogVariabila)
	//*)
END_EVENT_TABLE()

DialogVariabila::DialogVariabila(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogVariabila)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableRow(1);
	FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
	wxString __wxRadioBoxChoices_1[3] =
	{
		_("Text"),
		_("Variabila simpla"),
		_("Variabila multipla")
	};
	m_Radio = new wxRadioBox(this, ID_RADIOBOX1, _("Tip"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
	m_Radio->SetSelection(0);
	FlexGridSizer2->Add(m_Radio, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
	m_LabelText = new wxStaticText(this, ID_STATICTEXT4, _("Text"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer4->Add(m_LabelText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Text = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	FlexGridSizer4->Add(m_Text, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_LabelSeparator = new wxStaticText(this, ID_STATICTEXT3, _("Separator"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	m_LabelSeparator->Hide();
	FlexGridSizer4->Add(m_LabelSeparator, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Separator = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	m_Separator->Hide();
	FlexGridSizer4->Add(m_Separator, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	m_ButtonOK = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(m_ButtonOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonCancel = new wxButton(this, ID_BUTTON2, _("Anuleaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer3->Add(m_ButtonCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&DialogVariabila::Onm_RadioTipSelect);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogVariabila::Onm_ButtonOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogVariabila::Onm_ButtonCancelClick);
	//*)
}

DialogVariabila::~DialogVariabila()
{
	//(*Destroy(DialogVariabila)
	//*)
}


void DialogVariabila::Onm_ButtonOKClick(wxCommandEvent& event)
{
    EndModal(1);
}

void DialogVariabila::Onm_ButtonCancelClick(wxCommandEvent& event)
{
    EndModal(0);
}

void DialogVariabila::Onm_RadioTipSelect(wxCommandEvent& event)
{
    if(m_Radio->GetSelection()==0)
    {
        m_LabelText->SetLabel("Text");
        m_Separator->Show(false);
        m_LabelSeparator->Show(false);
    }
    if(m_Radio->GetSelection()==1)
    {
        m_LabelText->SetLabel("Variabila");
        m_Separator->Show(false);
        m_LabelSeparator->Show(false);
    }
    if(m_Radio->GetSelection()==2)
    {
        m_LabelText->SetLabel("Variabila");
        m_Separator->Show(true);
        m_LabelSeparator->Show(true);
    }
    Fit();
    Refresh();
    Layout();
}



