#include "DialogNLPEditor.h"

//(*InternalHeaders(DialogNLPEditor)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogNLPEditor)
const long DialogNLPEditor::ID_LISTVIEW1 = wxNewId();
const long DialogNLPEditor::ID_BUTTON1 = wxNewId();
const long DialogNLPEditor::ID_BUTTON2 = wxNewId();
const long DialogNLPEditor::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogNLPEditor,wxDialog)
	//(*EventTable(DialogNLPEditor)
	//*)
END_EVENT_TABLE()

DialogNLPEditor::DialogNLPEditor(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogNLPEditor)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxSize(700,500));
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	m_List = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES|wxLC_VRULES|wxVSCROLL, wxDefaultValidator, _T("ID_LISTVIEW1"));
	FlexGridSizer1->Add(m_List, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 7, 0, 0);
	m_ButtonAdd = new wxButton(this, ID_BUTTON1, _("Adauga"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(m_ButtonAdd, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonEditeaza = new wxButton(this, ID_BUTTON2, _("Editeaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer3->Add(m_ButtonEditeaza, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonSterge = new wxButton(this, ID_BUTTON3, _("Sterge"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer3->Add(m_ButtonSterge, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	SetSizer(FlexGridSizer1);
	Layout();

	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&DialogNLPEditor::Onm_ListItemActivated);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogNLPEditor::Onm_ButtonAddClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogNLPEditor::Onm_ButtonEditeazaClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogNLPEditor::Onm_ButtonStergeClick);
	//*)

    this->SetPosition(wxPoint(GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));




}

DialogNLPEditor::~DialogNLPEditor()
{
	//(*Destroy(DialogNLPEditor)
	//*)
}


#include "DialogNLP.h"
#include "DialogEditDesc.h"
#include <mysql++.h>
#include "Database.h"
#include <wx/tokenzr.h>
#include "Misc.h"
#include "Editor.h"
using namespace mysqlpp;
void DialogNLPEditor::Fill()
{

    m_List->DeleteAllColumns();
    m_List->InsertColumn(0,"ID",wxLIST_FORMAT_LEFT, 50);
    m_List->InsertColumn(1,"Nume",wxLIST_FORMAT_LEFT, 100);
    m_List->InsertColumn(2,"Descriere",wxLIST_FORMAT_LEFT, 200);
    m_List->InsertColumn(3,"Public",wxLIST_FORMAT_LEFT, 50);
    m_List->InsertColumn(4,"Forma",wxLIST_FORMAT_LEFT, 200);
    if(m_List->GetItemCount())
        m_List->DeleteAllItems();


        wxString temp="select ID, Nume, Descriere, case Public when 1 then 'Da' else 'Nu' end , Forma  from sablon where UserID="+UID;
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
void DialogNLPEditor::Onm_ButtonAddClick(wxCommandEvent& event)
{
    DialogEditDesc x(this);
    if(x.ShowModal()!=1)return;

    for(int a=0;a<m_List->GetItemCount();a++)
    if(x.m_Nume->GetValue()==m_List->GetItemText(a,1))
    {
        wxMessageBox("Mai exista un sablon cu numele asta!");
        return;
    }

    DialogNLP y(this);
    y.UID=UID;
    y.AIDI="";
    if(y.ShowModal()!=1)return;
    Connection conn(false);
    wxString Text="";
    for(int a=0;a<y.m_List->GetItemCount();a++)
    {
        wxString ichar="";
        ichar<<y.m_List->GetItemText(a,ID_TIP)<<"<|MAC|>"<<y.m_List->GetItemText(a,ID_SEPARATOR)<<"<|MAC|>"<<y.m_List->GetItemText(a,ID_NUME);
        Text<<ichar<<"\n";
    }
    if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
    {
        Query query = conn.query();
        query<<"INSERT INTO `sablon`(`Nume`, `Descriere`, `UserID`, `Public`, `Text`, `CodMacrou`,Inceput,Forma) VALUES ";
        query<<"('"<<escape<<utf8_encode(x.m_Nume->GetValue().wc_str())<<"',";
        query<<"'"<<escape<<utf8_encode(x.m_Descriere->GetValue().wc_str())<<"',";
        query<<UID<<",";
        query<<""<<(int)(x.m_Public->IsChecked()==true)<<",";
        query<<"'"<<escape<<utf8_encode(Text.wc_str())<<"',";
        query<<"'"<<escape<<utf8_encode(y.m_TextCode->GetValue().wc_str())<<"',";
        query<<"'"<<escape<<utf8_encode(y.m_List->GetItemText(0,ID_NUME).wc_str())<<"',";
        query<<"'"<<escape<<utf8_encode(y.m_Rezultat->GetValue().wc_str())<<"'";
        query<<")";
        Log(query.str().c_str());
        if (!query.execute())
        {
            Log(query.error());
            return ;
        }
    }
    else
    {
        Log("Couldn't connect to DB!");
        return;
    }
    Fill();
}

void DialogNLPEditor::Onm_ButtonEditeazaClick(wxCommandEvent& event)
{
    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza un rand...");
        return;
    }
    DialogEditDesc x(this);
    x.m_Nume->SetValue(m_List->GetItemText(m_List->GetFirstSelected(),1));
    x.m_Descriere->SetValue(m_List->GetItemText(m_List->GetFirstSelected(),2));
    if(m_List->GetItemText(m_List->GetFirstSelected(),3).compare("Da")==0)
        x.m_Public->SetValue(1);
    else
        x.m_Public->SetValue(0);
    if(x.ShowModal()!=1)return;

    for(int a=0;a<m_List->GetItemCount();a++)
    if(x.m_Nume->GetValue()==m_List->GetItemText(a,1))
    if(a!=m_List->GetFirstSelected())
    {
        wxMessageBox("Mai exista un sablon cu numele asta!");
        return;
    }


    DialogNLP y(this);
    y.UID=UID;
    y.AIDI=m_List->GetItemText(m_List->GetFirstSelected(),0);
    {
        wxString CodMacrou;
        wxString Text;
        wxString Forma;
        wxString temp="select CodMacrou,Text,Forma from sablon where ID=";
        temp<<m_List->GetItemText(m_List->GetFirstSelected(),0);
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
                CodMacrou=utf8_decode(res[0][0].c_str()),
                Text=utf8_decode(res[0][1].c_str()),
                Forma=utf8_decode(res[0][2].c_str());
        }
        y.m_TextCode->SetValue(CodMacrou);
        y.m_Rezultat->SetValue(Forma);


        wxStringTokenizer tok(Text, "\n");
        int a=0;
        while(tok.HasMoreTokens())
        {
            wxString da=tok.GetNextToken();
            int poz=da.find("<|MAC|>");
            wxString q1=da.substr(0,poz);
            wxString q=da.substr(poz+7);
            int poz2=q.find("<|MAC|>");
            wxString q2=q.substr(0,poz2);
            wxString q3=q.substr(poz2+7);
            y.m_List->InsertItem(a,"");
            y.m_List->SetItem(a,ID_TIP,q1);
            y.m_List->SetItem(a,ID_SEPARATOR,q2);
            y.m_List->SetItem(a,ID_NUME,q3);
            a++;
        }
    }
    if(y.ShowModal()!=1)return;

    wxString Text="";
    for(int a=0;a<y.m_List->GetItemCount();a++)
    {
        wxString ichar="";
        ichar<<y.m_List->GetItemText(a,ID_TIP)<<"<|MAC|>"<<y.m_List->GetItemText(a,ID_SEPARATOR)<<"<|MAC|>"<<y.m_List->GetItemText(a,ID_NUME);
        Text<<ichar<<"\n";
    }
    Connection conn(false);
    if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
    {
        Query query = conn.query();
        query<<"update sablon set Nume='"<<escape<<utf8_encode(x.m_Nume->GetValue().wc_str())<<"',";
        query<<"Descriere='"<<escape<<utf8_encode(x.m_Descriere->GetValue().wc_str())<<"',Public="<<(int)(x.m_Public->IsChecked()==true)<<",";
        query<<"Text='"<<escape<<utf8_encode(Text.wc_str())<<"', ";
        query<<"CodMacrou='"<<escape<<utf8_encode(y.m_TextCode->GetValue().wc_str())<<"', ";
        query<<"Inceput='"<<escape<<utf8_encode(y.m_List->GetItemText(0,ID_NUME).wc_str())<<"',";
        query<<"Forma='"<<escape<<utf8_encode(y.m_Rezultat->GetValue().wc_str())<<"'";

        query<<" where ID="<<m_List->GetItemText(m_List->GetFirstSelected(),0);
        Log(query.str().c_str());
        if (!query.execute())
        {
            Log(query.error());
            return ;
        }
    }
    else
    {
        Log("Couldn't connect to DB!");
        return;
    }
    Fill();
}

void DialogNLPEditor::Onm_ButtonStergeClick(wxCommandEvent& event)
{
    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza o linie...");
        return;
    }
    if(wxMessageBox("Esti sigur ca vrei sa stergi asta?","Macroul",wxYES_NO)!=wxYES )
        return;
    Connection conn(false);
    if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
    {
        Query query = conn.query();
        query<<"delete from sablon where ID = "+m_List->GetItemText(m_List->GetFirstSelected(),0);
        Log(query.str().c_str());
        if (!query.execute())
        {
            Log(query.error());
            return ;
        }
    }
    else
    {
        Log("Couldn't connect to DB!");
        return;
    }
    Fill();
}

void DialogNLPEditor::Onm_ListItemActivated(wxListEvent& event)
{
    Onm_ButtonEditeazaClick(wxCE);
}
