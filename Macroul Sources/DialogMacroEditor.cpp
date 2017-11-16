#include "DialogMacroEditor.h"

//(*InternalHeaders(DialogMacroEditor)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogMacroEditor)
const long DialogMacroEditor::ID_LISTVIEW1 = wxNewId();
const long DialogMacroEditor::ID_BUTTON1 = wxNewId();
const long DialogMacroEditor::ID_BUTTON2 = wxNewId();
const long DialogMacroEditor::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogMacroEditor,wxDialog)
	//(*EventTable(DialogMacroEditor)
	//*)
END_EVENT_TABLE()

DialogMacroEditor::DialogMacroEditor(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogMacroEditor)
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

	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&DialogMacroEditor::Onm_ListItemActivated);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogMacroEditor::Onm_ButtonAddClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogMacroEditor::Onm_ButtonEditeazaClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogMacroEditor::Onm_ButtonStergeClick);
	//*)

    this->SetPosition(wxPoint(GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));

}

DialogMacroEditor::~DialogMacroEditor()
{
	//(*Destroy(DialogMacroEditor)
	//*)
}

#include "DialogEditDesc.h"
#include "Editor.h"

void DialogMacroEditor::Fill()
{
    m_List->DeleteAllColumns();
    m_List->InsertColumn(0,"ID",wxLIST_FORMAT_LEFT, 70);
    m_List->InsertColumn(1,"Nume",wxLIST_FORMAT_LEFT, 200);
    m_List->InsertColumn(2,"Descriere",wxLIST_FORMAT_LEFT, 300);
    m_List->InsertColumn(3,"Public",wxLIST_FORMAT_LEFT, 50);
    if(m_List->GetItemCount())
        m_List->DeleteAllItems();


        wxString temp="select ID, Nume, Descriere, case Public when 1 then 'Da' else 'Nu' end  from macrou where UserID="+UID;
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
#include "Database.h"
void DialogMacroEditor::Onm_ButtonAddClick(wxCommandEvent& event)
{
    DialogEditDesc x(this);
    if(x.ShowModal()!=1)return;

    for(int a=0;a<m_List->GetItemCount();a++)
        if(x.m_Nume->GetValue()==m_List->GetItemText(a,1))
        {
            wxMessageBox("Mai exista un macrou cu numele asta!");
            return;
        }

    Editor y(this);
    y.UID=UID;
    if(y.ShowModal()!=1)return;
    unsigned long long MID=-1;
    Connection conn(false);
    wxString CodMacrou="";
    for(int a=0;a<y.m_List->GetItemCount();a++)
    {
        wxString ichar="";
        ichar<<y.Comm[a]<<"|||"<<y.Exec[a];
        ichar.Replace("\n","<nl>");
        CodMacrou<<ichar<<"\n";
    }
    if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
    {
        Query query = conn.query();
        query<<"INSERT INTO macrou (Nume,Descriere,UserID,Public,CodMacrou) VALUES ";
        query<<"('"<<escape<<utf8_encode(x.m_Nume->GetValue().wc_str())<<"',";
        query<<"'"<<escape<<utf8_encode(x.m_Descriere->GetValue().wc_str())<<"',";
        query<<UID<<",";
        query<<""<<(int)(x.m_Public->IsChecked()==true)<<",'"<<escape<<utf8_encode(CodMacrou.wc_str())<<"')";
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
    Fill();
}
#include <wx/tokenzr.h>
void DialogMacroEditor::Onm_ButtonEditeazaClick(wxCommandEvent& event)
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
        wxMessageBox("Mai exista un macrou cu numele asta!");
        return;
    }

    Editor y(this);
    y.UID=UID;
    {
        if(y.m_List->GetItemCount())
            y.m_List->DeleteAllItems();
        y.Comm.Empty();
        y.Exec.Empty();
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
            y.Comm.Insert(q1,a);
            y.Exec.Insert(q2,a);
            y.m_List->InsertItem(a,"");
            y.m_List->SetItem(a,0,q1);
            y.m_List->SetItem(a,1,q2);
            a++;
        }
    }
    if(y.ShowModal()!=1)return;
    {

        wxString CodMacrou="";
        for(int a=0;a<y.m_List->GetItemCount();a++)
        {
            wxString ichar="";
            ichar<<y.Comm[a]<<"|||"<<y.Exec[a];
            ichar.Replace("\n","<nl>");
            CodMacrou<<ichar<<"\n";
        }


        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"update macrou set Nume='"<<escape<<utf8_encode(x.m_Nume->GetValue().wc_str())<<"',";
            query<<"Descriere='"<<escape<<utf8_encode(x.m_Descriere->GetValue().wc_str())<<"',Public="<<(int)(x.m_Public->IsChecked()==true)<<",";
            query<<"CodMacrou='"<<escape<<utf8_encode(CodMacrou.wc_str())<<"' ";
            query<<" where ID="<<m_List->GetItemText(m_List->GetFirstSelected(),0);
            Log(query.str().c_str());
            if (!query.execute())
            {
                Log(query.error());
                return ;
            }
        }
    }
    MacroulFrame* p_foo = static_cast<MacroulFrame*>(framed);
        p_foo->initTriggers();
    Fill();
}

void DialogMacroEditor::Onm_ButtonStergeClick(wxCommandEvent& event)
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
        query<<"delete from macrou where ID = "+m_List->GetItemText(m_List->GetFirstSelected(),0);
        Log(query.str().c_str());
        if (!query.execute())
        {
            Log(query.error());
            return ;
        }
        query.reset();
        query<<"delete from activator where MacrouID = "+m_List->GetItemText(m_List->GetFirstSelected(),0);
        query.execute();
        MacroulFrame* p_foo = static_cast<MacroulFrame*>(framed);
        p_foo->initTriggers();
    }
    else
    {
        Log("Couldn't connect to DB!");
        return;
    }
    Fill();
}

void DialogMacroEditor::Onm_ListItemActivated(wxListEvent& event)
{
    ///Onm_ButtonEditeazaClick(wxCE);
    Onm_ButtonEditeazaClick(wxCE);
}
