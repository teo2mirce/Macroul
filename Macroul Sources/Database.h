
#ifndef DATABASE_H
#define DATABASE_H
#include <wx/msgdlg.h>
#include <mysql++.h>
#include <string>



using namespace mysqlpp;
using namespace std;
class SQL
{
    public:
    static const string IP,DB,User,Password;
    //string IP="macroul.sytes.net",DB="general",User="MrUser",Password="google";
    static const int port=3306;

};




int LogIn(wxString Email,wxString Parola);
int InsetUser(wxString Email,wxString Parola);
int UpdateUser(wxString Email,wxString Parola);
wxString EncodePassword(const char* x);
wxString RandCode();
int DBCheck();






#endif // DATABASE_H
