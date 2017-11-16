#include "DialogGetCode.h"

//(*InternalHeaders(DialogGetCode)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogGetCode)
const long DialogGetCode::ID_STATICTEXT1 = wxNewId();
const long DialogGetCode::ID_TEXTCTRL1 = wxNewId();
const long DialogGetCode::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogGetCode,wxDialog)
	//(*EventTable(DialogGetCode)
	//*)
END_EVENT_TABLE()

DialogGetCode::DialogGetCode(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogGetCode)
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Codul din email:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Text = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer1->Add(m_Text, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Button = new wxButton(this, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer1->Add(m_Button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogGetCode::Onm_ButtonClick);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&DialogGetCode::OnClose);
	//*)
}

DialogGetCode::~DialogGetCode()
{
	//(*Destroy(DialogGetCode)
	//*)
}

#include "wx/msgdlg.h"
void DialogGetCode::Onm_ButtonClick(wxCommandEvent& event)
{

     if(expected.compare(m_Text->GetValue())==0)
    {
        EndModal(666);
        return;
    }
    else
        EndModal(0);
}

void DialogGetCode::OnClose(wxCloseEvent& event)
{
    EndModal(0);
}
