#include "DialogMacroMele.h"

//(*InternalHeaders(DialogMacroMele)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include "MacroulMain.h"


//(*IdInit(DialogMacroMele)
const long DialogMacroMele::ID_LISTVIEW1 = wxNewId();
const long DialogMacroMele::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogMacroMele,wxDialog)
	//(*EventTable(DialogMacroMele)
	//*)
END_EVENT_TABLE()

DialogMacroMele::DialogMacroMele(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogMacroMele)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
	SetClientSize(wxSize(700,500));
	FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	m_List = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES|wxLC_VRULES|wxVSCROLL, wxDefaultValidator, _T("ID_LISTVIEW1"));
	FlexGridSizer1->Add(m_List, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 7, 0, 0);
	m_ButtonActivator = new wxButton(this, ID_BUTTON3, _("Activator"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer3->Add(m_ButtonActivator, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	SetSizer(FlexGridSizer1);
	Layout();

	Connect(ID_LISTVIEW1,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&DialogMacroMele::Onm_ListItemActivated);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogMacroMele::Onm_ButtonActivatorClick);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&DialogMacroMele::OnClose);
	//*)

    this->SetPosition(wxPoint(GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));

}


#include "Misc.h"
#include "Editor.h"
void DialogMacroMele::Fill()
{
    m_List->DeleteAllColumns();
    m_List->InsertColumn(0,"Macrou ID",wxLIST_FORMAT_LEFT, 70);
    m_List->InsertColumn(1,"Nume",wxLIST_FORMAT_LEFT, 200);
    m_List->InsertColumn(2,"Descriere",wxLIST_FORMAT_LEFT, 300);
    m_List->InsertColumn(3,"Public",wxLIST_FORMAT_LEFT, 50);
    m_List->InsertColumn(4,"Voce",wxLIST_FORMAT_LEFT, 150);
    m_List->InsertColumn(5,"Taste",wxLIST_FORMAT_LEFT, 150);
    m_List->InsertColumn(6,"Program",wxLIST_FORMAT_LEFT, 150);
    m_List->InsertColumn(7,"Card",wxLIST_FORMAT_LEFT, 150);
    if(m_List->GetItemCount())
        m_List->DeleteAllItems();


        wxString temp="select macrou.ID, macrou.Nume, macrou.Descriere, case macrou.Public when 1 then 'Da' else 'Nu' end ,COALESCE(A1.Data,''),COALESCE(A2.Data,''),COALESCE(A3.Data,''),COALESCE(A4.Data,'') from macrou LEFT JOIN activator A1 on (macrou.ID=A1.MacrouID and A1.Type=1)  LEFT JOIN activator A2 on (macrou.ID=A2.MacrouID and A2.Type=2) LEFT JOIN activator A3 on (macrou.ID=A3.MacrouID and A3.Type=3) LEFT JOIN activator A4 on (macrou.ID=A4.MacrouID and A4.Type=4) where  macrou.UserID="+UID;
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
                for (size_t i = 0; i < res.num_rows(); ++i)
                {
                    m_List->InsertItem(i,wxEmptyString);
                    for(int a=0;a<m_List->GetColumnCount();a++)
                    {
                        if(a!=6)
                            m_List->SetItem(i,a,utf8_decode(res[i][a].c_str()));
                        else
                        {
                            time_t temp=atoi(res[i][a].c_str());
                            wxDateTime DT;
                            DT.Set(temp);
                            if(temp)
                                m_List->SetItem(i,a,DT.Format(wxT("%d-%m-%y %H:%M:%S") ));
                            //x.m_TimePicker->SetTime(DT.GetHour(),DT.GetMinute(),DT.GetSecond());
                            //x.m_DatePicker->SetValue(DT);
                        }
                    }
                }
        }
}
DialogMacroMele::~DialogMacroMele()
{
	//(*Destroy(DialogMacroMele)
	//*)
}

#include "DialogActivator.h"
#include "Editor.h"
void DialogMacroMele::Onm_ButtonActivatorClick(wxCommandEvent& event)
{
    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza o linie...");
        return;
    }
    DialogActivator x(this);

    {
        wxString temp="SELECT Type,Data,NrTimes FROM activator where MacrouID="+m_List->GetItemText(m_List->GetFirstSelected(),0);
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Log(_T("Query: ")+ temp);Query query = conn.query();query<<temp;
            if (StoreQueryResult res = query.store())
                for (size_t i = 0; i < res.num_rows(); ++i)
                {
                    if(atoi(res[i][0].c_str())==1)
                    {
                        x.m_CheckVoce->SetValue(1);
                        x.m_VoiceText->SetValue(utf8_decode(res[i][1].c_str()));
                    }
                    if(atoi(res[i][0].c_str())==2)
                    {
                        x.m_CheckTaste->SetValue(1);
                        x.m_Tastatura->SetValue(utf8_decode(res[i][1].c_str()));
                    }
                    if(atoi(res[i][0].c_str())==3)
                    {
                        x.m_CheckProgram->SetValue(1);
                        time_t temp=atoi(res[i][1].c_str());
                        wxDateTime DT;
                        DT.Set(temp);
                        x.m_TimePicker->SetTime(DT.GetHour(),DT.GetMinute(),DT.GetSecond());
                        x.m_DatePicker->SetValue(DT);
                    }
                    if(atoi(res[i][0].c_str())==4)
                    {
                        x.m_CheckCard->SetValue(1);
                        x.m_CardCode->SetValue(utf8_decode(res[i][1].c_str()));
                    }
                    x.m_Times->SetValue(atoi(res[i][2].c_str()));
                }
        }
    }












    if(x.ShowModal()!=666)
        return;
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"delete from activator where MacrouID = "+m_List->GetItemText(m_List->GetFirstSelected(),0);
            Log(query.str().c_str());
            if (!query.execute())
            {
                Log(query.error());
                return ;
            }
        }
    }
    if(x.m_CheckVoce->GetValue())
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"INSERT INTO activator (MacrouID,Type,Data,NrTimes) VALUES ";
            query<<"("<<m_List->GetItemText(m_List->GetFirstSelected(),0)<<",1,'"<<escape<<utf8_encode(x.m_VoiceText->GetValue().wx_str())<<"',"<<x.m_Times->GetValue()<<")";
            Log(query.str().c_str());
            if (!query.execute())
            {
                Log(query.error());
                return ;
            }
        }
    }
    if(x.m_CheckTaste->GetValue())
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"INSERT INTO activator (MacrouID,Type,Data,NrTimes) VALUES ";
            query<<"("<<m_List->GetItemText(m_List->GetFirstSelected(),0)<<",2,'"<<x.m_Tastatura->GetValue()<<"',"<<x.m_Times->GetValue()<<")";
            Log(query.str().c_str());
            if (!query.execute())
            {
                Log(query.error());
                return ;
            }
        }
    }
    if(x.m_CheckProgram->GetValue())
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {

            wxDateTime DT=x.m_DatePicker->GetValue();
            DT.SetHour(x.m_TimePicker->GetValue().GetHour());
            DT.SetMinute(x.m_TimePicker->GetValue().GetMinute());
            DT.SetSecond(x.m_TimePicker->GetValue().GetSecond());

            wxString ichar="";
            ichar<<DT.GetTicks();

            Query query = conn.query();
            query<<"INSERT INTO activator (MacrouID,Type,Data,NrTimes) VALUES ";
            query<<"("<<m_List->GetItemText(m_List->GetFirstSelected(),0)<<",3,'"<<ichar<<"',"<<x.m_Times->GetValue()<<")";
            Log(query.str().c_str());
            if (!query.execute())
            {
                Log(query.error());
                return ;
            }
        }
    }
    if(x.m_CheckCard->GetValue())
    {
        Connection conn(false);
        if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        {
            Query query = conn.query();
            query<<"INSERT INTO activator (MacrouID,Type,Data,NrTimes) VALUES ";
            query<<"("<<m_List->GetItemText(m_List->GetFirstSelected(),0)<<",4,'"<<x.m_CardCode->GetValue()<<"',"<<x.m_Times->GetValue()<<")";
            Log(query.str().c_str());
            if (!query.execute())
            {
                Log(query.error());
                return ;
            }
        }
    }

    MacroulFrame::initTriggers();

}

void DialogMacroMele::OnClose(wxCloseEvent& event)
{
    EndModal(0);
}

void DialogMacroMele::Onm_ListItemActivated(wxListEvent& event)
{
    Onm_ButtonActivatorClick(wxCE);
}
