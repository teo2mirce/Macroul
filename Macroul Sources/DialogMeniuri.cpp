#include "DialogMeniuri.h"

//(*InternalHeaders(DialogMeniuri)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogMeniuri)
const long DialogMeniuri::ID_LISTVIEW1 = wxNewId();
const long DialogMeniuri::ID_BUTTON1 = wxNewId();
const long DialogMeniuri::ID_BUTTON2 = wxNewId();
const long DialogMeniuri::ID_BUTTON5 = wxNewId();
const long DialogMeniuri::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogMeniuri,wxDialog)
	//(*EventTable(DialogMeniuri)
	//*)
END_EVENT_TABLE()

DialogMeniuri::DialogMeniuri(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogMeniuri)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("id"));
	SetClientSize(wxSize(800,600));
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	m_List = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES|wxLC_VRULES|wxVSCROLL, wxDefaultValidator, _T("ID_LISTVIEW1"));
	FlexGridSizer1->Add(m_List, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 7, 0, 0);
	m_ButtonAdd = new wxButton(this, ID_BUTTON1, _("Adauga"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(m_ButtonAdd, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonEdit = new wxButton(this, ID_BUTTON2, _("Editeaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer3->Add(m_ButtonEdit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonDelete = new wxButton(this, ID_BUTTON5, _("Sterge"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	FlexGridSizer3->Add(m_ButtonDelete, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonSet = new wxButton(this, ID_BUTTON3, _("Meniu preferat"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer3->Add(m_ButtonSet, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	SetSizer(FlexGridSizer1);
	Layout();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogMeniuri::Onm_ButtonAddClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogMeniuri::Onm_ButtonEditClick);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogMeniuri::Onm_ButtonDeleteClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogMeniuri::Onm_ButtonSetClick);
	//*)
	    this->SetPosition(wxPoint(GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));

}

DialogMeniuri::~DialogMeniuri()
{
	//(*Destroy(DialogMeniuri)
	//*)
}
#include "Misc.h"
#include "Editor.h"
void DialogMeniuri::Fill()
{
    wxString MP="";
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"select nume from meniupreferat where UserID="<<UID;
            if (StoreQueryResult res = query.store())
                for (size_t i = 0; i < res.num_rows(); ++i)
                    MP=utf8_decode(res[0][0].c_str());
        }
    }


    m_List->DeleteAllColumns();
    m_List->InsertColumn(0,"Meniu",wxLIST_FORMAT_LEFT, 200);
    for(int a=1;a<=9;a++)
    {
        wxString temp="Macrou";
        temp<<a;
        m_List->InsertColumn(a,temp,wxLIST_FORMAT_LEFT, 100);
    }
    if(m_List->GetItemCount())
        m_List->DeleteAllItems();
    wxString temp="SELECT Nume,COALESCE((SELECT Nume from macrou WHERE ID=M1),'') M1,COALESCE((SELECT Nume from macrou WHERE ID=M2),'') M2,COALESCE((SELECT Nume from macrou WHERE ID=M3),'') M3,COALESCE((SELECT Nume from macrou WHERE ID=M4),'') M4,COALESCE((SELECT Nume from macrou WHERE ID=M5),'') M5,COALESCE((SELECT Nume from macrou WHERE ID=M6),'') M6,COALESCE((SELECT Nume from macrou WHERE ID=M7),'') M7,COALESCE((SELECT Nume from macrou WHERE ID=M8),'') M8,COALESCE((SELECT Nume from macrou WHERE ID=M9),'') M9 FROM meniuri WHERE UserID ="+UID;
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
                if(m_List->GetItemText(i,0)==MP)
                    m_List->SetItemBackgroundColour(i,wxColor(120,220,120));
            }
    }
}
#include "DialogMeniuriAddEdit.h"
#include "wx/choice.h"
void DialogMeniuri::Onm_ButtonAddClick(wxCommandEvent& event)
{
    DialogMeniuriAddEdit x(this);

    wxArrayString Nume,ID;
    {
        wxString temp="select Nume, ID from macrou where UserID="+UID;
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
                for (size_t i = 0; i < res.num_rows(); ++i)
                {
                    Nume.Add(utf8_decode(res[i][0].c_str()));
                    ID.Add(res[i][1].c_str());
                    x.Choice1->Append(Nume[i]);
                    x.Choice2->Append(Nume[i]);
                    x.Choice3->Append(Nume[i]);
                    x.Choice4->Append(Nume[i]);
                    x.Choice5->Append(Nume[i]);
                    x.Choice6->Append(Nume[i]);
                    x.Choice7->Append(Nume[i]);
                    x.Choice8->Append(Nume[i]);
                    x.Choice9->Append(Nume[i]);
                }
        }
    }
    x.Layout();
    x.Fit();
    if(x.ShowModal()==1)
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"INSERT INTO `meniuri`(`UserID`, `Nume`, `M1`, `M2`, `M3`, `M4`, `M5`, `M6`, `M7`, `M8`, `M9`) VALUES (";
            query<<UID<<",'"<<escape<<utf8_encode(x.m_Text->GetValue().wc_str())<<"'";
            query<<",";if(x.Choice1->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice1->GetString(x.Choice1->GetSelection()))];
            query<<",";if(x.Choice2->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice2->GetString(x.Choice2->GetSelection()))];
            query<<",";if(x.Choice3->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice3->GetString(x.Choice3->GetSelection()))];
            query<<",";if(x.Choice4->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice4->GetString(x.Choice4->GetSelection()))];
            query<<",";if(x.Choice5->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice5->GetString(x.Choice5->GetSelection()))];
            query<<",";if(x.Choice6->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice6->GetString(x.Choice6->GetSelection()))];
            query<<",";if(x.Choice7->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice7->GetString(x.Choice7->GetSelection()))];
            query<<",";if(x.Choice8->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice8->GetString(x.Choice8->GetSelection()))];
            query<<",";if(x.Choice9->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice9->GetString(x.Choice9->GetSelection()))];
            query<<")";
            Log(query.str().c_str());
            if (!query.execute())
            {
                Log(query.error());
                return ;
            }
            Fill();
        }
        else
        {
            Log("Couldn't connect to DB!");
            return;
        }
    }
}

void DialogMeniuri::Onm_ButtonEditClick(wxCommandEvent& event)
{
    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza un rand");
        return;
    }
    DialogMeniuriAddEdit x(this);
    x.m_Text->SetValue(m_List->GetItemText(m_List->GetFirstSelected(),0));



    wxArrayString Nume,ID;
    {
        wxString temp="select Nume, ID from macrou where UserID="+UID;
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
                for (size_t i = 0; i < res.num_rows(); ++i)
                {
                    Nume.Add(utf8_decode(res[i][0].c_str()));
                    ID.Add(res[i][1].c_str());
                    x.Choice1->Append(Nume[i]);
                    x.Choice2->Append(Nume[i]);
                    x.Choice3->Append(Nume[i]);
                    x.Choice4->Append(Nume[i]);
                    x.Choice5->Append(Nume[i]);
                    x.Choice6->Append(Nume[i]);
                    x.Choice7->Append(Nume[i]);
                    x.Choice8->Append(Nume[i]);
                    x.Choice9->Append(Nume[i]);
                }
        }
    }
    x.Choice1->SetSelection(Nume.Index(m_List->GetItemText(m_List->GetFirstSelected(),1)));
    x.Choice2->SetSelection(Nume.Index(m_List->GetItemText(m_List->GetFirstSelected(),2)));
    x.Choice3->SetSelection(Nume.Index(m_List->GetItemText(m_List->GetFirstSelected(),3)));
    x.Choice4->SetSelection(Nume.Index(m_List->GetItemText(m_List->GetFirstSelected(),4)));
    x.Choice5->SetSelection(Nume.Index(m_List->GetItemText(m_List->GetFirstSelected(),5)));
    x.Choice6->SetSelection(Nume.Index(m_List->GetItemText(m_List->GetFirstSelected(),6)));
    x.Choice7->SetSelection(Nume.Index(m_List->GetItemText(m_List->GetFirstSelected(),7)));
    x.Choice8->SetSelection(Nume.Index(m_List->GetItemText(m_List->GetFirstSelected(),8)));
    x.Choice9->SetSelection(Nume.Index(m_List->GetItemText(m_List->GetFirstSelected(),9)));


    x.Layout();
    x.Fit();
    if(x.ShowModal()==1)
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"update `meniuri` set Nume='"<<escape<<utf8_encode(x.m_Text->GetValue().wc_str())<<"' ";

            query<<",M1=";if(x.Choice1->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice1->GetString(x.Choice1->GetSelection()))];
            query<<",M2=";if(x.Choice2->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice2->GetString(x.Choice2->GetSelection()))];
            query<<",M3=";if(x.Choice3->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice3->GetString(x.Choice3->GetSelection()))];
            query<<",M4=";if(x.Choice4->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice4->GetString(x.Choice4->GetSelection()))];
            query<<",M5=";if(x.Choice5->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice5->GetString(x.Choice5->GetSelection()))];
            query<<",M6=";if(x.Choice6->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice6->GetString(x.Choice6->GetSelection()))];
            query<<",M7=";if(x.Choice7->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice7->GetString(x.Choice7->GetSelection()))];
            query<<",M8=";if(x.Choice8->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice8->GetString(x.Choice8->GetSelection()))];
            query<<",M9=";if(x.Choice9->GetSelection()==-1)query<<"-1";else query<<ID[Nume.Index(x.Choice9->GetString(x.Choice9->GetSelection()))];


            query<<" where UserID="<<UID;
            query<<" and Nume='"<<escape<<utf8_encode(m_List->GetItemText(m_List->GetFirstSelected(),0).wc_str())<<"'";
            Log(query.str().c_str());
            if (!query.execute())
            {
                Log(query.error());
                return ;
            }
            Fill();
        }
        else
        {
            Log("Couldn't connect to DB!");
            return;
        }
    }
}

void DialogMeniuri::Onm_ButtonDeleteClick(wxCommandEvent& event)
{
    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza un rand");
        return;
    }
    if(wxMessageBox("Esti sigur ca vrei sa stergi asta?","Macroul",wxYES_NO)!=wxYES )
        return;
    Connection conn(false);
    if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
    {
        Query query = conn.query();
        query<<"delete from meniuri where UserID="<<UID;
        query<<" and Nume='"<<escape<<utf8_encode(m_List->GetItemText(m_List->GetFirstSelected(),0).wc_str())<<"'";
        Log(query.str().c_str());
        if (!query.execute())
        {
            Log(query.error());
            return ;
        }
        Fill();
    }
    else
    {
        Log("Couldn't connect to DB!");
        return;
    }
}

void DialogMeniuri::Onm_ButtonSetClick(wxCommandEvent& event)
{

    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza un rand");
        return;
    }

    Connection conn(false);
    if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
    {
        Query query = conn.query();
        query<<"delete from meniupreferat where UserID="<<UID;
        Log(query.str().c_str());
        if (!query.execute())
        {
            Log(query.error());
            return ;
        }
        query.reset();
        query<<"INSERT INTO `meniupreferat`(`UserID`, `Nume`) VALUES ("<<UID<<",'"<<escape<<utf8_encode(m_List->GetItemText(m_List->GetFirstSelected(),0).wc_str())<<"')";
        query.execute();


        Fill();
    }
}
