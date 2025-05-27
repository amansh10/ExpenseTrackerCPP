#include<iostream>
#include<time.h>
#include<sqlite3.h>


using namespace std;

class Money{
    private:
    int amount; 
    string category; 
    string description;
    string date;
      
    public:
    // adding in the database;

     string Date(){
            
                time_t timestamp; 
                time(&timestamp); 

                return string(ctime(&timestamp));
         };

   

    void addMoney(){
             sqlite3 *db; 
        char *errMsg=nullptr;  
        int rc=sqlite3_open("new_financial.db",&db); 

         const char *creation_command= "CREATE TABLE IF NOT EXISTS finance ("
                                   "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                   "Amount INTEGER NOT NULL, "
                                   "Category TEXT NOT NULL, "
                                   "Description TEXT NOT NULL, "
                                   "DATE TEXT NOT NULL);";

         rc=sqlite3_exec(db,creation_command,nullptr,0,&errMsg);

         cout<<"What is the amount you want to insert? "<<endl;
         cin>>amount;
         
         cout<<"What is the category? "<<endl;
         cin>>category;

         cout<<"What is the description? "<<endl;
         cin>>description;


        string sql = "INSERT INTO finance (Amount, Category, Description, Date) VALUES (" +
             to_string(amount) + ", '" + category + "', '" + description + "', '" + Date() + "');";

        rc = sqlite3_exec(db, sql.c_str(), nullptr, 0, &errMsg);

        sqlite3_close(db);

       
    } ;

       


    // viewing all

    void viewAll()
    {
            sqlite3 *db; 
            int rc=sqlite3_open("new_financial.db",&db);
            char *errMsg= nullptr; 

            string sql= "SELECT * FROM finance";

             auto callback = [](void* unused, int argc, char** argv, char** colNames) -> int {
        for (int i = 0; i < argc; ++i) {
            cout << colNames[i] << ": " << (argv[i] ? argv[i] : "NULL") << "  ";
        }
        cout << endl;
        return 0;
                 };

                 rc=sqlite3_exec(db,sql.c_str(),callback,0,&errMsg);

                 sqlite3_close(db);

    };

    // filter by category 

    void Filter(){
           int id_number; 
           sqlite3 *db; 

            int rc = sqlite3_open("new_financial.db", &db);
            char *errMsg=nullptr; 

           cout<<"Which ID, you want to check what? "<<endl;
           cin>>id_number; 

            string sql="SELECT * FROM finance WHERE ID="+to_string(id_number);

            //NEED TO UDNERSTAND 

                 auto callback = [](void* unused, int argc, char** argv, char** colNames) -> int {
        for (int i = 0; i < argc; ++i) {
            cout << colNames[i] << ": " << (argv[i] ? argv[i] : "NULL") << "  ";
        }
        cout << endl;
        return 0;
                 };

        // NEED TO UNDERSTAND
        
                rc=sqlite3_exec(db,sql.c_str(),callback,0,&errMsg);
                sqlite3_close(db);

          
    };  
    
 
// deleting Data
    void deleteExpense(){
        int id_number; 
        sqlite3 *db;
         char *errMsg=nullptr; 

         int rc=sqlite3_open("new_financial.db",&db);

         cout<<"Which ID record you wanna delete? "<<endl;
         cin>>id_number; 

         string sql="DELETE FROM finance WHERE ID="+to_string(id_number);

         rc=sqlite3_exec(db,sql.c_str(),nullptr,0,&errMsg); 

         sqlite3_close(db);

    };

  // updating data 
    void Updating(){
        int id_number; 
        string update_field;
        string change; 
        sqlite3 *db; 
        char *errMsg=nullptr; 

        int rc=sqlite3_open("new_financial.db",&db);

        cout<<"What is the ID Number you want to update? "<<endl;
        cin>>id_number; 

        cout<<"Which field do you wanna update? "<<endl;
        cin>>update_field; 

        cout<<"What you want to inser new? "<<endl;
        cin>>change;

         if(update_field=="Amount"){
                string sql="UPDATE finance SET Amount='"+change+"'WHERE ID="+to_string(id_number);

                rc=sqlite3_exec(db,sql.c_str(),nullptr,0,&errMsg);
                
        }

        else if(update_field=="Category"){
             string sql="UPDATE finance SET Category='"+change+"'WHERE ID="+to_string(id_number);

                rc=sqlite3_exec(db,sql.c_str(),nullptr,0,&errMsg);
        }
        
        else if(update_field=="Description"){
             string sql="UPDATE finance SET Description='"+change+"'WHERE ID="+to_string(id_number);

                rc=sqlite3_exec(db,sql.c_str(),nullptr,0,&errMsg);
                sqlite3_close(db);

        }
    


    };
           
           
        

    };

    


class Menu:public Money{
    public:
    
    string menu_answer;

       void menu(){
        while(menu_answer!="exit"){
                cout<<"Welcome to expense tracker"<<endl;
                cout<<" "<<endl;

                cout<<"1. Add Expense"<<endl;
                cout<<"2. View All"<<endl;
                cout<<"3. Filter By Category"<<endl;
                cout<<"4.Delete Expense"<<endl;
                cout<<"5. Update"<<endl; 
                cout<<"6.Exit"<<endl;
                cin>>menu_answer;

                if(menu_answer=="1"){
                    addMoney();
                }
                else if(menu_answer=="2"){
                    viewAll();
                }
                else if(menu_answer=="3"){
                    Filter(); 

                }   
                else if(menu_answer=="4"){
                    deleteExpense(); 

                }   
                else if(menu_answer=="5"){
                    Updating(); 
                }
                else if(menu_answer=="6"){
                    break;
                }

        };
       };


};

int main(){

    Menu Object1; 
    Object1.menu(); 

    

};
