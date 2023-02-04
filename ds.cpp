#include <iostream>
#include <fstream>

#include <string.h>
using namespace std;
void ser();
void menu();
void registration();
void login();
void registrationa();
void logina();
 void dat();
class Emp
{
    int ID;
    char name[20];
    float SAL;


public:
    Emp() 
    {
        ID = 00;
        strcpy(name, "Not Given");
        SAL = 00;
    }

    Emp(int d, const char *j, float bs)
    {
        ID = d;
        strcpy(name, j);
        SAL = bs;
    }
    void display()
    {
        cout << "\n************************************";
        cout << "\nEmployee Id : " << ID;
        cout << "\nName : " << name;
        cout << "\nSalary : " << SAL;
        cout << "\n************************************";
    }

    int getid()
    {
        return ID;
    }
    const char *getname()
    {
        return name;
    }
    float getSAL()
    {
        return SAL;
    }
    void setid(int d)
    {
        this->ID = d;
    }
    void setename(const char *j)
    {
        strcpy(this->name, j);
    }
    void setSAL(float bs)
    {
        this->SAL = bs;
    }
}; 

class Node
{
    Emp data;
    Node *next;

public:
    Node(Emp d)
    {
        data = d;
        next = NULL;
    }
    Emp getdata()
    {
        return data;
    }
    Node *getnext()
    {
        return next;
    }

    void setdata(Emp d)
    {
        this->data = d;
    }
    void setnext(Node *n)
    {
        this->next = n;
    }
}; 

class Company
{
    Node *start;

public:
    Company()
    {
        start = NULL;
    }
    void addemp(Emp e)
    {
        Node *temp = new Node(e);
        temp->setnext(start);
        start = temp;
        ofstream out;
       out.open("data.txt",ios::app);
       out<<e.getname()<<"\t"<<e.getid()<<"\t"<<e.getSAL()<<endl;
    }

    void removeempById(int id)
    {
        if (start == NULL)
        {
            cout << "\nNo employee data is here ";
            return;
        }
        Node *p = start; 
        if (id == p->getdata().getid())
        {
            start = start->getnext();
            p->getdata().display();
            cout << "\nthis employee is deleted ...";
            delete p;
            return;
        }
        if (p->getnext() == NULL)
        {
            cout << "\nnot Found ";
            return;
        }
        while (p->getnext()!= NULL)
        {
            Emp e1 = p->getnext()->getdata();
            if (id == e1.getid())
            {
                Node *q = p->getnext();
                p->setnext(q->getnext());
                q->getdata().display();
                cout << "\nNow Deleted this employee";
                delete q;
                return;
            }
            p = p->getnext();
        }
        cout << "\nnot Found ";
    }

    

    void searchEmpById(int id)
    {
        if (start == NULL)
        {
            cout << "\nNot Found";
            return;
        }
        Node *p = start;
        while (p != NULL)
        {
            Emp e1 = p->getdata();
            if (e1.getid() == id)
            {
                cout << "\nEmployee Found ...";
                e1.display();
                return;
            }
            p = p->getnext();
        }
        cout << "\nEmployee is not Found";
    }

    void DisplayallEmp()
    {
        if (start == NULL)
        {
            cout << "\n\n No employee data here ";
            cout << "\n\n";
            return;
        }
        Node *p = start;
        while (p != NULL)
        {
            p->getdata().display();
            p = p->getnext();
        }
    }

}; 





int main(){


int g,l;
cout<<"\t\t\tWelcome to Employe Managment System\n\n\n ";
cout<<"\t\t\tEnter 1 if you are an Admin\n";
cout<<"\t\t\tEnter 2 if you are an Employe\n";
cin>>g;
switch (g)
{
case 1:
cout<<"\t\t\tEnter 1 to Register\n";
cout<<"\t\t\tEnter 2  to log in\n\n";
       
cin>>l;
switch (l)
{
case 1:
registrationa();
  break;
case 2:
logina();

break;
default:
  break;
}

case 2:
cout<<"\t\t\tEnter 1 to Register\n";
cout<<"\t\t\tEnter 2  to log in\n\n";


int k;
cin>>k;
switch (k)
{
case 1:
registration();
    
    break;
    case 2:
login();

break;
default:
cout<<"Enter a valid option\n";

main();
    break;
}

   }
 
}
void registration()

{  string usernam;
   int passwor;

   cout<<"Enter Your Username\n";
   cin>>usernam;
   cout<<"Enter the Password\n";
   cin>>passwor;

    ofstream reg("registration.txt",ios ::app);
    reg<<usernam<<"\t"<<passwor<<endl;
    main();
    reg.close();

}
void login(){
   string username;
   int password,count;

   cout<<"Enter Your Username\n";
   cin>>username;
   cout<<"Enter your Password\n";
   cin>>password;
   string user[100];
   int pass[100];
 int j=0;
  ifstream rege;

  rege.open("registration.txt",ios::app);
   while(rege>>user[j]>>pass[j]){
    
 if(username==user[j]&&password==pass[j])
     count=1;
    j++;
   }

    
      
          rege.close();
        
          if (count==1){
            cout<<"          Your login successfully\n";
             ser();
          }
          else {
          cout<<"You have Entered wrong  Username or Password\n";
          main();
          }
   }
   void registrationa()

{  string usernam;
   int passwor;

   cout<<"Enter Your Username\n";
   cin>>usernam;
   cout<<"Enter the Password\n";
   cin>>passwor;

    ofstream reg("registrationa.txt",ios ::app);
    reg<<usernam<<"\t"<<passwor<<endl;
    main();
    reg.close();

}
void logina(){
   string username;
   int password,count;

   cout<<"Enter Your Username\n";
   cin>>username;
   cout<<"Enter your Password\n";
   cin>>password;
   string user[100];
   int pass[100];
 int j=0;
  ifstream rege;

  rege.open("registrationa.txt",ios::app);
   while(rege>>user[j]>>pass[j]){
    
 if(username==user[j]&&password==pass[j])
     count=1;
    j++;
   }

    
      
          rege.close();
        
          if (count==1){
            cout<<"          Your login successfully\n";
            menu();
          }
          else {
          cout<<"You have Entered wrong  Username or Password\n";
          main();}
   }
   void menu(){
    int ch = 0;
    Company lt;
    while (ch != 6)
    {
        cout << "\n\n*************************************";
        cout << "\n\t1.Add Employee.";
        cout << "\n\t2.Display Employee.";
        cout << "\n\t3.Search By id.";
        cout << "\n\t4.Delete by Id.";
        cout << "\n\t5.Exit";
        cout << "\n*************************************\n\n";
        cout << "\n\tEnter the choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int id;
            char name[20];
            float bs;
            cout << "\n Enter the ID : ";
            cin >> id;
            cout << "\n Enter the name :";
            cin >> name;
            cout << "\n Enter the Salary: ";
            cin >> bs;
            Emp e1(id, name, bs);
            lt.addemp(e1);
        }
        break;
        case 2:
            lt.DisplayallEmp();
            /* code */
            break;
        case 3:
        {
            int id;
            cout << "\nEnter the id to search : ";
            cin >> id;
            lt.searchEmpById(id);
        }
     
        break;

        case 4:
        {
            int id;
            cout << "\nEnter the id to Delete  : ";
            cin >> id;
            lt.removeempById(id);
        }
        
        break;

      
        case 5:
        {
            cout << "\nEnd the Programm!!!";
            main();
        }
        
        break;

        default:
            cout << "\nInvalid choice:";
            break;
        }
    }
   }
   void ser(){

    Company p;
    int y,id;
    cout<<"Enter 1 to Check your record\n";
    cout<<"Enter 2 to EXIT\n";
    cin>>y;
    switch (y){
     case 1:
   
    //  cin>>id;
     dat();
     

    
    
    case 2:
    main();
      break;
    
    default:
      break;
    }
   }

   void dat(){

     string name[100];
     int id[100],sal[100];
     int serch,count;
     cout<<"Enter you ID\n";
    cin>>serch;
     int j=0;
  ifstream rege;

  rege.open("data.txt",ios::app);
   while(rege>>name[j]>>id[j]>>sal[j]){
    
 if(serch==id[j])
    //  count=1;
        
 cout<<"Employe Name is\t"<<name[j]<<"\t\tYour id is\t "<<id[j]<<"\t\t and Salary is \t"<<sal[j]<<endl;
    j++;

    
   }


    
      
          rege.close();
        
        
          
         
          
}

   