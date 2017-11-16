#include "Database.h"
#include "Misc.h"
const string SQL::IP="your_ip";
const string SQL::DB="database";
const string SQL::User="user";
const string SQL::Password="pass";
wxString EncodePassword(const char* x)
{
    ///some encoding function
}
wxString RandCode()
{
    srand(GetTickCount());
    wxString ichar="";
    for(int a=0;a<6;a++)
        if(rand()%2)
            ichar<<(int)(rand()%10);
        else
        {
            if(rand()%2)
                ichar<<(char)(rand()%26+'a');
            else
                ichar<<(char)(rand()%26+'A');
        }
    return ichar;
}
#include "Editor.h"
int LogIn(wxString Email,wxString Parola)
{
    Connection conn(false);
    if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
    {
        Query query = conn.query();
        query<<"select * from users where Email='"<<escape<<utf8_encode(Email.wc_str())<<"' and Password='"<<utf8_encode(Parola.wc_str())<<"'";
        Log(query.str().c_str());
        if (StoreQueryResult res = query.store())
        {
            if(res.num_rows())//email and pass exists
                return 1;
            query.reset();
            query<<"select * from users where Email='"<<escape<<utf8_encode(Email.wc_str())<<"'";
            {
                StoreQueryResult res = query.store();
                if(res.num_rows())
                    return 2;//invalid password
                return 3;//just created, ask for email check
            }
        }
        else
        {
            Log(query.error());
            return 0;
        }
    }
    else
    {
        Log("Couldn't connect to DB!");
        return 0;
    }
    return 0;
}
int InsetUser(wxString Email,wxString Parola)
{
    Connection conn(false);
    if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
    {
        Query query = conn.query();
        query<<"INSERT INTO users (Email,Password) VALUES ('"<<escape<<utf8_encode(Email.wc_str())<<"','"<<utf8_encode(Parola.wc_str())<<"')";
        Log(query.str().c_str());
        if (query.execute())
            return 1;
        else
        {
            Log(query.error());
            return 0;
        }
    }
    else
    {
        Log("Couldn't connect to DB!");
        return 0;
    }
    return 0;
}
int DBCheck()
{
    Connection conn(false);
    if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
        return 1;
    wxMessageBox(conn.error());
    return 0;
}
int UpdateUser(wxString Email,wxString Parola)
{
    Connection conn(false);
    if (conn.connect(SQL::DB.c_str(), SQL::IP.c_str(),SQL::User.c_str(),SQL::Password.c_str(),SQL::port))
    {
        Query query = conn.query();
        query<<"update users set Password='"<<escape<<utf8_encode(Parola.wc_str())<<"' where Email='"<<escape<<utf8_encode(Email.wc_str())<<"'";
        Log(query.str().c_str());
        if (query.execute())
            return 1;
        else
        {
            Log(query.error());
            return 0;
        }
    }
    else
    {
        Log("Couldn't connect to DB!");
        return 0;
    }
    return 0;
}
