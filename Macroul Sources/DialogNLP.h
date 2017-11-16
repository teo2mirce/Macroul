#ifndef DIALOGNLP_H
#define DIALOGNLP_H

//(*Headers(DialogNLP)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#define ID_NUME 0
#define ID_TIP  1
#define ID_SEPARATOR 2



class DialogNLP: public wxDialog
{
	public:
	    wxString AIDI;
	    wxString UID;
	    wxCommandEvent wxCE;
	    bool Check();

		DialogNLP(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogNLP();

		//(*Declarations(DialogNLP)
		wxTextCtrl* m_Rezultat;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* m_ButtonSave;
		wxButton* m_Edit;
		wxButton* m_ButtonTest;
		wxButton* m_Add;
		wxButton* m_Delete;
		wxTextCtrl* m_TextCode;
		wxListView* m_List;
		//*)

	protected:

		//(*Identifiers(DialogNLP)
		static const long ID_STATICTEXT1;
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON5;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON4;
		static const long ID_BUTTON6;
		//*)

	private:

		//(*Handlers(DialogNLP)
		void Onm_ButtonSaveClick(wxCommandEvent& event);
		void Onm_ButtonTestClick(wxCommandEvent& event);
		void Onm_AddVariableClick(wxCommandEvent& event);
		void Onm_EditClick(wxCommandEvent& event);
		void Onm_DeleteClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
