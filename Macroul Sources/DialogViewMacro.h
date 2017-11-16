#ifndef DIALOGVIEWMACRO_H
#define DIALOGVIEWMACRO_H

//(*Headers(DialogViewMacro)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/dialog.h>
//*)

class DialogViewMacro: public wxDialog
{
	public:

		DialogViewMacro(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~DialogViewMacro();

		//(*Declarations(DialogViewMacro)
		wxListView* m_List;
		//*)

	protected:

		//(*Identifiers(DialogViewMacro)
		static const long ID_LISTVIEW1;
		//*)

	private:

		//(*Handlers(DialogViewMacro)
		void Onm_ListBeginDrag(wxListEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
