#include "DialogViewMacro.h"

//(*InternalHeaders(DialogViewMacro)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogViewMacro)
const long DialogViewMacro::ID_LISTVIEW1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogViewMacro,wxDialog)
	//(*EventTable(DialogViewMacro)
	//*)
END_EVENT_TABLE()

DialogViewMacro::DialogViewMacro(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogViewMacro)
	wxFlexGridSizer* FlexGridSizer4;

	Create(parent, id, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxSize(800,600));
	Move(wxDefaultPosition);
	FlexGridSizer4 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer4->AddGrowableCol(0);
	FlexGridSizer4->AddGrowableRow(0);
	m_List = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES|wxLC_VRULES|wxVSCROLL, wxDefaultValidator, _T("ID_LISTVIEW1"));
	FlexGridSizer4->Add(m_List, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer4);
	SetSizer(FlexGridSizer4);
	Layout();

	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&DialogViewMacro::Onm_ListBeginDrag);
	//*)
    this->SetPosition(wxPoint(GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));
}

DialogViewMacro::~DialogViewMacro()
{
	//(*Destroy(DialogViewMacro)
	//*)
}


void DialogViewMacro::Onm_ListBeginDrag(wxListEvent& event)
{
}
