#include "DialogCalculatoare.h"

//(*InternalHeaders(DialogCalculatoare)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogCalculatoare)
const long DialogCalculatoare::ID_LISTVIEW1 = wxNewId();
const long DialogCalculatoare::ID_BUTTON1 = wxNewId();
const long DialogCalculatoare::ID_BUTTON2 = wxNewId();
const long DialogCalculatoare::ID_BUTTON5 = wxNewId();
const long DialogCalculatoare::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogCalculatoare,wxDialog)
	//(*EventTable(DialogCalculatoare)
	//*)
END_EVENT_TABLE()

DialogCalculatoare::DialogCalculatoare(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogCalculatoare)
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
	m_ButtonSet = new wxButton(this, ID_BUTTON3, _("Seteaza/deseteaza acest calculator"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer3->Add(m_ButtonSet, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	SetSizer(FlexGridSizer1);
	Layout();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogCalculatoare::Onm_ButtonAddClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogCalculatoare::Onm_ButtonEditClick);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogCalculatoare::Onm_ButtonDeleteClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogCalculatoare::Onm_ButtonSetClick);
	//*)
    //this->Layout();
    //this->Fit();
    this->SetPosition(wxPoint(GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));
}
#include "Editor.h"
void DialogCalculatoare::Fill()
{
    m_List->DeleteAllColumns();
    m_List->InsertColumn(0,"Nume",wxLIST_FORMAT_LEFT, 200);
    m_List->InsertColumn(1,"Ultima activitate",wxLIST_FORMAT_LEFT, 300);
    if(m_List->GetItemCount())
        m_List->DeleteAllItems();
    wxString temp="select Nume, LastActivity from calculatoare where UserID="+UID;
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
                if(m_List->GetItemText(i,0)==ReadDatas(1))
                    m_List->SetItemBackgroundColour(i,wxColor(120,220,120));
            }
    }
}

DialogCalculatoare::~DialogCalculatoare()
{
	//(*Destroy(DialogCalculatoare)
	//*)
}

#include "DialogCalculatoareAddEdit.h"
void DialogCalculatoare::Onm_ButtonAddClick(wxCommandEvent& event)
{
    DialogCalculatoareAddEdit x(this);
    if(x.ShowModal()==1)
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"INSERT INTO `calculatoare`(`UserID`, `Nume`) VALUES (";
            query<<UID<<",'"<<escape<<utf8_encode(x.m_Text->GetValue().wc_str())<<"')";
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

void DialogCalculatoare::Onm_ButtonEditClick(wxCommandEvent& event)
{
    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza un rand");
        return;
    }
    DialogCalculatoareAddEdit x(this);
    x.m_Text->SetValue(m_List->GetItemText(m_List->GetFirstSelected(),0));
    if(x.ShowModal()==1)
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"update `calculatoare` set Nume='"<<escape<<utf8_encode(x.m_Text->GetValue().wc_str())<<"' where UserID="<<UID;
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

void DialogCalculatoare::Onm_ButtonDeleteClick(wxCommandEvent& event)
{

    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza un rand");
        return;
    }
    if(wxMessageBox("Esti sigur ca vrei sa stergi asta?","Macroul",wxYES_NO)!=wxYES )
        return;
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"delete from calculatoare where UserID="<<UID;
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

    if(ReadDatas(1)!="")
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"select * from calculatoare where UserID="<<UID<<" and Nume='"<<escape<<utf8_encode(ReadDatas(1).wc_str())<<"'";
            Log(_T("Query: ")+ query.str());
            if (StoreQueryResult res = query.store())
            if(res.num_rows()==0)
            {
                SaveDatas("",1);
                //UID=res[0][0].c_str();
            }
        }
    }
}
void DialogCalculatoare::Onm_ButtonSetClick(wxCommandEvent& event)
{
    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza un rand");
        return;
    }
    if(ReadDatas(1)!=m_List->GetItemText(m_List->GetFirstSelected(),0))
        SaveDatas(m_List->GetItemText(m_List->GetFirstSelected(),0),1);
    else
        SaveDatas("",1);

    Fill();
}
