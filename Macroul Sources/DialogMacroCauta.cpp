#include "DialogMacroCauta.h"

//(*InternalHeaders(DialogMacroCauta)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogMacroCauta)
const long DialogMacroCauta::ID_LISTVIEW1 = wxNewId();
const long DialogMacroCauta::ID_STATICTEXT1 = wxNewId();
const long DialogMacroCauta::ID_SPINCTRL1 = wxNewId();
const long DialogMacroCauta::ID_BUTTON2 = wxNewId();
const long DialogMacroCauta::ID_BUTTON3 = wxNewId();
const long DialogMacroCauta::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogMacroCauta,wxDialog)
	//(*EventTable(DialogMacroCauta)
	//*)
END_EVENT_TABLE()

DialogMacroCauta::DialogMacroCauta(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogMacroCauta)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
	SetClientSize(wxSize(700,500));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	m_List = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES|wxLC_VRULES|wxVSCROLL, wxDefaultValidator, _T("ID_LISTVIEW1"));
	FlexGridSizer1->Add(m_List, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("ID Macrou/User"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Search = new wxSpinCtrl(this, ID_SPINCTRL1, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 1000000, 1, _T("ID_SPINCTRL1"));
	m_Search->SetValue(_T("1"));
	FlexGridSizer2->Add(m_Search, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonCauta = new wxButton(this, ID_BUTTON2, _("Cauta"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer2->Add(m_ButtonCauta, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 7, 0, 0);
	m_ButtonAdauga = new wxButton(this, ID_BUTTON3, _("Adauga la lista mea"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer3->Add(m_ButtonAdauga, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonView = new wxButton(this, ID_BUTTON1, _("Vezi macrou"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(m_ButtonView, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	SetSizer(FlexGridSizer1);
	Layout();

	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&DialogMacroCauta::Onm_ListItemActivated);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogMacroCauta::Onm_ButtonCautaClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogMacroCauta::Onm_ButtonAdaugaClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogMacroCauta::Onm_ButtonViewClick);
	//*)

    this->SetPosition(wxPoint(GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));

//    m_Search->SetFocus();
}
#include "Editor.h"
#include "Misc.h"
void DialogMacroCauta::Fill()
{
    m_List->DeleteAllColumns();
    m_List->InsertColumn(0,"ID Macrou",wxLIST_FORMAT_LEFT, 75);
    m_List->InsertColumn(1,"Nume",wxLIST_FORMAT_LEFT, 220);
    m_List->InsertColumn(2,"Descriere",wxLIST_FORMAT_LEFT, 320);
    m_List->InsertColumn(3,"ID Utilizator",wxLIST_FORMAT_LEFT, 75);
    if(m_List->GetItemCount())
        m_List->DeleteAllItems();


        wxString temp="select ID, Nume, Descriere, UserID  from macrou where Public=1 order by rand() ";//limit 10
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
                for (size_t i = 0; i < res.num_rows(); ++i)
                {
                    m_List->InsertItem(i,wxEmptyString);
                    for(int a=0;a<m_List->GetColumnCount();a++)
                        m_List->SetItem(i,a,utf8_decode(res[i][a].c_str()));
                }
        }
}

DialogMacroCauta::~DialogMacroCauta()
{
	//(*Destroy(DialogMacroCauta)
	//*)
}

#include "DialogEditDesc.h"
void DialogMacroCauta::Onm_ButtonAdaugaClick(wxCommandEvent& event)
{
    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza un rand...");
        return;
    }
    DialogEditDesc x(this);
    x.m_Nume->SetValue(m_List->GetItemText(m_List->GetFirstSelected(),1));
    x.m_Descriere->SetValue(m_List->GetItemText(m_List->GetFirstSelected(),2));
    if(x.ShowModal()!=1)return;


    unsigned long long MID=-1;
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"INSERT INTO macrou (Nume,Descriere,UserID,Public,CodMacrou) VALUES ";
            query<<"('"<<escape<<utf8_encode(x.m_Nume->GetValue().wc_str())<<"',";
            query<<"'"<<escape<<utf8_encode(x.m_Descriere->GetValue().wc_str())<<"',";
            query<<UID<<",";
            query<<""<<(int)(x.m_Public->IsChecked()==true)<<",'')";
            Log(query.str().c_str());
            if (!query.execute())
            {
                Log(query.error());
                return ;
            }
            MID=query.insert_id();
        }
        else
        {
            Log("Couldn't connect to DB!");
            return;
        }

    }
    wxString CodMacrou="";
    wxString temp="select CodMacrou from macrou where ID=";
    temp<<m_List->GetItemText(m_List->GetFirstSelected(),0);
    Connection conn(false);
    if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
    {
        Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
        if (StoreQueryResult res = query.store())
            CodMacrou=utf8_decode(res[0][0].c_str());
    }

    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"update macrou set CodMacrou='"<<escape<<utf8_encode(CodMacrou.wc_str())<<"' where ID = "<<MID;
            Log(query.str().c_str());
            if (!query.execute())
            {
                Log(query.error());
                return ;
            }
        }
    }
}
#include "DialogViewMacro.h"
#include <wx/tokenzr.h>
void DialogMacroCauta::Onm_ButtonViewClick(wxCommandEvent& event)
{
    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza un rand...");
        return;
    }
    DialogViewMacro x(this);
    x.m_List->DeleteAllColumns();
    x.m_List->InsertColumn(0,"Comentariu",wxLIST_FORMAT_LEFT, 250);
    x.m_List->InsertColumn(1,"Actiune",wxLIST_FORMAT_LEFT, 520);
    if(x.m_List->GetItemCount())
        x.m_List->DeleteAllItems();




        wxString CodMacrou="";
        wxString temp="select CodMacrou from macrou where ID=";
        temp<<m_List->GetItemText(m_List->GetFirstSelected(),0);
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
                CodMacrou=utf8_decode(res[0][0].c_str());
        }
        wxStringTokenizer tok(CodMacrou, "\n");
        int a=0;
        while(tok.HasMoreTokens())
        {
            wxString da=tok.GetNextToken();
            if(da.IsEmpty())
                da="|||Asteapta(1)";
            int poz=da.find("|||");
            wxString q1=da.substr(0,poz);
            wxString q2=da.substr(poz+3);
            //q2.Replace("|||","");
            q1.Replace("<nl>","\n");
            q2.Replace("<nl>","\n");
            x.m_List->InsertItem(a,"");
            x.m_List->SetItem(a,0,q1);
            x.m_List->SetItem(a,1,q2);
            a++;
        }




    x.ShowModal();
}
#include <cctype>
#include <string>
#include <functional>

void DialogMacroCauta::Onm_SearchText(wxCommandEvent& event)
{

}

void DialogMacroCauta::Onm_ButtonCautaClick(wxCommandEvent& event)
{
    unsigned long long maybe=m_Search->GetValue();
    if(m_List->GetItemCount())
        m_List->DeleteAllItems();

    wxString temp="select ID, Nume, Descriere, UserID  from macrou where Public=1 and (ID = ";
    temp<<maybe<<" or UserID = "<<maybe<<" ) order by rand() ";
    Connection conn(false);
    if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
    {
        Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
        if (StoreQueryResult res = query.store())
            for (size_t i = 0; i < res.num_rows(); ++i)
            {
                m_List->InsertItem(i,wxEmptyString);
                for(int a=0;a<m_List->GetColumnCount();a++)
                    m_List->SetItem(i,a,utf8_decode(res[i][a].c_str()));
            }
    }
}

void DialogMacroCauta::Onm_ListItemActivated(wxListEvent& event)
{
    Onm_ButtonViewClick(wxCE);
}
