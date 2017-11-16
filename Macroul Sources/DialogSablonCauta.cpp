#include "DialogSablonCauta.h"

//(*InternalHeaders(DialogSablonCauta)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogSablonCauta)
const long DialogSablonCauta::ID_LISTVIEW1 = wxNewId();
const long DialogSablonCauta::ID_STATICTEXT1 = wxNewId();
const long DialogSablonCauta::ID_SPINCTRL1 = wxNewId();
const long DialogSablonCauta::ID_BUTTON2 = wxNewId();
const long DialogSablonCauta::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogSablonCauta,wxDialog)
	//(*EventTable(DialogSablonCauta)
	//*)
END_EVENT_TABLE()

DialogSablonCauta::DialogSablonCauta(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogSablonCauta)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxSize(700,500));
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	m_List = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES|wxLC_VRULES|wxVSCROLL, wxDefaultValidator, _T("ID_LISTVIEW1"));
	FlexGridSizer1->Add(m_List, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("ID Sablon/User"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
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
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	SetSizer(FlexGridSizer1);
	Layout();

	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&DialogSablonCauta::Onm_ListItemActivated);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogSablonCauta::Onm_ButtonCautaClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogSablonCauta::Onm_ButtonAdaugaClick);
	//*)
	    this->SetPosition(wxPoint(GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));

}

DialogSablonCauta::~DialogSablonCauta()
{
	//(*Destroy(DialogSablonCauta)
	//*)
}
#include "Misc.h"
#include "Editor.h"
void DialogSablonCauta::Fill()
{
    m_List->DeleteAllColumns();
    m_List->InsertColumn(0,"ID",wxLIST_FORMAT_LEFT, 50);
    m_List->InsertColumn(1,"Nume",wxLIST_FORMAT_LEFT, 100);
    m_List->InsertColumn(2,"Descriere",wxLIST_FORMAT_LEFT, 200);
    m_List->InsertColumn(3,"Public",wxLIST_FORMAT_LEFT, 50);
    m_List->InsertColumn(4,"Forma",wxLIST_FORMAT_LEFT, 200);
    if(m_List->GetItemCount())
        m_List->DeleteAllItems();


        wxString temp="select ID, Nume, Descriere, case Public when 1 then 'Da' else 'Nu' end , Forma  from sablon where Public=1 order by rand() ";
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

void DialogSablonCauta::Onm_ButtonCautaClick(wxCommandEvent& event)
{
    unsigned long long maybe=m_Search->GetValue();
    if(m_List->GetItemCount())
        m_List->DeleteAllItems();

    wxString temp="select ID, Nume, Descriere, case Public when 1 then 'Da' else 'Nu' end , Forma  from sablon where Public=1 and (ID = ";
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

#include "DialogEditDesc.h"
void DialogSablonCauta::Onm_ButtonAdaugaClick(wxCommandEvent& event)
{
    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza un rand...");
        return;
    }


    ///check
    wxString start="";
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"Select Inceput from sablon where ID= "+m_List->GetItemText(m_List->GetFirstSelected(),0);
            if (StoreQueryResult res = query.store())
                for (size_t i = 0; i < res.num_rows(); ++i)
                    start=utf8_decode(res[0][0].c_str());
        }
    }
    if(start=="")
    {
        Log("?");
        return;
    }
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"Select Inceput from sablon where UserID= "+UID;
            if (StoreQueryResult res = query.store())
            {
                for (size_t i = 0; i < res.num_rows(); ++i)
                {
                    wxString poate=utf8_decode(res[i][0].c_str());
                    if(poate.StartsWith(start) || start.StartsWith(poate))
                    {
                        wxMessageBox("Mai exista un sablon care incepe asa");
                        return;
                    }
                }
            }
        }
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
            query<<"INSERT INTO sablon (Nume,Descriere,UserID,Public,Text,CodMacrou,Inceput,Forma) VALUES ";
            query<<"('"<<escape<<utf8_encode(x.m_Nume->GetValue().wc_str())<<"',";
            query<<"'"<<escape<<utf8_encode(x.m_Descriere->GetValue().wc_str())<<"',";
            query<<UID<<",";
            query<<""<<(int)(x.m_Public->IsChecked()==true)<<",'','','','')";
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
    wxString Inceput="";
    wxString Forma="";
    wxString Text="";
    wxString temp="select CodMacrou,Inceput,Forma,Text from sablon where ID=";
    temp<<m_List->GetItemText(m_List->GetFirstSelected(),0);
    Connection conn(false);
    if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
    {
        Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
        if (StoreQueryResult res = query.store())
            CodMacrou=utf8_decode(res[0][0].c_str()),
            Inceput=utf8_decode(res[0][1].c_str()),
            Forma=utf8_decode(res[0][2].c_str()),
            Text=utf8_decode(res[0][3].c_str());
    }

    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"update sablon set Text='"<<escape<<utf8_encode(Text.wc_str())<<"',CodMacrou='"<<escape<<utf8_encode(CodMacrou.wc_str())<<"',Inceput='"<<escape<<Inceput.data().AsChar()<<"',Forma='"<<escape<<utf8_encode(Forma.wc_str())<<"' where ID = "<<MID;
            Log(query.str().c_str());
            if (!query.execute())
            {
                Log(query.error());
                return ;
            }
        }
    }
}

void DialogSablonCauta::Onm_ListItemActivated(wxListEvent& event)
{
}
