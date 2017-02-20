 #include <iostream>
 #include <conio.h>
 #include <SQLAPI.h> //  main SQLAPI++ header
 using namespace std;
 int main(int argc, char*  argv[])
 {
   SAConnection con;   // create connection object
   SACommand cmd(&con,"Select name, roll from a");      /* create command object, this is line in which we will select field which is to be viewed in output give (table name here)*/ \
   try
   {
      // connect to MySQL database
      con.Connect(
      "amit",  // database name change as per your database  name
      "root",   // user name change per your setting
      "SQL",       // password I don't have any password  for my database
      SA_MySQL_Client);
      cout<<"We are  connected!\n";
      // Select from our test table
      cmd.Execute();
      // fetch results row by row and print  results
      int i=0;
      while(cmd.FetchNext())
      {
          i++;
          cout<<"Row  "<<i<<" ";
          cout<<(const  char*)cmd.Field("name").asString()<<" ";
          cout<<(const  char*)cmd.Field("roll").asString()<<" ";
          cout<<endl;
      }
     // commit changes on success
     con.Commit();
     cout<<"Rows  selected!\n";
     // Disconnect is optional
     // autodisconnect will ocur in  destructor if needed
     con.Disconnect();
     cout<<"We are  disconnected!\n";
     getch();
   }
   catch(SAException &x)
   {
      // SAConnection::Rollback()
      // can also throw an exception
      // (if a network error for example),
      // we will be ready
      try
      {
          // on error rollback changes
          con.Rollback();
      }
      catch(SAException &)
      {
      }
          // print error message
          cout<<(const char*)x.ErrText();
   }
return 0;
}
