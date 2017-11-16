#include "DialogNLP.h"

//(*InternalHeaders(DialogNLP)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogNLP)
const long DialogNLP::ID_STATICTEXT1 = wxNewId();
const long DialogNLP::ID_LISTVIEW1 = wxNewId();
const long DialogNLP::ID_BUTTON2 = wxNewId();
const long DialogNLP::ID_BUTTON3 = wxNewId();
const long DialogNLP::ID_BUTTON5 = wxNewId();
const long DialogNLP::ID_STATICTEXT2 = wxNewId();
const long DialogNLP::ID_TEXTCTRL1 = wxNewId();
const long DialogNLP::ID_STATICTEXT3 = wxNewId();
const long DialogNLP::ID_TEXTCTRL2 = wxNewId();
const long DialogNLP::ID_BUTTON1 = wxNewId();
const long DialogNLP::ID_BUTTON4 = wxNewId();
const long DialogNLP::ID_BUTTON6 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogNLP,wxDialog)
	//(*EventTable(DialogNLP)
	//*)
END_EVENT_TABLE()

DialogNLP::DialogNLP(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogNLP)
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Macroul"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
	SetClientSize(wxSize(800,600));
	FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	FlexGridSizer4 = new wxFlexGridSizer(2, 2, 0, 0);
	FlexGridSizer4->AddGrowableCol(0);
	FlexGridSizer4->AddGrowableCol(1);
	FlexGridSizer4->AddGrowableRow(0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer2->AddGrowableCol(0);
	FlexGridSizer2->AddGrowableRow(1);
	FlexGridSizer2->AddGrowableRow(4);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Text sablon si variabile"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_List = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxLC_HRULES|wxLC_VRULES|wxVSCROLL, wxDefaultValidator, _T("ID_LISTVIEW1"));
	FlexGridSizer2->Add(m_List, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5 = new wxFlexGridSizer(0, 3, 0, 0);
	m_Add = new wxButton(this, ID_BUTTON2, _("Adauga"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer5->Add(m_Add, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Edit = new wxButton(this, ID_BUTTON3, _("Editeaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer5->Add(m_Edit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Delete = new wxButton(this, ID_BUTTON5, _("Sterge"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	FlexGridSizer5->Add(m_Delete, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer5, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Rezultat"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_Rezultat = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	m_Rezultat->Disable();
	FlexGridSizer2->Add(m_Rezultat, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(FlexGridSizer2, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer6->AddGrowableCol(0);
	FlexGridSizer6->AddGrowableRow(1);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Cod macrou"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer6->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_TextCode = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	FlexGridSizer6->Add(m_TextCode, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(FlexGridSizer6, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer4, 1, wxTOP|wxBOTTOM|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 7, 0, 0);
	m_ButtonSave = new wxButton(this, ID_BUTTON1, _("Salveaza"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(m_ButtonSave, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_ButtonTest = new wxButton(this, ID_BUTTON4, _("Test"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	FlexGridSizer3->Add(m_ButtonTest, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON6, _("Exemplu"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
	Button1->Disable();
	Button1->Hide();
	FlexGridSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	SetSizer(FlexGridSizer1);
	Layout();

	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogNLP::Onm_AddVariableClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogNLP::Onm_EditClick);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogNLP::Onm_DeleteClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogNLP::Onm_ButtonSaveClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogNLP::Onm_ButtonTestClick);
	//*)


	m_List->DeleteAllColumns();
    m_List->InsertColumn(ID_NUME,"Nume",wxLIST_FORMAT_LEFT, 140);
    m_List->InsertColumn(ID_TIP,"Tip",wxLIST_FORMAT_LEFT, 120);
    m_List->InsertColumn(ID_SEPARATOR,"Separator",wxLIST_FORMAT_LEFT, 70);
    if(m_List->GetItemCount())
        m_List->DeleteAllItems();

    this->SetPosition(wxPoint(GetSystemMetrics(SM_CXSCREEN)/2- (this->GetClientRect().width)/2,GetSystemMetrics(SM_CYSCREEN)/2 -(this->GetClientRect().height)/2 ));
}

DialogNLP::~DialogNLP()
{
	//(*Destroy(DialogNLP)
	//*)
}

#include <wx/msgdlg.h>
#include "Misc.h"
#include "Editor.h"
#include "Database.h"

#include <mysql++.h>
using namespace mysqlpp;
void DialogNLP::Onm_ButtonSaveClick(wxCommandEvent& event)
{
    if(m_List->GetItemCount()<=0)
    {
        wxMessageBox("Trebuie sa fie text sau variabile");
        return;
    }
    if(Check()==false)return;

    Connection conn(false);
    if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
    {
        wxString start=m_List->GetItemText(0,ID_NUME);
        Query query = conn.query();
        query<<"Select Inceput from sablon where UserID= "+UID;
        if(AIDI!="")
            query<<" and ID!= "<<AIDI;
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

    EndModal(1);
}

#include "DialogGetText.h"
#include<vector>
#include<map>
#include "Misc.h"
#include<wx/tokenzr.h>
using namespace std;
void DialogNLP::Onm_ButtonTestClick(wxCommandEvent& event)
{
    if(m_List->GetItemCount()<=0)
    {
        wxMessageBox("Trebuie sa fie text sau variabile");
        return;
    }
    if(m_List->GetItemCount()<=0)
    {
        wxMessageBox("Trebuie sa fie text sau variabile");
        return;
    }
    if(Check()==false)return;

    DialogGetText x(this);
    if(x.ShowModal()!=1)return;

    map<wxString,vector<wxString> > Variabile;
    wxString input=x.m_TextCode->GetValue();
    int i=0;
    int n=m_List->GetItemCount();
    if(m_List->GetItemText(n-1,ID_TIP)!="Text")
        n--;
    vector<wxString> NumeVariabile;
    for(int a=0;a<n;a++)///sigur se termina cu text
    {
        wxString left=input.substr(i);
        wxString tip=m_List->GetItemText(a,ID_TIP);
        wxString nume=m_List->GetItemText(a,ID_NUME);
        wxString sep=m_List->GetItemText(a,ID_SEPARATOR);
        if(tip=="Text")
        {
            wxString tocomp=left.substr(0,nume.size());
            if(nume.compare(tocomp))
            {
                wxMessageBox("\""+left+"\" nu incepe cu \""+nume+"\"");
                return;
            }
            i+=nume.size();
        }
        else
        {
            NumeVariabile.push_back(nume);
            if(m_List->GetItemText(a,ID_TIP)=="Variabila simpla")
            {
                vector<wxString> Var;
                wxString next=m_List->GetItemText(a+1,ID_NUME);///urmatorul text
                if(left.find(next)==-1)
                {
                    wxMessageBox("Nu am mai gasit textul asteptat: \""+next+"\"");
                    return;
                }
                size_t cate=left.find(next);
                Var.push_back(left.substr(0,cate));
                Variabile[nume]=Var;
                i+=cate;
            }
            else///var multipla
            {
                vector<wxString> Var;
                wxString next=m_List->GetItemText(a+1,ID_NUME);///urmatorul text
                if(left.find(next)==-1)
                {
                    wxMessageBox("Nu am mai gasit textul asteptat: \""+next+"\"");
                    return;
                }
                size_t cate=left.find(next);
                wxString tot=left.substr(0,cate);

                Var=split(tot,sep);///qqq

                Variabile[nume]=Var;
                i+=cate;
            }
        }
    }
    if(m_List->GetItemText(m_List->GetItemCount()-1,ID_TIP)=="Variabila simpla")
    {
        NumeVariabile.push_back(m_List->GetItemText(m_List->GetItemCount()-1,ID_NUME));
        wxString left=input.substr(i);
        vector<wxString> Var;
        Var.push_back(left);
        Variabile[m_List->GetItemText(m_List->GetItemCount()-1,ID_NUME)]=Var;
    }
    if(m_List->GetItemText(m_List->GetItemCount()-1,ID_TIP)=="Variabila multipla")
    {
        NumeVariabile.push_back(m_List->GetItemText(m_List->GetItemCount()-1,ID_NUME));
        wxString left=input.substr(i);
        vector<wxString> Var;
        wxString tot=left;

        Var=split(tot,m_List->GetItemText(m_List->GetItemCount()-1,ID_SEPARATOR));///qqq
//        wxStringTokenizer tok(tot,m_List->GetItemText(m_List->GetItemCount()-1,ID_SEPARATOR));
//        while(tok.HasMoreTokens())
//            Var.push_back(tok.GetNextToken());

        Variabile[m_List->GetItemText(m_List->GetItemCount()-1,ID_NUME)]=Var;
    }
    Log("Eu zic ca sunt urmatoarele var:");
    for(int a=0;a<NumeVariabile.size();a++)
    {
        Log("Pt: "+NumeVariabile[a]);
        for(int b=0;b<Variabile[NumeVariabile[a]].size();b++)
            Log("\t\t- |"+Variabile[NumeVariabile[a]][b]+"|");
    }

    int slip=30;
    if(ReadDatas(2)!="")
        slip=atoi(ReadDatas(2).data().AsChar());
    wxString Exe=m_TextCode->GetValue();
    wxStringTokenizer tok(Exe, "\n");
    while(tok.HasMoreTokens())
    {
        wxString toexe=tok.GetNextToken();
        ///todo sa vad daca e variabila inauntru, de care si cu ce trebuie inlocuita
        vector<posibilitate> posibilitati;
        posibilitati.push_back(posibilitate(toexe,0));
        bool done;
        do
        {
            done=true;
            for(int a=0;a<posibilitati.size();a++)
            {
                int p=-1,care=-1;
                posibilitate x=posibilitati[a];
                wxString acum=x.str.substr(x.poz);
                for(int b=0;b<NumeVariabile.size();b++)
                if(acum.find(NumeVariabile[b])!=-1)
                {
                    if(p==-1 || acum.find(NumeVariabile[b])<p)
                    {
                        p=acum.find(NumeVariabile[b]);
                        care=b;
                    }
                }
                if(p!=-1)
                {
                    wxString numeVar=NumeVariabile[care];
                    wxString str=x.str;
                    int poz=x.poz;
                    vector<wxString> valori = Variabile[numeVar];
                    wxString inceput=str.substr(0,poz+p);
                    wxString sfarsit=str.substr(poz+p+numeVar.size());
                    for(int b=0;b<valori.size();b++)
                    {
                        wxString tot=inceput+valori[b]+sfarsit;
                        int poz=tot.size()-sfarsit.size();
                        posibilitati.push_back(posibilitate(tot,poz));
                    }
                    done=false;
                    posibilitati.erase(posibilitati.begin()+a);
                    a--;
                }
            }
        }while(done==false);
        ///Log("Posibilitati:");
        for(int a=0;a<posibilitati.size();a++)
            runLine(posibilitati[a].str,slip,UID);
    }
}
#include "DialogVariabila.h"

bool DialogNLP::Check()
{
    for(int a=0;a<m_List->GetItemCount()-1;a++)
        if(m_List->GetItemText(a,ID_TIP).Contains("Variabila") && m_List->GetItemText(a+1,ID_TIP).Contains("Variabila"))
        {
            wxMessageBox("Nu poti sa ai doua variabile una dupa alta");
            return false;
        }
    if(m_List->GetItemCount())
        if(m_List->GetItemText(0,ID_TIP)!="Text")
        {
            wxMessageBox("Sablonul trebuie sa inceapa cu text");
            return false;
        }
    return true;
}
void DialogNLP::Onm_AddVariableClick(wxCommandEvent& event)
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

    DialogVariabila x(this);
    if(x.ShowModal()!=1)return;

    wxString name,separator,tip;
    tip=x.m_Radio->GetStringSelection();
    name=x.m_Text->GetValue();
    separator=x.m_Separator->GetValue();

    if(tip!="Text")
    for(int a=0;a<m_List->GetItemCount();a++)
        if(m_List->GetItemText(a,ID_NUME)==x.m_Text->GetValue() && m_List->GetItemText(a,ID_TIP)!="Text")
        {
            wxMessageBox("Mai exista o variabila cu numele asta");
            return;
        }
    m_List->InsertItem(pos,"");
    m_List->SetItem(pos,ID_NUME,name);
    m_List->SetItem(pos,ID_TIP,tip);
    if(x.m_Radio->GetSelection()==2)
        m_List->SetItem(pos,ID_SEPARATOR,separator);


    m_Rezultat->SetValue("");
    for(int a=0;a<m_List->GetItemCount();a++)
        m_Rezultat->AppendText(m_List->GetItemText(a,ID_NUME));
    Check();
}

void DialogNLP::Onm_EditClick(wxCommandEvent& event)
{
    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza un rand");
        return;
    }
    int pozy=m_List->GetFirstSelected();




    DialogVariabila x(this);
    x.m_Separator->SetValue(m_List->GetItemText(pozy,ID_SEPARATOR));
    x.m_Text->SetValue(m_List->GetItemText(pozy,ID_NUME));
    x.m_Radio->SetStringSelection(m_List->GetItemText(pozy,ID_TIP));
    x.Onm_RadioTipSelect(wxCE);

    if(x.ShowModal()!=1)return;

    ///todo sa inceapa cu text neaparat
    wxString name,separator,tip;
    tip=x.m_Radio->GetStringSelection();
    name=x.m_Text->GetValue();
    separator=x.m_Separator->GetValue();

    if(tip!="Text")
    for(int a=0;a<m_List->GetItemCount();a++)
        if(m_List->GetItemText(a,ID_NUME)==x.m_Text->GetValue() && m_List->GetItemText(a,ID_TIP)!="Text")
        {
            wxMessageBox("Mai exista o variabila cu numele asta");
            return;
        }
    m_List->SetItem(pozy,ID_NUME,name);
    m_List->SetItem(pozy,ID_TIP,tip);
    if(x.m_Radio->GetSelection()==2)
        m_List->SetItem(pozy,ID_SEPARATOR,separator);

    m_Rezultat->SetValue("");
    for(int a=0;a<m_List->GetItemCount();a++)
        m_Rezultat->AppendText(m_List->GetItemText(a,ID_NUME));
    Check();
}

void DialogNLP::Onm_DeleteClick(wxCommandEvent& event)
{
    if(m_List->GetFirstSelected()<0)
    {
        wxMessageBox("Selecteaza un rand");
        return;
    }
    int x=m_List->GetFirstSelected();
    m_List->DeleteItem(x);
    Check();
}


