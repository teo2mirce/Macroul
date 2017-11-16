#include "DialogEditorKey.h"

//(*InternalHeaders(DialogEditorKey)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogEditorKey)
const long DialogEditorKey::ID_RADIOBOX1 = wxNewId();
const long DialogEditorKey::ID_CHOICE1 = wxNewId();
const long DialogEditorKey::ID_CHECKBOX1 = wxNewId();
const long DialogEditorKey::ID_CHECKBOX4 = wxNewId();
const long DialogEditorKey::ID_CHECKBOX3 = wxNewId();
const long DialogEditorKey::ID_CHECKBOX2 = wxNewId();
const long DialogEditorKey::ID_RADIOBOX4 = wxNewId();
const long DialogEditorKey::ID_TEXTCTRL1 = wxNewId();
const long DialogEditorKey::ID_CHECKBOX5 = wxNewId();
const long DialogEditorKey::ID_BUTTON1 = wxNewId();
const long DialogEditorKey::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogEditorKey,wxDialog)
	//(*EventTable(DialogEditorKey)
	//*)
END_EVENT_TABLE()

DialogEditorKey::DialogEditorKey(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogEditorKey)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer7;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Taste"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	wxString __wxRadioBoxChoices_1[2] =
	{
		_("O tasta"),
		_("Text")
	};
	m_ChoiceTaste = new wxRadioBox(this, ID_RADIOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
	m_ChoiceTaste->SetSelection(0);
	FlexGridSizer1->Add(m_ChoiceTaste, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5 = new wxFlexGridSizer(0, 1, 0, 0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("O tasta"));
	FlexGridSizer3 = new wxFlexGridSizer(0, 1, 0, 0);
	m_ChoiceKey = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	m_ChoiceKey->SetSelection( m_ChoiceKey->Append(wxEmptyString) );
	m_ChoiceKey->Append(_("A"));
	m_ChoiceKey->Append(_("B"));
	m_ChoiceKey->Append(_("C"));
	m_ChoiceKey->Append(_("D"));
	m_ChoiceKey->Append(_("E"));
	m_ChoiceKey->Append(_("F"));
	m_ChoiceKey->Append(_("G"));
	m_ChoiceKey->Append(_("H"));
	m_ChoiceKey->Append(_("I"));
	m_ChoiceKey->Append(_("J"));
	m_ChoiceKey->Append(_("K"));
	m_ChoiceKey->Append(_("L"));
	m_ChoiceKey->Append(_("M"));
	m_ChoiceKey->Append(_("N"));
	m_ChoiceKey->Append(_("O"));
	m_ChoiceKey->Append(_("P"));
	m_ChoiceKey->Append(_("Q"));
	m_ChoiceKey->Append(_("R"));
	m_ChoiceKey->Append(_("S"));
	m_ChoiceKey->Append(_("T"));
	m_ChoiceKey->Append(_("U"));
	m_ChoiceKey->Append(_("V"));
	m_ChoiceKey->Append(_("W"));
	m_ChoiceKey->Append(_("X"));
	m_ChoiceKey->Append(_("Y"));
	m_ChoiceKey->Append(_("Z"));
	m_ChoiceKey->Append(_("0"));
	m_ChoiceKey->Append(_("1"));
	m_ChoiceKey->Append(_("2"));
	m_ChoiceKey->Append(_("3"));
	m_ChoiceKey->Append(_("4"));
	m_ChoiceKey->Append(_("5"));
	m_ChoiceKey->Append(_("6"));
	m_ChoiceKey->Append(_("7"));
	m_ChoiceKey->Append(_("8"));
	m_ChoiceKey->Append(_("9"));
	m_ChoiceKey->Append(_("DEL"));
	m_ChoiceKey->Append(_("END"));
	m_ChoiceKey->Append(_("HOME"));
	m_ChoiceKey->Append(_("BACKSPACE"));
	m_ChoiceKey->Append(_("TAB"));
	m_ChoiceKey->Append(_("ENTER"));
	m_ChoiceKey->Append(_("ESC"));
	m_ChoiceKey->Append(_("SPACEBAR"));
	m_ChoiceKey->Append(_("PAGE_UP"));
	m_ChoiceKey->Append(_("PAGE_DOWN"));
	m_ChoiceKey->Append(_("LEFT"));
	m_ChoiceKey->Append(_("UP"));
	m_ChoiceKey->Append(_("RIGHT"));
	m_ChoiceKey->Append(_("DOWN"));
	m_ChoiceKey->Append(_("F1"));
	m_ChoiceKey->Append(_("F2"));
	m_ChoiceKey->Append(_("F3"));
	m_ChoiceKey->Append(_("F4"));
	m_ChoiceKey->Append(_("F5"));
	m_ChoiceKey->Append(_("F6"));
	m_ChoiceKey->Append(_("F7"));
	m_ChoiceKey->Append(_("F8"));
	m_ChoiceKey->Append(_("F9"));
	m_ChoiceKey->Append(_("F10"));
	m_ChoiceKey->Append(_("F11"));
	m_ChoiceKey->Append(_("F12"));
	m_ChoiceKey->Append(_("+"));
	FlexGridSizer3->Add(m_ChoiceKey, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer6 = new wxFlexGridSizer(2, 2, 0, 0);
	m_CTRL = new wxCheckBox(this, ID_CHECKBOX1, _("Ctrl"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	m_CTRL->SetValue(false);
	FlexGridSizer6->Add(m_CTRL, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_WIN = new wxCheckBox(this, ID_CHECKBOX4, _("Win"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
	m_WIN->SetValue(false);
	FlexGridSizer6->Add(m_WIN, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_ALT = new wxCheckBox(this, ID_CHECKBOX3, _("Alt"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	m_ALT->SetValue(false);
	FlexGridSizer6->Add(m_ALT, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	m_SHIFT = new wxCheckBox(this, ID_CHECKBOX2, _("Shift"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	m_SHIFT->SetValue(false);
	FlexGridSizer6->Add(m_SHIFT, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7->Add(FlexGridSizer6, 1, wxALL|wxSHAPED|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	wxString __wxRadioBoxChoices_2[3] =
	{
		_("Apasa"),
		_("Ridica"),
		_("Ambele")
	};
	m_State = new wxRadioBox(this, ID_RADIOBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_2, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX4"));
	m_State->SetSelection(2);
	FlexGridSizer7->Add(m_State, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(FlexGridSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("Text"));
	FlexGridSizer4 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer4->AddGrowableCol(0);
	FlexGridSizer4->AddGrowableRow(0);
	m_Text = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(200,100), wxTE_PROCESS_ENTER|wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer4->Add(m_Text, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_OneByOne = new wxCheckBox(this, ID_CHECKBOX5, _("Una cate una (doar litere si cifre)"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
	m_OneByOne->SetValue(false);
	FlexGridSizer4->Add(m_OneByOne, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	m_ButtonOK = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer2->Add(m_ButtonOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonCancel = new wxButton(this, ID_BUTTON2, _("Anuleaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer2->Add(m_ButtonCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&DialogEditorKey::OnM_ChoiceTasteSelect);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditorKey::Onm_ButtonOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogEditorKey::Onm_ButtonCancelClick);
	//*)
}

DialogEditorKey::~DialogEditorKey()
{
	//(*Destroy(DialogEditorKey)
	//*)
}


void DialogEditorKey::Onm_ButtonOKClick(wxCommandEvent& event)
{
    EndModal(1);
}

void DialogEditorKey::Onm_ButtonCancelClick(wxCommandEvent& event)
{
    EndModal(0);
}

void DialogEditorKey::OnM_ChoiceTasteSelect(wxCommandEvent& event)
{
    if(m_ChoiceTaste->GetSelection()==0)
        StaticBoxSizer1->Show(true),
        StaticBoxSizer2->Show(false);
    else
        StaticBoxSizer1->Show(false),
        StaticBoxSizer2->Show(true);
    Fit();
    Layout();
    Refresh();
}
