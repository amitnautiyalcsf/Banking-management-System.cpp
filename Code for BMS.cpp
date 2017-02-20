#include <iostream>
 #include <conio.h>
 #include <SQLAPI.h> //  main SQLAPI++ header
 #include<string.h>
 #include<mysql.h>
 #include<iomanip>
 using namespace std;
class bank
 {

    public:
    string uname,name,n1ame,s,u2name,u3name,wit,wit1,u4name,uuname,po;
    string pas,bal,password,pass1;
    string u1name;


    public:
    int newaccount();
}b;         // class object



 int bank::newaccount()
 {
     SAConnection con;   // creation of connection object
     SACommand cmd(&con);
     cout<<"Plz enter your name:";
     cin>>b.name;
     cout<<"Plz enter your username:";
     cin>>b.uname;
    cout<<"enter initial balance:";
     cin>>bal;
     cout<<"Enter your password:";
     cin>>b.password;

}




 int main(int argc, char*  argv[])
 {

     int c;

    SAConnection con;   // create connection object
    SACommand cmd(&con);     // create command object
   try
   {
        cout<<"Enter database password:";   /*SQL*/
        cin>>b.pas;
      // connection query of MySQL database
      con.Connect("test", "root", b.pas.c_str(),SA_MySQL_Client); //format is "database name","user name","password"

      cout<<"Congratulation we are  connected!\n";
        goto fl;  //calling bookmark

     con.Disconnect();
     cout<<"Oops we are  disconnected!\n";
     getch();
   }
        catch(SAException &x)
   {
      try
      {
          con.Rollback();
      }
      catch(SAException &)
      {
      }
          cout<<(const char*)x.ErrText();       //statement for printing error mssg
   }
return 0;
fl:
while(1)
{
		system("cls");
		qw:
		cout<<setw(50)<<":Welcome to Nsm Bank:"<<endl;
		cout<<setw(55)<<"Plz select your option from below:"<<endl;
		cout<<"1. Create Account"<<endl;
		cout<<"2. Balance Enquiry"<<endl;  //Balance
		cout<<"3. Modify Account"<<endl;  //to be removed at last
		cout<<"4. Reset password for your account"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"6. List all accounts"<<endl;     // to be done
		cout<<setw(50)<<"Your choice->>";
		cin>>c;
		system("cls");
		switch(c)
		{
                case 1:
                {
                            try{
                                cout<<"Enter following data for making your account:"<<endl;
                               b.newaccount();
                                SACommand cmd(&con,"Insert into v(name,uname,Balance,Password) values(:1,:2,:3,:4)");  //considering exception for primary key which is uname
                                cmd.Param(1).setAsString()=b.name.c_str();
                                cmd.Param(2).setAsString()=b.uname.c_str();             // queries for insertion of value taken from user
                                cmd.Param(3).setAsString()=b.bal.c_str();
                                cmd.Param(4).setAsString()=b.password.c_str();
                                cmd.Execute();      //command for executing queries
                                con.Commit();       //to save in database
                                cout<<endl<<"Congrats!Account created"<<endl;
                                system("pause");
                                break;
                                }
                            catch(SAException &x)
                                   {
                                      try
                                      {
                                          con.Rollback();
                                      }
                                      catch(SAException &)
                                      {
                                      }

                                          cout<<endl<<"Plz enter different username, this username is already taken"<<endl;
                                          system("pause");
                                   }
                                break;
                }

                case 2:
                 {
                     system("cls");
                     string a;
                            string pass;
                                    cout<<setw(40)<<"Enter Username for checking balance:";
                                    cin>>b.u1name;
                                    cout<<setw(40)<<"Enter password for checking balance:";
                                    cin>>pass;
                                    SACommand cmd(&con,"Select balance from a where uname=:9 AND password=:22");
                                    cmd.Param(9).setAsString()=b.u1name.c_str();
                                    cmd.Param(22).setAsString()=pass.c_str();
                                    cmd.Execute();      //full function for traversing through database

                                    bool is_result = cmd.isResultSet();
                                    long col_count = cmd.FieldCount();
                                    SAField& Field = cmd.Field("balance");


                                    if(cmd.FetchNext()==1)      //if result exists then it return value 1 because of experssion  bool is_result = cmd.isResultSet()
                                    {
                                    v=cmd.Field("balance").asString();
                                    cout<<"Press any key to see your balance:"<<endl;
                                    system("pause");
                                    system("cls");
                                    cout<<"Your account balance is :->"<<"RS."<<a<<"/-"<<endl<<endl<<endl;
                                    system("pause");
                                    break;
                                    }
                                    if(cmd.FetchNext()==0)
                                    {
                                        cout<<endl<<"plz input correct username or password"<<endl<<endl;
                                        system("pause");
                                    }
                            break;
                    }
                    case 3:
                    {
                                    system("cls");
                                    int t;
                                    cout<<"Choose option from below for futher modification of account:"<<endl;
                                    cout<<"1. Delete your account"<<endl;
                                    cout<<"2. Withdrawal"<<endl;
                                    cout<<"3. Deposite"<<endl;
                                    cout<<"4. Goto Main Menu"<<endl;
                                    cin>>t;
                                    switch(t)
                                    {
                                        case 1:
                                        {
                                                cout<<"Enter your username for deleting your account:";
                                                cin>>b.u2name;
                                                SACommand cmd(&con,"delete from v where uname=:10");
                                                cmd.Param(10).setAsString()=b.u2name.c_str();
                                                cmd.Execute();
                                                cout<<"Account Deleted"<<endl;
                                                system("pause");
                                    break;
                                        }
                                        case 2:
                                        {
                                    cout<<"Enter your Username:";
                                    cin>>b.u3name;
                                    system("pause");
                                    cout<<"Enter amount to be withdrwan:";
                                    cin>>b.wit;
                                    SACommand cmd(&con,"update a set balance=balance-:7 where uname=:6");
                                    cmd.Param(7).setAsString()=b.wit.c_str();
                                    cmd.Param(6).setAsString()=b.u3name.c_str();
                                    cmd.Execute();
                                    cout<<endl<<"Transaction done:"<<endl;
                                    system("pause");
                                        goto fl;
                                    break;
                                        }
                                        case 3:
                                        {
                                    cout<<"Enter your user name:";
                                    cin>>b.u4name;
                                    system("pause");
                                    cout<<"Enter amount to Deposite:";
                                    cin>>b.wit1;
                                    SACommand cmd(&con,"update a set balance=balance+:8 where uname=:9");
                                    cmd.Param(8).setAsString()=b.wit1.c_str();
                                    cmd.Param(9).setAsString()=b.u4name.c_str();
                                    cmd.Execute();
                                    cout<<endl<<"Transaction done:"<<endl;
                                    system("pause");
                                            goto fl;
                                    break;
                                        }
                                        case 4:
                                        {
                                        goto fl;
                                         system("pause");
                                          break;
                                        }
                                    }
                            break;
                    }
                    case 4:
                    {
                        cout<<"Welcome to password reset module:"<<endl;
                        cout<<"Enter your username for reseting ur password:"<<endl;
                        cin>>b.uuname;
                        cout<<"Enter your new password";
                        cin>>b.po;
                        SACommand cmd(&con,"update a set password=:13 where uname=:14");
                        cmd.Param(13).setAsString()=b.po.c_str();
                        cmd.Param(14).setAsString()=b.uuname.c_str();
                        cmd.Execute();
                        cout<<"Your password is updated"<<endl;
                        system("pause");
                        break;
                    }
                    case 5:
                    {
                        goto end;
                        system("pause");
                        break;
                    }
                    case 6:
                    {
                        SACommand cmd(&con,"Select name,uname,balance from a");
                        cmd.Execute();
                        int i=0;
                            bool is_result = cmd.isResultSet();
                            long col_count = cmd.FieldCount();

                              while(cmd.FetchNext())
                              {
                                  i++;
                                  cout<<"Row  "<<i<<" ";
                                  cout<<(const  char*)cmd.Field("name").asString()<<" ";
                                  cout<<(const  char*)cmd.Field("uname").asString()<<" ";
                                  cout<<(const  char*)cmd.Field("balance").asString()<<" ";
                                  cout<<endl;
                              }
                              cmd.Execute();
                              system("pause");
                                break;
                    }
            }
}           end:
            getch();
}
