#include "DialogGrupuri.h"

//(*InternalHeaders(DialogGrupuri)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogGrupuri)
const long DialogGrupuri::ID_LISTVIEW1 = wxNewId();
const long DialogGrupuri::ID_BUTTON1 = wxNewId();
const long DialogGrupuri::ID_BUTTON2 = wxNewId();
const long DialogGrupuri::ID_BUTTON5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogGrupuri,wxDialog)
	//(*EventTable(DialogGrupuri)
	//*)
END_EVENT_TABLE()

DialogGrupuri::DialogGrupuri(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogGrupuri)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
	SetClientSize(wxSize(800,600));
	FlexGridSizer1 = new wxFlexGridSizer(2, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	m_List = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES|wxLC_VRULES|wxVSCROLL, wxDefaultValidator, _T("ID_LISTVIEW1"));
	FlexGridSizer1->Add(m_List, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(1, 3, 0, 0);
	m_ButtonAdd = new wxButton(this, ID_BUTTON1, _("Adauga"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(m_ButtonAdd, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonEdit = new wxButton(this, ID_BUTTON2, _("Editeaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer3->Add(m_ButtonEdit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonDelete = new wxButton(this, ID_BUTTON5, _("Sterge"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	FlexGridSizer3->Add(m_ButtonDelete, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	SetSizer(FlexGridSizer1);
	Layout();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogGrupuri::Onm_ButtonAddClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogGrupuri::Onm_ButtonEditClick);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogGrupuri::Onm_ButtonDeleteClick);
	//*)


    this->SetPosition(wxPoint(GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));

}

DialogGrupuri::~DialogGrupuri()
{
	//(*Destroy(DialogGrupuri)
	//*)
}
#include "wx/grid.h"
#include "Misc.h"
#include "Editor.h"
void DialogGrupuri::Fill()
{
    m_List->DeleteAllColumns();
    m_List->InsertColumn(0,"Nume grup",wxLIST_FORMAT_LEFT, 200);
    if(m_List->GetItemCount())
        m_List->DeleteAllItems();

    wxArrayString grupuri,calculatoare;

    ///grupurile         = linii
    {
        wxString temp="select Nume from grupuri where UserID="+UID;
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
                    grupuri.Add(utf8_decode(res[i][0].c_str()));
                }
        }
    }
    ///calculatoarele       = coloane
    {
        wxString temp="select Nume from calculatoare where UserID="+UID;
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
                for (size_t i = 0; i < res.num_rows(); ++i)
                {
                    m_List->InsertColumn(i+1,utf8_decode(res[i][0].c_str()),wxLIST_FORMAT_LEFT, -1);
                    calculatoare.Add(utf8_decode(res[i][0].c_str()));
                }
        }
    }
    ///asocierile
    {
        wxString temp="select NumeGrup,NumeCalculator from asocieregrup where UserID="+UID;
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
            for (size_t i = 0; i < res.num_rows(); ++i)
            {
                int l=grupuri.Index(utf8_decode(res[i][0].c_str()));
                int c=1+calculatoare.Index(utf8_decode(res[i][1].c_str()));///ca prima coloana e nume grupuri

                m_List->SetItem(l,c,"X");
            }
        }
    }
}

#include "DialogGrupuriAddEdit.h"
#include "wx/checklst.h"
void DialogGrupuri::Onm_ButtonAddClick(wxCommandEvent& event)
{
    DialogGrupuriAddEdit x(this);
    {
        wxString temp="select Nume from calculatoare where UserID="+UID;
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
                for (size_t i = 0; i < res.num_rows(); ++i)
                    x.m_Check->AppendAndEnsureVisible(utf8_decode(res[i][0].c_str()));
        }
    }
    x.Layout();
    x.Fit();
    if(x.ShowModal()==1)
    {
        ///adauga grupul
        {
            Connection conn(false);
            if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
            {
                Query query = conn.query();
                query<<"INSERT INTO `grupuri`(`UserID`, `Nume`) VALUES (";
                query<<UID<<",'"<<escape<<utf8_encode(x.m_Text->GetValue().wc_str())<<"')";
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
        }
        ///adauga si calculatoarele
        {
            Connection conn(false);
            if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
            {
                for(int a=0;a<x.m_Check->GetCount();a++)
                if(x.m_Check->IsChecked(a))
                {
                    Query query = conn.query();
                    query<<"INSERT INTO `asocieregrup`(`UserID`, `NumeGrup`,NumeCalculator) VALUES (";
                    query<<UID<<",'"<<escape<<utf8_encode(x.m_Text->GetValue().wc_str())<<"',";
                    query<<"'"<<escape<<utf8_encode(x.m_Check->GetString(a).wc_str())<<"')";
                    Log(query.str().c_str());
                    if (!query.execute())
                    {
                        Log(query.error());
                        return ;
                    }
                }
            }
            else
            {
                Log("Couldn't connect to DB!");
                return;
            }
        }
        Fill();
    }
}

void DialogGrupuri::Onm_ButtonEditClick(wxCommandEvent& event)
{
    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza un rand");
        return;
    }
    DialogGrupuriAddEdit x(this);

    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"SELECT calculatoare.Nume,(SELECT count(*) FROM asocieregrup WHERE asocieregrup.NumeCalculator=calculatoare.Nume AND asocieregrup.UserID="<<UID.data().AsChar()<<" AND asocieregrup.NumeGrup='"<<escape<<utf8_encode(m_List->GetItemText(m_List->GetFirstSelected(),0).wc_str())<<"' ) FROM calculatoare WHERE calculatoare.UserID="<<UID.data().AsChar();
            Log(_T("Query: ")+ query.str());
            if (StoreQueryResult res = query.store())
                for (size_t i = 0; i < res.num_rows(); ++i)
                {
                    x.m_Check->AppendAndEnsureVisible(utf8_decode(res[i][0].c_str()));
                    if(atoi(res[i][1].c_str())==1)
                        x.m_Check->Check(i);
                }
        }
    }
    x.Layout();
    x.Fit();


    x.m_Text->SetValue(m_List->GetItemText(m_List->GetFirstSelected(),0));
    if(x.ShowModal()==1)
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"update `grupuri` set Nume='"<<escape<<utf8_encode(x.m_Text->GetValue().wc_str())<<"' where UserID="<<UID;
            query<<" and Nume='"<<escape<<utf8_encode(m_List->GetItemText(m_List->GetFirstSelected(),0).wc_str())<<"'";
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
    }
    ///adauga si calculatoarele
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            {
                Query query = conn.query();
                query<<"delete from  `asocieregrup` where UserID="<<UID;
                query<<" and NumeGrup='"<<escape<<utf8_encode(m_List->GetItemText(m_List->GetFirstSelected(),0).wc_str())<<"'";
                query.execute();
            }
            for(int a=0;a<x.m_Check->GetCount();a++)
            if(x.m_Check->IsChecked(a))
            {
                Query query = conn.query();
                query<<"INSERT INTO `asocieregrup`(`UserID`, `NumeGrup`,NumeCalculator) VALUES (";
                query<<UID<<",'"<<escape<<utf8_encode(x.m_Text->GetValue().wc_str())<<"',";
                query<<"'"<<escape<<utf8_encode(x.m_Check->GetString(a).wc_str())<<"')";
                Log(query.str().c_str());
                if (!query.execute())
                {
                    Log(query.error());
                    return ;
                }
            }
        }
        else
        {
            Log("Couldn't connect to DB!");
            return;
        }
    }
    Fill();
}

void DialogGrupuri::Onm_ButtonDeleteClick(wxCommandEvent& event)
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
        {
            Query query = conn.query();
            query<<"delete from  `asocieregrup` where UserID="<<UID;
            query<<" and NumeGrup='"<<escape<<utf8_encode(m_List->GetItemText(m_List->GetFirstSelected(),0).wc_str())<<"'";
            query.execute();
        }
        Query query = conn.query();
        query<<"delete from grupuri where UserID="<<UID;
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
