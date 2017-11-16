#include "Editor.h"
#include "DialogEditorClick.h"
#include "DialogEditorMove.h"
#include "DialogEditorSleep.h"
#include "DialogEditorKey.h"
#include "DialogEditorComentariu.h"
#include "DialogEditoroExecute.h"
#include "DialogEditorWebsite.h"
#include "DialogEditorEmail.h"
#include "DialogEditorPower.h"
#include "DialogEditorSSH.h"
#include "DialogEditorResize.h"
#include "DialogEditorClose.h"
#include "DialogEditorAsteapta.h"

//(*InternalHeaders(Editor)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(Editor)
const long Editor::ID_LISTVIEW1 = wxNewId();
const long Editor::ID_SPINBUTTON1 = wxNewId();
const long Editor::ID_BITMAPBUTTON2 = wxNewId();
const long Editor::ID_BITMAPBUTTON1 = wxNewId();
const long Editor::ID_BITMAPBUTTON3 = wxNewId();
const long Editor::ID_BITMAPBUTTON4 = wxNewId();
const long Editor::ID_BITMAPBUTTON5 = wxNewId();
const long Editor::ID_BITMAPBUTTON6 = wxNewId();
const long Editor::ID_BITMAPBUTTON7 = wxNewId();
const long Editor::ID_BITMAPBUTTON8 = wxNewId();
const long Editor::ID_BITMAPBUTTON9 = wxNewId();
const long Editor::ID_BITMAPBUTTON10 = wxNewId();
const long Editor::ID_BITMAPBUTTON11 = wxNewId();
const long Editor::ID_BITMAPBUTTON12 = wxNewId();
const long Editor::ID_BITMAPBUTTON13 = wxNewId();
const long Editor::ID_STATICTEXT1 = wxNewId();
const long Editor::ID_STATICTEXT3 = wxNewId();
const long Editor::ID_STATICTEXT2 = wxNewId();
const long Editor::ID_STATICTEXT4 = wxNewId();
const long Editor::ID_STATICTEXT5 = wxNewId();
const long Editor::ID_STATICTEXT6 = wxNewId();
const long Editor::ID_STATICTEXT7 = wxNewId();
const long Editor::ID_STATICTEXT8 = wxNewId();
const long Editor::ID_STATICTEXT9 = wxNewId();
const long Editor::ID_STATICTEXT10 = wxNewId();
const long Editor::ID_STATICTEXT11 = wxNewId();
const long Editor::ID_STATICTEXT12 = wxNewId();
const long Editor::ID_STATICTEXT13 = wxNewId();
const long Editor::ID_BUTTON1 = wxNewId();
const long Editor::ID_BUTTON2 = wxNewId();
const long Editor::ID_BUTTON5 = wxNewId();
const long Editor::ID_BUTTON3 = wxNewId();
const long Editor::ID_BUTTON4 = wxNewId();
const long Editor::ID_BUTTON6 = wxNewId();
const long Editor::ID_BUTTON7 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Editor,wxDialog)
	//(*EventTable(Editor)
	//*)
END_EVENT_TABLE()

Editor::Editor(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Editor)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Editor"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
	SetClientSize(wxSize(800,600));
	FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer4->AddGrowableCol(0);
	FlexGridSizer4->AddGrowableRow(0);
	m_List = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES|wxLC_VRULES|wxVSCROLL, wxDefaultValidator, _T("ID_LISTVIEW1"));
	FlexGridSizer4->Add(m_List, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonSpin = new wxSpinButton(this, ID_SPINBUTTON1, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL|wxSP_ARROW_KEYS, _T("ID_SPINBUTTON1"));
	m_ButtonSpin->SetRange(0, 1);
	FlexGridSizer4->Add(m_ButtonSpin, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer4, 1, wxTOP|wxBOTTOM|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(2, 13, 0, 0);
	m_ButtonClick = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("res\\click.bmp"))), wxDefaultPosition, wxSize(22,22), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
	m_ButtonClick->SetDefault();
	m_ButtonClick->SetToolTip(_("Click cursor"));
	m_ButtonClick->SetHelpText(_("Click cursor"));
	FlexGridSizer2->Add(m_ButtonClick, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonMove = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("res\\move.bmp"))), wxDefaultPosition, wxSize(22,22), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
	m_ButtonMove->SetDefault();
	m_ButtonMove->SetToolTip(_("Muta cursor"));
	m_ButtonMove->SetHelpText(_("Muta cursor"));
	FlexGridSizer2->Add(m_ButtonMove, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonSleep = new wxBitmapButton(this, ID_BITMAPBUTTON3, wxBitmap(wxImage(_T("res\\sleep.bmp"))), wxDefaultPosition, wxSize(22,22), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
	m_ButtonSleep->SetDefault();
	m_ButtonSleep->SetToolTip(_("Asteapta (milisecunde)"));
	m_ButtonSleep->SetHelpText(_("Asteapta (milisecunde)"));
	FlexGridSizer2->Add(m_ButtonSleep, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonKey = new wxBitmapButton(this, ID_BITMAPBUTTON4, wxBitmap(wxImage(_T("res\\key.bmp"))), wxDefaultPosition, wxSize(22,22), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
	m_ButtonKey->SetDefault();
	m_ButtonKey->SetToolTip(_("Taste"));
	m_ButtonKey->SetHelpText(_("Taste"));
	FlexGridSizer2->Add(m_ButtonKey, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonExecute = new wxBitmapButton(this, ID_BITMAPBUTTON5, wxBitmap(wxImage(_T("res\\execute.bmp"))), wxDefaultPosition, wxSize(22,22), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
	m_ButtonExecute->SetDefault();
	m_ButtonExecute->SetToolTip(_("Executa"));
	m_ButtonExecute->SetHelpText(_("Executa"));
	FlexGridSizer2->Add(m_ButtonExecute, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonWeb = new wxBitmapButton(this, ID_BITMAPBUTTON6, wxBitmap(wxImage(_T("res\\website.bmp"))), wxDefaultPosition, wxSize(22,22), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
	m_ButtonWeb->SetDefault();
	m_ButtonWeb->SetToolTip(_("Website"));
	m_ButtonWeb->SetHelpText(_("Website"));
	FlexGridSizer2->Add(m_ButtonWeb, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonEmail = new wxBitmapButton(this, ID_BITMAPBUTTON7, wxBitmap(wxImage(_T("res\\email.bmp"))), wxDefaultPosition, wxSize(22,22), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON7"));
	m_ButtonEmail->SetDefault();
	m_ButtonEmail->SetToolTip(_("Email"));
	m_ButtonEmail->SetHelpText(_("Email"));
	FlexGridSizer2->Add(m_ButtonEmail, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonPower = new wxBitmapButton(this, ID_BITMAPBUTTON8, wxBitmap(wxImage(_T("res\\shutdown.bmp"))), wxDefaultPosition, wxSize(22,22), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON8"));
	m_ButtonPower->SetDefault();
	m_ButtonPower->SetToolTip(_("Power"));
	m_ButtonPower->SetHelpText(_("Power"));
	FlexGridSizer2->Add(m_ButtonPower, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonSSH = new wxBitmapButton(this, ID_BITMAPBUTTON9, wxBitmap(wxImage(_T("res\\ssh.bmp"))), wxDefaultPosition, wxSize(22,22), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON9"));
	m_ButtonSSH->SetDefault();
	m_ButtonSSH->SetToolTip(_("SSH"));
	m_ButtonSSH->SetHelpText(_("SSH"));
	FlexGridSizer2->Add(m_ButtonSSH, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonClose = new wxBitmapButton(this, ID_BITMAPBUTTON10, wxBitmap(wxImage(_T("res\\close.bmp"))), wxDefaultPosition, wxSize(22,22), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON10"));
	m_ButtonClose->SetDefault();
	m_ButtonClose->SetToolTip(_("Inchide"));
	m_ButtonClose->SetHelpText(_("Inchide"));
	FlexGridSizer2->Add(m_ButtonClose, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonResize = new wxBitmapButton(this, ID_BITMAPBUTTON11, wxBitmap(wxImage(_T("res\\resize.bmp"))), wxDefaultPosition, wxSize(22,22), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON11"));
	m_ButtonResize->SetDefault();
	m_ButtonResize->SetToolTip(_("Redimensionare"));
	m_ButtonResize->SetHelpText(_("Redimensionare"));
	FlexGridSizer2->Add(m_ButtonResize, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonAsteapta = new wxBitmapButton(this, ID_BITMAPBUTTON12, wxBitmap(wxImage(_T("res\\waiting.bmp"))), wxDefaultPosition, wxSize(22,22), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON12"));
	m_ButtonAsteapta->SetDefault();
	m_ButtonAsteapta->SetToolTip(_("Asteapta schimbare"));
	m_ButtonAsteapta->SetHelpText(_("Asteapta schimbare"));
	FlexGridSizer2->Add(m_ButtonAsteapta, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonMacrou = new wxBitmapButton(this, ID_BITMAPBUTTON13, wxBitmap(wxImage(_T("res\\macrou.bmp"))), wxDefaultPosition, wxSize(22,22), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON13"));
	m_ButtonMacrou->SetDefault();
	m_ButtonMacrou->SetToolTip(_("Macou"));
	m_ButtonMacrou->SetHelpText(_("Macou"));
	FlexGridSizer2->Add(m_ButtonMacrou, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("C"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("M"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer2->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("S"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("K"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer2->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("E"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer2->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("W"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer2->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("@"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer2->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("P"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	FlexGridSizer2->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("H"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	FlexGridSizer2->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("X"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	FlexGridSizer2->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("R"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	FlexGridSizer2->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("A"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	FlexGridSizer2->Add(StaticText12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("Q"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	FlexGridSizer2->Add(StaticText13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 7, 0, 0);
	m_ButtonSave = new wxButton(this, ID_BUTTON1, _("Salveaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(m_ButtonSave, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonEditeaza = new wxButton(this, ID_BUTTON2, _("Editeaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer3->Add(m_ButtonEditeaza, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonSterge = new wxButton(this, ID_BUTTON5, _("Sterge"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	FlexGridSizer3->Add(m_ButtonSterge, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonComentariu = new wxButton(this, ID_BUTTON3, _("Comentariu"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer3->Add(m_ButtonComentariu, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonTest = new wxButton(this, ID_BUTTON4, _("Test"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	FlexGridSizer3->Add(m_ButtonTest, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonImport = new wxButton(this, ID_BUTTON6, _("Import"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
	FlexGridSizer3->Add(m_ButtonImport, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonExport = new wxButton(this, ID_BUTTON7, _("Export"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
	FlexGridSizer3->Add(m_ButtonExport, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	m_SaveFile = new wxFileDialog(this, _("Selecteaza fisier"), wxEmptyString, wxEmptyString, _("Macrou Files (*.Macrou) | *.Macrou"), wxFD_SAVE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	m_OpenFile = new wxFileDialog(this, _("Selecteaza fisier"), wxEmptyString, wxEmptyString, _("Macrou Files (*.Macrou) | *.Macrou"), wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	SetSizer(FlexGridSizer1);
	Layout();

	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&Editor::Onm_ListItemActivated);
	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_KEY_DOWN,(wxObjectEventFunction)&Editor::Onm_ListKeyDown);
	Connect(ID_SPINBUTTON1,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&Editor::Onm_ButtonSpinChange);
	Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonClickClick);
	Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonMoveClick);
	Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonSleepClick);
	Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonKeyClick);
	Connect(ID_BITMAPBUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonExecuteClick);
	Connect(ID_BITMAPBUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonWebClick);
	Connect(ID_BITMAPBUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonEmailClick);
	Connect(ID_BITMAPBUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonPowerClick);
	Connect(ID_BITMAPBUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonSSHClick);
	Connect(ID_BITMAPBUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonCloseClick);
	Connect(ID_BITMAPBUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonResizeClick);
	Connect(ID_BITMAPBUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonAsteaptaClick);
	Connect(ID_BITMAPBUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonMacrouClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonSaveClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonEditeazaClick);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonStergeClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonComentariuClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonTestClick);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonImportClick);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Editor::Onm_ButtonExportClick);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Editor::OnClose);
	//*)
	m_List->DeleteAllColumns();
    m_List->InsertColumn(0,"Comentariu",wxLIST_FORMAT_LEFT, 250);
    m_List->InsertColumn(1,"Actiune",wxLIST_FORMAT_LEFT, 520);
    if(m_List->GetItemCount())
        m_List->DeleteAllItems();

    this->SetPosition(wxPoint(GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));
}

Editor::~Editor()
{
	//(*Destroy(Editor)
	//*)
}


// Convert a wide Unicode string to an UTF8 string
std::string utf8_encode(const std::wstring &wstr)
{
    if( wstr.empty() ) return std::string();
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
    std::string strTo( size_needed, 0 );
    WideCharToMultiByte                  (CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
    return strTo;
}

// Convert an UTF8 string to a wide Unicode String
std::wstring utf8_decode(const std::string &str)
{
    if( str.empty() ) return std::wstring();
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo( size_needed, 0 );
    MultiByteToWideChar                  (CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}



void Editor::Onm_ButtonClickClick(wxCommandEvent& event)
{
    DialogEditorClick x(this);
//    x.m_X->SelectAll();
    if(x.ShowModal()==1)
    {
        wxString ichar="";
        if(x.m_CheckRandom->GetValue())
            ichar<<"Click("<<x.m_X->GetValue()<<"|"<<x.m_XMAX->GetValue()<<","<<x.m_Y->GetValue()<<"|"<<x.m_YMAX->GetValue()<<","<<x.m_RadioStMjDr->GetString(x.m_RadioStMjDr->GetSelection())<<","<<x.m_RadioApRiAm->GetString(x.m_RadioApRiAm->GetSelection())<<")";
        else
            ichar<<"Click("<<x.m_X->GetValue()<<","<<x.m_Y->GetValue()<<","<<x.m_RadioStMjDr->GetString(x.m_RadioStMjDr->GetSelection())<<","<<x.m_RadioApRiAm->GetString(x.m_RadioApRiAm->GetSelection())<<")";
        Insert(ichar);
    }
}

void Editor::Insert(wxString x)
{
    int n=m_List->GetItemCount();
    int k=m_List->GetFirstSelected();

    int pos=0;
    if(n==0)
        pos=0;
    else
    {
        if(k==-1)
            pos=n;
        else
            pos=k;
    }
    m_List->InsertItem(pos,"");
    m_List->SetItem(pos,1,x);
    Exec.Insert(x,pos);
    Comm.Insert("",pos);
}
void Editor::Onm_ListItemActivated(wxListEvent& event)
{
    Onm_ButtonEditeazaClick(wxCE);
}
#include "Misc.h"
void Editor::Onm_ListKeyDown(wxListEvent& event)
{
    if(event.GetKeyCode()=='C')
        Onm_ButtonClickClick(wxCE);
    if(event.GetKeyCode()=='M')
        Onm_ButtonMoveClick(wxCE);
    if(event.GetKeyCode()=='S')
        Onm_ButtonSleepClick(wxCE);
    if(event.GetKeyCode()=='K')
        Onm_ButtonKeyClick(wxCE);
    if(event.GetKeyCode()=='E')
        Onm_ButtonExecuteClick(wxCE);
    if(event.GetKeyCode()=='W')
        Onm_ButtonWebClick(wxCE);
    if(event.GetKeyCode()=='2')
        Onm_ButtonEmailClick(wxCE);
    if(event.GetKeyCode()=='P')
        Onm_ButtonPowerClick(wxCE);
    if(event.GetKeyCode()=='H')
        Onm_ButtonSSHClick(wxCE);
    if(event.GetKeyCode()=='X')
        Onm_ButtonCloseClick(wxCE);
    if(event.GetKeyCode()=='R')
        Onm_ButtonResizeClick(wxCE);
    if(event.GetKeyCode()=='A')
        Onm_ButtonAsteaptaClick(wxCE);
    if(event.GetKeyCode()=='Q')
        Onm_ButtonMacrouClick(wxCE);
}
void Editor::Onm_ButtonMoveClick(wxCommandEvent& event)
{
    DialogEditorMove x(this);
    if(x.ShowModal()==1)
    {
        wxString ichar="";
        ichar<<"Muta("<<x.m_X->GetValue()<<","<<x.m_Y->GetValue()<<","<<x.RadioBox4->GetString(x.RadioBox4->GetSelection())<<")";
        Insert(ichar);
    }
}

void Editor::Onm_ButtonSleepClick(wxCommandEvent& event)
{
    DialogEditorSleep x(this);
    if(x.ShowModal()==1)
    {
        wxString ichar="";
        ichar<<"Asteapta("<<x.m_Milisec->GetValue()<<")";
        Insert(ichar);
    }
}

void Editor::Onm_ButtonKeyClick(wxCommandEvent& event)
{
    DialogEditorKey x(this);

    x.StaticBoxSizer2->Show(false);
    if(x.ShowModal()==1)
    {
        wxString ichar="";
        ichar<<"Taste("<<x.m_ChoiceTaste->GetString(x.m_ChoiceTaste->GetSelection())<<",";
        if(x.m_ChoiceTaste->GetSelection()==0)
        {
            ichar<<x.m_State->GetString(x.m_State->GetSelection())<<",";
            if(x.m_CTRL->IsChecked())
                ichar<<"CTRL,";
            if(x.m_WIN->IsChecked())
                ichar<<"WIN,";
            if(x.m_ALT->IsChecked())
                ichar<<"ALT,";
            if(x.m_SHIFT->IsChecked())
                ichar<<"SHIFT,";
            ichar<<x.m_ChoiceKey->GetString(x.m_ChoiceKey->GetSelection())<<")";
        }
        else
        {
            if(x.m_OneByOne->GetValue())
                ichar<<"Intrerupt";
            else
                ichar<<"Deodata";
            ichar<<","<<x.m_Text->GetValue()<<")";
        }
        Insert(ichar);
        //fmm=ichar;
    }
}



void Editor::Onm_ButtonComentariuClick(wxCommandEvent& event)
{
    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza un rand");
        return;
    }
    DialogEditorComentariu x(this);
    x.m_Comment->SetValue(Comm[m_List->GetFirstSelected()]);
    if(x.ShowModal()==1)
    {
        m_List->SetItem(m_List->GetFirstSelected(),0,x.m_Comment->GetValue());
        Comm[m_List->GetFirstSelected()]=x.m_Comment->GetValue();
    }
}

void Editor::Onm_ButtonTestClick(wxCommandEvent& event)
{
    if(m_List->GetItemCount()==0)
    {
        wxMessageBox("Lista e goala");
        return;
    }
    int slip=30;
    if(ReadDatas(2)!="")
        slip=atoi(ReadDatas(2).data().AsChar());
    if(m_List->GetFirstSelected()<0)
    {
        for(int a=0;a<m_List->GetItemCount();a++)
            runLine(Exec[a],slip,UID);
    }
    else
        runLine(Exec[m_List->GetFirstSelected()],slip,UID);
}

#include <wx/tokenzr.h>
/*
A programming language is a formal computer language or constructed
language designed to communicate instructions to a machine,
particularly a computer. Programming languages can be used to create programs
to control the behavior of a machine or to express algorithms.
*/



void Editor::Onm_ButtonExecuteClick(wxCommandEvent& event)
{
    DialogEditoroExecute x(this);
    if(x.ShowModal()==1)
    {
        wxString ichar="";
        ichar<<"Executa("<<x.m_File->GetPath()<<",";
        if(x.m_Asteapta->GetValue())
            ichar<<"Sync";
        else
            ichar<<"Async";
        ichar<<",";
        if(x.m_Ascunde->GetValue())
            ichar<<"Ascunde";
        else
            ichar<<"Arata";
        ichar<<",";
        ichar<<x.m_Arguments->GetValue()<<")";
        Insert(ichar);
    }
}

void Editor::Onm_ButtonWebClick(wxCommandEvent& event)
{
    DialogEditorWebsite x(this);
    if(x.ShowModal()==1)
    {
        wxString ichar="";
        ichar<<"Website("<<x.m_Website->GetValue()<<")";
        Insert(ichar);
    }
}

void Editor::Onm_ButtonEmailClick(wxCommandEvent& event)
{
    DialogEditorEmail x(this);
    if(x.ShowModal()==1)
    {
        wxString ichar="";
        ichar<<"Email("<<x.m_Email->GetValue()<<","<<x.m_Text->GetValue()<<")";
        Insert(ichar);
    }
}

void Editor::Onm_ButtonPowerClick(wxCommandEvent& event)
{
    DialogEditorPower x(this);
    if(x.ShowModal()==1)
    {
        wxString ichar="";
        ichar<<"Power("<<x.m_Radio->GetString(x.m_Radio->GetSelection())<<","<<x.m_Spin->GetValue()<<")";
        Insert(ichar);
    }
}

void Editor::Onm_ButtonSSHClick(wxCommandEvent& event)
{
    DialogEditorSSH x(this);
    if(x.ShowModal()==1)
    {
        wxString ichar="";
        ichar<<"SSH(";
        if(x.m_Asteapta->GetValue())
            ichar<<"Sync";
        else
            ichar<<"Async";
        ichar<<","<<x.m_IP->GetValue()<<","<<x.m_User->GetValue()<<","<<x.m_Parola->GetValue()<<","<<x.m_Comenzi->GetValue()<<")";
        Insert(ichar);
    }
}

void Editor::Onm_ButtonCloseClick(wxCommandEvent& event)
{
    //Inchide

    DialogEditorClose x(this);
    if(x.ShowModal()==1)
    {
        wxString ichar="";
        ichar<<"Inchide("<<x.m_Radio->GetString(x.m_Radio->GetSelection())<<","<<x.m_Text->GetValue()<<")";
        Insert(ichar);
    }
    return;
}

void Editor::Onm_ButtonResizeClick(wxCommandEvent& event)
{
    //Redimensionare

    DialogEditorResize x(this);
    if(x.ShowModal()==1)
    {
        wxString ichar="";
        ichar<<"Redimensionare("<<x.m_x->GetValue()<<","<<x.m_y->GetValue()<<","<<x.m_w->GetValue()<<","<<x.m_h->GetValue()<<","<<x.m_Text->GetValue()<<")";
        Insert(ichar);
    }
}
#include "DialogMacrouSablon.h"
void Editor::Onm_ButtonEditeazaClick(wxCommandEvent& event)
{
    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza un rand");
        return;
    }
    int pozy=m_List->GetFirstSelected();
    wxString input = Exec[pozy];
    wxString res;
    wxString rest;
    input.RemoveLast();

    if(input.StartsWith("Click(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString x,y,a1,a2;
        x=tok.GetNextToken();
        y=tok.GetNextToken();
        a1=tok.GetNextToken();
        a2=tok.GetNextToken();

        DialogEditorClick D(this);
        if(x.Contains("|"))
        {
            D.m_CheckRandom->SetValue(true);
            wxStringTokenizer xxx(x,"|");
            wxStringTokenizer yyy(y,"|");
            D.m_X->SetValue(xxx.GetNextToken());
            D.m_Y->SetValue(yyy.GetNextToken());
            D.m_XMAX->SetValue(xxx.GetNextToken());
            D.m_YMAX->SetValue(yyy.GetNextToken());
            D.m_XMAX->Enable();
            D.m_YMAX->Enable();
        }
        else
        {
            D.m_CheckRandom->SetValue(false);
            D.m_X->SetValue(x);
            D.m_Y->SetValue(y);
            D.m_XMAX->Enable(false);
            D.m_YMAX->Enable(false);
        }
        D.m_RadioStMjDr->SetStringSelection(a1);
        D.m_RadioApRiAm->SetStringSelection(a2);
        if(D.ShowModal()==1)
        {
            wxString ichar="";
            if(D.m_CheckRandom->GetValue())
                ichar<<"Click("<<D.m_X->GetValue()<<"|"<<D.m_XMAX->GetValue()<<","<<D.m_Y->GetValue()<<"|"<<D.m_YMAX->GetValue()<<","<<D.m_RadioStMjDr->GetString(D.m_RadioStMjDr->GetSelection())<<","<<D.m_RadioApRiAm->GetString(D.m_RadioApRiAm->GetSelection())<<")";
            else
                ichar<<"Click("<<D.m_X->GetValue()<<","<<D.m_Y->GetValue()<<","<<D.m_RadioStMjDr->GetString(D.m_RadioStMjDr->GetSelection())<<","<<D.m_RadioApRiAm->GetString(D.m_RadioApRiAm->GetSelection())<<")";

            Exec[pozy]=ichar;
            m_List->SetItem(pozy,1,ichar);
        }
    }
    if(input.StartsWith("Muta(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString x,y,a1,a2;
        x=tok.GetNextToken();
        y=tok.GetNextToken();
        a1=tok.GetNextToken();


        DialogEditorMove D(this);
        D.m_X->SetValue(x);
        D.m_Y->SetValue(y);
        D.RadioBox4->SetStringSelection(a1);
        if(D.ShowModal()==1)
        {
            wxString ichar="";
            ichar<<"Muta("<<D.m_X->GetValue()<<","<<D.m_Y->GetValue()<<","<<D.RadioBox4->GetString(D.RadioBox4->GetSelection())<<")";
            Exec[pozy]=ichar;
            m_List->SetItem(pozy,1,ichar);

        }
    }
    if(input.StartsWith("Email(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString x,y,a1,a2;
        x=tok.GetNextToken();
        y=tok.GetString();



        DialogEditorEmail D(this);
        D.m_Email->SetValue(x);
        D.m_Text->SetValue(y);
        if(D.ShowModal()==1)
        {
            wxString ichar="";
            ichar<<"Email("<<D.m_Email->GetValue()<<","<<D.m_Text->GetValue()<<")";
            Exec[pozy]=ichar;
            m_List->SetItem(pozy,1,ichar);
        }


    }
    if(input.StartsWith("Asteapta(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString x;
        x=tok.GetNextToken();

        DialogEditorSleep D(this);
        D.m_Milisec->SetValue(x);
        if(D.ShowModal()==1)
        {
            wxString ichar="";
            ichar<<"Asteapta("<<D.m_Milisec->GetValue()<<")";
            Exec[pozy]=ichar;
            m_List->SetItem(pozy,1,ichar);
        }
    }
    if(input.StartsWith("Asteapta_schimbare(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString x;
        x=tok.GetNextToken();
        DialogEditorAsteapta D(this);
        int ch1=0,ch2=0;
        if(x=="Proces")
            D.m_Radio->SetSelection(0);
        if(x=="Fereastra")
            D.m_Radio->SetSelection(1),ch1=1;
        if(x=="Pixel")
            D.m_Radio->SetSelection(2),ch1=2;

        D.Onm_RadioSelect(wxCE);
        x=tok.GetNextToken();
        if(x=="Asteapta sa apara")
            D.RadioBox1->SetSelection(0);
        else
            D.RadioBox1->SetSelection(1),ch2=1;
        D.OnRadioBox1Select(wxCE);
        if(ch1<2)
            D.m_Text->SetValue(tok.GetNextToken());
        else
        {
            D.m_X->SetValue(tok.GetNextToken());
            D.m_Y->SetValue(tok.GetNextToken());
            if(ch2==0)
            {
                D.SpinCtrl1->SetValue(tok.GetNextToken());
                D.SpinCtrl2->SetValue(tok.GetNextToken());
                D.SpinCtrl3->SetValue(tok.GetNextToken());
            }
        }
        if(D.ShowModal()==1)
        {
            wxString ichar="Asteapta_schimbare(";
            ichar<<D.m_Radio->GetString(D.m_Radio->GetSelection())<<",";
            ichar<<D.RadioBox1->GetString(D.RadioBox1->GetSelection())<<",";
            if(D.m_Radio->GetSelection()<2)
                ichar<<D.m_Text->GetValue();
            else
            {
                ichar<<D.m_X->GetValue()<<","<<D.m_Y->GetValue();
                if(D.RadioBox1->GetSelection()==0)
                    ichar<<","<<D.SpinCtrl1->GetValue()<<","<<D.SpinCtrl2->GetValue()<<","<<D.SpinCtrl3->GetValue();
            }
            ichar<<")";


            Exec[pozy]=ichar;
            m_List->SetItem(pozy,1,ichar);
        }
    }
    if(input.StartsWith("Power(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString x,y;
        x=tok.GetNextToken();
        y=tok.GetNextToken();

        DialogEditorPower D(this);
        D.m_Radio->SetStringSelection(x);
        D.m_Spin->SetValue(y);
        if(D.ShowModal()==1)
        {
            wxString ichar="";
            ichar<<"Power("<<D.m_Radio->GetString(D.m_Radio->GetSelection())<<","<<D.m_Spin->GetValue()<<")";
            Exec[pozy]=ichar;
            m_List->SetItem(pozy,1,ichar);
        }
    }
    if(input.StartsWith("Website(",&res))
    {
        DialogEditorWebsite x(this);
        x.m_Website->SetValue(res);
        if(x.ShowModal()==1)
        {
            wxString ichar="";
            ichar<<"Website("<<x.m_Website->GetValue()<<")";
            Exec[pozy]=ichar;
            m_List->SetItem(pozy,1,ichar);
        }
    }
    if(input.StartsWith("Executa(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString a,b,c,d;
        a=tok.GetNextToken();
        b=tok.GetNextToken();//asteapta
        c=tok.GetNextToken();//ascunde
        d=tok.GetString();//argumente

        DialogEditoroExecute x(this);
        x.m_File->SetPath(a);
        if(b=="Sync")
            x.m_Asteapta->SetValue(1);
        else
            x.m_Asteapta->SetValue(0);
        if("Ascunde"==c)
            x.m_Ascunde->SetValue(1);
        else
            x.m_Ascunde->SetValue(0);
        x.m_Arguments->SetValue(d);
        if(x.ShowModal()==1)
        {
            wxString ichar="";
            ichar<<"Executa("<<x.m_File->GetPath()<<",";
            if(x.m_Asteapta->GetValue())
                ichar<<"Sync";
            else
                ichar<<"Async";
            ichar<<",";
            if(x.m_Ascunde->GetValue())
                ichar<<"Ascunde";
            else
                ichar<<"Arata";
            ichar<<",";
            ichar<<x.m_Arguments->GetValue()<<")";

            Exec[pozy]=ichar;
            m_List->SetItem(pozy,1,ichar);
        }

    }
    if(input.StartsWith("Redimensionare(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString a,b,c,d,e;
        a=tok.GetNextToken();
        b=tok.GetNextToken();//asteapta
        c=tok.GetNextToken();//ascunde
        d=tok.GetNextToken();//ascunde
        e=tok.GetString();//argumente

        DialogEditorResize x(this);
        x.m_x->SetValue(a);
        x.m_y->SetValue(b);
        x.m_w->SetValue(c);
        x.m_h->SetValue(d);
        x.m_Text->SetValue(e);
        if(x.ShowModal()==1)
        {
            wxString ichar="";
            ichar<<"Redimensionare("<<x.m_x->GetValue()<<","<<x.m_y->GetValue()<<","<<x.m_w->GetValue()<<","<<x.m_h->GetValue()<<","<<x.m_Text->GetValue()<<")";
            Exec[pozy]=ichar;
            m_List->SetItem(pozy,1,ichar);
        }

    }
    if(input.StartsWith("Inchide(",&res))///nu aici
    {
        wxStringTokenizer tok(res, ",");
        wxString a,b,c,d;
        a=tok.GetNextToken();
        b=tok.GetString();//argumente

        DialogEditorClose x(this);
        x.m_Radio->SetStringSelection(a);
        x.m_Text->SetValue(b);
        if(x.ShowModal()==1)
        {
            wxString ichar="";
            ichar<<"Inchide("<<x.m_Radio->GetString(x.m_Radio->GetSelection())<<","<<x.m_Text->GetValue()<<")";
            Exec[pozy]=ichar;
            m_List->SetItem(pozy,1,ichar);
        }
    }
    if(input.StartsWith("Macrou(",&rest))
    {
        DialogMacrouSablon x(this);
        x.m_Radio->SetSelection(0);
        x.Onm_RadioSelect(wxCE);

        wxString temp="select ID,Nume from macrou where UserID="+UID;
        wxArrayString ID,Nume;
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
                for (size_t i = 0; i < res.num_rows(); ++i)
                {
                    ID.Add(res[i][0].c_str());
                    Nume.Add(utf8_decode(res[i][1].c_str()));
                    x.m_Macrou->Append(Nume[i]);
                    if(ID[i]==rest)
                        x.m_Macrou->SetSelection(i);
                }
        }
        if(x.ShowModal()==1)
        {
            wxString ichar="";
            if(x.m_Radio->GetSelection()==0)///macrou
                ichar<<"Macrou("<<ID[x.m_Macrou->GetSelection()]<<")";
            else
                ichar<<"Sablon("<<x.m_Sablon->GetValue()<<")";
            Exec[pozy]=ichar;
            m_List->SetItem(pozy,1,ichar);
        }
    }
    if(input.StartsWith("Sablon(",&rest))
    {
        DialogMacrouSablon x(this);
        x.m_Radio->SetSelection(1);
        x.Onm_RadioSelect(wxCE);
        x.m_Sablon->SetValue(rest);

        wxString temp="select ID,Nume from macrou where UserID="+UID;
        wxArrayString ID,Nume;
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
                for (size_t i = 0; i < res.num_rows(); ++i)
                {
                    ID.Add(res[i][0].c_str());
                    Nume.Add(utf8_decode(res[i][1].c_str()));
                    x.m_Macrou->Append(Nume[i]);
                }
        }
        if(x.ShowModal()==1)
        {
            wxString ichar="";
            if(x.m_Radio->GetSelection()==0)///macrou
                ichar<<"Macrou("<<ID[x.m_Macrou->GetSelection()]<<")";
            else
                ichar<<"Sablon("<<x.m_Sablon->GetValue()<<")";
            Exec[pozy]=ichar;
            m_List->SetItem(pozy,1,ichar);
        }
    }
    if(input.StartsWith("SSH(",&res))
    {
        wxStringTokenizer tok(res, ",");
        wxString a,b,c,d,e,ichar="";
        a=tok.GetNextToken();
        b=tok.GetNextToken();
        c=tok.GetNextToken();
        d=tok.GetNextToken();
        e=tok.GetString();

        DialogEditorSSH x(this);

        if(a=="Sync")
            x.m_Asteapta->SetValue(1);
        else
            x.m_Asteapta->SetValue(0);

        ///x.m_Asteapta->SetValue(wxAtoi(a));
        x.m_IP->SetValue(b);
        x.m_User->SetValue(c);
        x.m_Parola->SetValue(d);
        x.m_Comenzi->SetValue(e);


        if(x.ShowModal()==1)
        {
            wxString ichar="";
            ichar<<"SSH(";
            if(x.m_Asteapta->GetValue())
                ichar<<"Sync";
            else
                ichar<<"Async";
            ichar<<","<<x.m_IP->GetValue()<<","<<x.m_User->GetValue()<<","<<x.m_Parola->GetValue()<<","<<x.m_Comenzi->GetValue()<<")";
            Exec[pozy]=ichar;
            m_List->SetItem(pozy,1,ichar);
        }
    }

    ///TREBUIE SA FACI 2 LISTE DE WXSTRINGURI CU CE E PE FIECARE LINIE/COLOANA CA ASTIA NU POT TINE MAI MULTE DE 400 CHARS PE WXlISTITEM!!!
   // wxListItem
//    input=fmm;






    if(input.StartsWith("Taste(",&res))
    {
        DialogEditorKey D(this);
        wxStringTokenizer tok(res, ",");
        wxString x,y;
        x=tok.GetNextToken();
        D.m_ChoiceTaste->SetStringSelection(x);
        if(x.StartsWith("O tasta"))
        {
            D.m_ChoiceTaste->SetSelection(0);
            D.OnM_ChoiceTasteSelect(*(new wxCommandEvent()));

            y=tok.GetNextToken();
            D.m_State->SetStringSelection(y);

            wxArrayString v;
            D.m_CTRL->SetValue(false);

            while (tok.HasMoreTokens())
            {
                wxString temy=tok.GetNextToken();
                if(temy=="CTRL")
                    D.m_CTRL->SetValue(true);
                else
                if(temy=="WIN")
                    D.m_WIN->SetValue(true);
                else
                if(temy=="ALT")
                    D.m_ALT->SetValue(true);
                else
                if(temy=="SHIFT")
                    D.m_SHIFT->SetValue(true);
                else
                    D.m_ChoiceKey->SetStringSelection(temy);
            }
        }
        else
        {
            D.m_ChoiceTaste->SetSelection(1);
            D.OnM_ChoiceTasteSelect(*(new wxCommandEvent()));
            wxString temp;

            temp= tok.GetNextToken();

            if(temp=="Intrerupt")
                D.m_OneByOne->SetValue(1);
            else
                D.m_OneByOne->SetValue(0);



            temp= tok.GetString();
            D.m_Text->SetValue(temp);
        }
        if(D.ShowModal()==1)
        {
            wxString ichar="";
            ichar<<"Taste("<<D.m_ChoiceTaste->GetString(D.m_ChoiceTaste->GetSelection())<<",";
            if(D.m_ChoiceTaste->GetSelection()==0)
            {
                ichar<<D.m_State->GetString(D.m_State->GetSelection())<<",";
                if(D.m_CTRL->IsChecked())
                    ichar<<"CTRL,";
                if(D.m_WIN->IsChecked())
                    ichar<<"WIN,";
                if(D.m_ALT->IsChecked())
                    ichar<<"ALT,";
                if(D.m_SHIFT->IsChecked())
                    ichar<<"SHIFT,";
                ichar<<D.m_ChoiceKey->GetString(D.m_ChoiceKey->GetSelection())<<")";
            }
            else
            {

                if(D.m_OneByOne->GetValue())
                    ichar<<"Intrerupt";
                else
                    ichar<<"Deodata";
                ichar<<","<<D.m_Text->GetValue()<<")";
            }
            Exec[pozy]=ichar;
            m_List->SetItem(pozy,1,ichar);
        }
    }

}

void Editor::Onm_ButtonStergeClick(wxCommandEvent& event)
{
    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza un rand");
        return;
    }
    int x=m_List->GetFirstSelected();
    m_List->DeleteItem(x);
    Exec.RemoveAt(x);
    Comm.RemoveAt(x);
}
#include <wx/textfile.h>
void Editor::Onm_ButtonExportClick(wxCommandEvent& event)
{
    if(m_SaveFile->ShowModal()==wxID_CANCEL)
        return;
    wxTextFile f;
    if (f.Create(m_SaveFile->GetPath()) == false)
    {
        f.Open(m_SaveFile->GetPath());
        f.Clear();
    }
    for(int a=0;a<m_List->GetItemCount();a++)
    {
        wxString ichar="";
        //ichar<<m_List->GetItemText(a,0)<<"|||"<<m_List->GetItemText(a,1);
        ichar<<Comm[a]<<"|||"<<Exec[a];
        ichar.Replace("\n","<nl>");
        f.AddLine(ichar);
    }
    f.Write();
    f.Close();
}

void Editor::Onm_ButtonImportClick(wxCommandEvent& event)
{
    if(m_OpenFile->ShowModal()==wxID_CANCEL)
        return;
    wxTextFile f;
    if (f.Open(m_OpenFile->GetPath()) == false)
        return;

    if(m_List->GetItemCount())
        m_List->DeleteAllItems();
    Comm.Empty();
    Exec.Empty();
    Log("inainte");
    for(int a=0;a<f.GetLineCount();a++)
    {
        wxString da=f.GetLine(a);
        if(da.IsEmpty())
            da="|||Asteapta(1)";

        int poz=da.find("|||");
        wxString q1=da.substr(0,poz);
        wxString q2=da.substr(poz+3);
        //q2.Replace("|||","");
        q1.Replace("<nl>","\n");
        q2.Replace("<nl>","\n");
        Comm.Insert(q1,a);
        Exec.Insert(q2,a);
        m_List->InsertItem(a,"");
        m_List->SetItem(a,0,q1);
        m_List->SetItem(a,1,q2);
    }
    Log("Si dupa");
    f.Close();
}

void Editor::Onm_ButtonSaveClick(wxCommandEvent& event)
{
    EndModal(1);
}


/*
// drop a list item (start row is in m_drag)
void Editor::OnDragEnd(wxMouseEvent& event)
{
  wxPoint pos = event.GetPosition();  // must reference the event
  int flags = wxLIST_HITTEST_ONITEM;
  long index = m_List->HitTest(pos,flags,NULL); // got to use it at last
  if(index >= 0 && index != m_drag){ // valid and not the same as start
  //  ...
    // do something to move/copy the list control items
  //  ...

    swap(Comm[index],Comm[m_drag]);
    swap(Exec[index],Exec[m_drag]);
    m_List->SetItem(index,0,Comm[index]);
    m_List->SetItem(index,1,Exec[index]);
    m_List->SetItem(m_drag,0,Comm[m_drag]);
    m_List->SetItem(m_drag,1,Exec[m_drag]);

  }
  // restore cursor
  m_List->SetCursor(wxCursor(*wxSTANDARD_CURSOR));
  // disconnect both functions
  m_List->Disconnect(wxEVT_LEFT_UP,
    wxMouseEventHandler(Editor::OnDragEnd));
  m_List->Disconnect(wxEVT_LEAVE_WINDOW,
    wxMouseEventHandler(Editor::OnDragQuit));

}
// abort dragging a list item because user has left window
void Editor::OnDragQuit(wxMouseEvent& event)
{
  // restore cursor and disconnect unconditionally
  m_List->SetCursor(wxCursor(*wxSTANDARD_CURSOR));
  m_List->Disconnect(wxEVT_LEFT_UP,
    wxMouseEventHandler(Editor::OnDragEnd));
  m_List->Disconnect(wxEVT_LEAVE_WINDOW,
    wxMouseEventHandler(Editor::OnDragQuit));
}














BEGIN_EVENT_TABLE(anyframe, wxFrame)
...
// more interesting stuff
...
  EVT_LIST_BEGIN_DRAG(ID_LIST_CTRL,		anyframe::OnDragStart)
...
END_EVENT_TABLE()
// m_list is an anyframe class variable pointing to wxListCtrl
// m_drag is an anyframe class variable containing the index value on drag start
// OnDragStart is driven from event table when user starts a drag (left button is down)
void anyframe::OnDragStart(wxListEvent &event)
{
  m_drag = event.GetIndex();	// save the start index
  // do some checks here to make sure valid start
  ...
  // trigger when user releases left button (drop)
  m_list->Connect(wxEVT_LEFT_UP,
    wxMouseEventHandler(anyframe::OnDragEnd), NULL,this);
  // trigger when user leaves window to abort drag
  m_list->Connect(wxEVT_LEAVE_WINDOW,
    wxMouseEventHandler(anyframe::OnDragQuit), NULL,this);
  // give visual feedback that we are doing something
  m_list->SetCursor(wxCursor(wxCURSOR_HAND));
}

// drop a list item (start row is in m_drag)
void anyframe::OnDragEnd(wxMouseEvent& event)
{
  wxPoint pos = event.GetPosition();  // must reference the event
  int flags = wxLIST_HITTEST_ONITEM;
  long index = m_list->HitTest(pos,flags,NULL); // got to use it at last
  if(index >= 0 && index != m_drag){ // valid and not the same as start
    ...
    // do something to move/copy the list control items
    ...
  }
  // restore cursor
  m_list->SetCursor(wxCursor(*wxSTANDARD_CURSOR));
  // disconnect both functions
  m_list->Disconnect(wxEVT_LEFT_UP,
    wxMouseEventHandler(anyframe::OnDragEnd));
  m_list->Disconnect(wxEVT_LEAVE_WINDOW,
    wxMouseEventHandler(anyframe::OnDragQuit));

}
// abort dragging a list item because user has left window
void anyframe::OnDragQuit(wxMouseEvent& event)
{
  // restore cursor and disconnect unconditionally
  m_list->SetCursor(wxCursor(*wxSTANDARD_CURSOR));
  m_list->Disconnect(wxEVT_LEFT_UP,
    wxMouseEventHandler(anyframe::OnDragEnd));
  m_list->Disconnect(wxEVT_LEAVE_WINDOW,
    wxMouseEventHandler(anyframe::OnDragQuit));
}

*/
#include <wx/spinbutt.h>
void Editor::Onm_ButtonSpinChange(wxSpinEvent& event)
{
    int p=m_List->GetFirstSelected();
    if(p<0)
        return;
    if(event.GetInt()==1)
    {
        if(m_List->GetFirstSelected()>0)
        {
            swap(Comm[p],Comm[p-1]);
            swap(Exec[p],Exec[p-1]);
            m_List->SetItem(p,0,Comm[p]);
            m_List->SetItem(p,1,Exec[p]);
            m_List->SetItem(p-1,0,Comm[p-1]);
            m_List->SetItem(p-1,1,Exec[p-1]);
            m_List->Select(p-1);
        }
    }
    else
    {

        if(m_List->GetFirstSelected()<m_List->GetItemCount()-1)
        {
            swap(Comm[p],Comm[p+1]);
            swap(Exec[p],Exec[p+1]);
            m_List->SetItem(p,0,Comm[p]);
            m_List->SetItem(p,1,Exec[p]);
            m_List->SetItem(p+1,0,Comm[p+1]);
            m_List->SetItem(p+1,1,Exec[p+1]);
            m_List->Select(p+1);
        }
    }
//    wxString ichar="";
//    ichar<<(event.GetInt()==1 ? "up" : "down");
//    wxMessageBox(ichar);
}

void Editor::OnClose(wxCloseEvent& event)
{

     if ( event.CanVeto()  )
        if ( wxMessageBox("Esti sigur ca nu vrei sa salvezi?",
                          "Macroul",
                          wxICON_QUESTION | wxYES_NO) != wxYES )
        {
            event.Veto();
            return;
        }
    EndModal(0);
}

void Editor::Onm_ButtonAsteaptaClick(wxCommandEvent& event)
{
    //Asteapta

    DialogEditorAsteapta x(this);
    if(x.ShowModal()==1)
    {
        wxString ichar="Asteapta_schimbare(";
        ichar<<x.m_Radio->GetString(x.m_Radio->GetSelection())<<",";
        ichar<<x.RadioBox1->GetString(x.RadioBox1->GetSelection())<<",";
        if(x.m_Radio->GetSelection()<2)
            ichar<<x.m_Text->GetValue();
        else
        {
            ichar<<x.m_X->GetValue()<<","<<x.m_Y->GetValue();
            if(x.RadioBox1->GetSelection()==0)
                ichar<<","<<x.SpinCtrl1->GetValue()<<","<<x.SpinCtrl2->GetValue()<<","<<x.SpinCtrl3->GetValue();
        }
        ichar<<")";
        Insert(ichar);
    }
}
#include "DialogMacrouSablon.h"
void Editor::Onm_ButtonMacrouClick(wxCommandEvent& event)
{
    DialogMacrouSablon x(this);
    wxString temp="select ID,Nume from macrou where UserID="+UID;
    wxArrayString ID,Nume;
    Connection conn(false);
    if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
    {
        Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
        if (StoreQueryResult res = query.store())
            for (size_t i = 0; i < res.num_rows(); ++i)
            {
                ID.Add(res[i][0].c_str());
                Nume.Add(utf8_decode(res[i][1].c_str()));
                x.m_Macrou->Append(Nume[i]);
            }
    }
    x.Onm_RadioSelect(wxCE);
    if(x.ShowModal()==1)
    {
        wxString ichar="";
        if(x.m_Radio->GetSelection()==0)///macrou
            ichar<<"Macrou("<<ID[x.m_Macrou->GetSelection()]<<")";
        else
            ichar<<"Sablon("<<x.m_Sablon->GetValue()<<")";
        Insert(ichar);
    }
}
