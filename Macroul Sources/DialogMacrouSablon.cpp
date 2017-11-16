#include "DialogMacrouSablon.h"

//(*InternalHeaders(DialogMacrouSablon)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogMacrouSablon)
const long DialogMacrouSablon::ID_RADIOBOX4 = wxNewId();
const long DialogMacrouSablon::ID_STATICTEXT2 = wxNewId();
const long DialogMacrouSablon::ID_CHOICE1 = wxNewId();
const long DialogMacrouSablon::ID_STATICTEXT1 = wxNewId();
const long DialogMacrouSablon::ID_TEXTCTRL1 = wxNewId();
const long DialogMacrouSablon::ID_BUTTON1 = wxNewId();
const long DialogMacrouSablon::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogMacrouSablon,wxDialog)
	//(*EventTable(DialogMacrouSablon)
	//*)
END_EVENT_TABLE()

DialogMacrouSablon::DialogMacrouSablon(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogMacrouSablon)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	wxString __wxRadioBoxChoices_1[2] =
	{
		_("Macrou"),
		_("Sablon")
	};
	m_Radio = new wxRadioBox(this, ID_RADIOBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX4"));
	FlexGridSizer4->Add(m_Radio, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	m_MT = new wxStaticText(this, ID_STATICTEXT2, _("Macrou:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer3->Add(m_MT, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Macrou = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(250,22), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	FlexGridSizer3->Add(m_Macrou, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ST = new wxStaticText(this, ID_STATICTEXT1, _("Sablon:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer3->Add(m_ST, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Sablon = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(250,22), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer3->Add(m_Sablon, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(FlexGridSizer3, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	m_ButtonOK = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(m_ButtonOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonCancel = new wxButton(this, ID_BUTTON2, _("Anuleaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer2->Add(m_ButtonCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_RADIOBOX4,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&DialogMacrouSablon::Onm_RadioSelect);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogMacrouSablon::Onm_ButtonOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogMacrouSablon::Onm_ButtonCancelClick);
	//*)
}

DialogMacrouSablon::~DialogMacrouSablon()
{
	//(*Destroy(DialogMacrouSablon)
	//*)
}

#include <wx/msgdlg.h>
void DialogMacrouSablon::Onm_ButtonOKClick(wxCommandEvent& event)
{
    if(m_Radio->GetSelection()==0 && m_Macrou->GetSelection()<0)
    {
        wxMessageBox("Trebuie sa alegi ceva");
        return;
    }
    EndModal(1);
}

void DialogMacrouSablon::Onm_ButtonCancelClick(wxCommandEvent& event)
{
    EndModal(0);
}

void DialogMacrouSablon::Onm_RadioSelect(wxCommandEvent& event)
{
    if(m_Radio->GetSelection()==0)///macrou
    {
        m_MT->Show(true);
        m_Macrou->Show(true);
        m_ST->Show(false);
        m_Sablon->Show(false);
    }
    if(m_Radio->GetSelection()==1)///sablon
    {
        m_MT->Show(false);
        m_Macrou->Show(false);
        m_ST->Show(true);
        m_Sablon->Show(true);
    }
    Fit();
    Refresh();
    Layout();
}
