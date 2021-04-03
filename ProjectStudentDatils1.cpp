
 // student managaement system in c+
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iomanip>
#include<windows.h>
char user[30];
char password[30];

void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
using namespace std;

class Student
{
    int rno;
    char name[20];
    char fname[20];
    char cont[11];
    char course[10];
public:
    void Store();
    void Read();
    void Search(int);
    void Delete(char *);
    void Update(int);
    Student()
    {
        rno=0;
        strcpy(name,"Not-Found");
        strcpy(fname,"Not-Found");
        strcpy(cont,"Not-Found");
        strcpy(course,"Not-Found");

    }
    void login()
    {

        cout<<"\n\n\t\t\t\t\t\tLogIn Page\n\n";
        cout<<"Enter UserName : ";
        fflush(stdin);
        gets(user);
        cout<<"Enter Password : ";
        fflush(stdin);
        gets(password);

    }
    void SetData()
    {
        cout<<"\nEnter Your Roll Number : ";
        cin>>rno;
        cout<<"Enter Your Name : ";
        fflush(stdin);
        gets(name);
        cout<<"Enter Your Father's Name : ";
        fflush(stdin);
        gets(fname);
        cout<<"Enter Your Contact Number : ";
         fflush(stdin);
        gets(cont);
        cout<<"Enter Your Course : ";
         fflush(stdin);
        gets(course);

    }
    void ShowData()
    {

        cout<<endl;
        cout<<endl;
        cout<<setw(40)<<"Roll Number : "<<setw(40)<<rno<<endl
        <<setw(40)<<"Name : "<<setw(40)<<name<<endl
        <<setw(40)<<"Father's Name : "<<setw(40)<<fname<<endl
        <<setw(40)<<"Contact Number : "<<setw(40)<<cont<<endl
        <<setw(40)<<"Course Name : "<<setw(40)<<course<<endl;
    }
};
void Student::Store()
{
    fstream obj;
    obj.open("write1.cpp",ios::app);
    if(!obj)
        cout<<"file not found!!";
    else
    {
        obj.write((char*)this,sizeof(*this));
        obj.close();
        cout<<"\nInserted successful !\n";
    }
    obj.close();

}
void Student:: Read()
{
    fstream obj;
    obj.open("write1.cpp",ios::in);
    obj.read((char*)this,sizeof(*this));
    if(!obj)
        cout<<"Data Not available!!";
    else
    {
    while(!obj.eof())
    {
        ShowData();
        obj.read((char*)this,sizeof(*this));
    }
    }
    obj.close();
    getch();

}
void Student:: Search(int n)
{
    fstream obj;
    obj.open("write1.cpp",ios::in);
    if(!obj)
        cout<<"Not available";
    else
    {
    obj.read((char*)this,sizeof(*this));
    while(!obj.eof())
    {
        if(n == rno)
        ShowData();
        obj.read((char*)this,sizeof(*this));
    }
obj.close();
    }
    getch();
}
/*void Student :: Delete(char *n)
{
    ifstream obj1;
    ofstream obj2;
    obj1.open("write1.cpp",ios::in|ios::binary);
    if(!obj1)
        cout<<"Not exist!!";

    else
    {
    obj2.open("temp.cpp",ios::out| ios::binary);
    getch();
    obj1.read((char*)this,sizeof(*this));
    while(!obj1.eof())
    {
        if(strcmp(name,n))
             obj2.write((char*)this,sizeof(this));
        obj1.read((char*)this , sizeof(*this));
    }
     obj1.close();
    obj2.close();
    remove("write1.cpp");
    rename("temp.cpp","write1.cpp");
}
getch();

}
*/
void Student:: Update(int n)
{
    fstream obj;
    obj.open("write1.cpp",ios::in|ios::out|ios::ate);
    obj.seekg(0);
    obj.read((char*)this,sizeof(*this));
    while(!obj.eof())
    {
        if(n==rno)
        {
            SetData();
            obj.seekp(obj.tellp()-sizeof(*this));
            obj.write((char*)this, sizeof(*this));
        }
        obj.read((char*)this,sizeof(*this));
    }
    obj.close();
    cout<<"Updated Successful!!!";
    getch();
}
int menu()
{
    int ch;
    system("cls");
    cout<<"\n\n************************* Student Management System   ***************************\n\n";
    cout<<"\n1.Registration";
    cout<<"\n2.Show All";
    cout<<"\n3.Exit";
    cout<<"\n4.Search";
    //cout<<"\n5.Delete";
    cout<<"\n6.Update";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        system("cls");
        return ch;

}
int main()
{
    Student S;
    char n[20];
    int no;
    cout<<"\n\t\t\tYou Have To Login Before Use This Application\n\n";
    x:
    S.login();
    if(strcmp(user,"mujtaba9")==0 & strcmp(password,"12345")==0)
    {
    cout<<"Login Successful";
    while(1)
    {
        switch(menu())
        {
        case 1:
            S.SetData();
            S.Store();
            break;
        case 2:
            S.Read();
            break;
        case 3:
            gotoxy(35,12);
            cout<<"THANK YOU FOR USING THIS APPLOCATION ";
            gotoxy(35,13);
            cout<<"press any key to exit : ";
            getch();
            exit(0);
            break;
        case 4:
            cout<<"\n\n\t\tEnter The Roll Number which you want to search : ";
            cin>>no;
            S.Search(no);
            break;
        case 5:
            cout<<"Enter The name  : ";
            cin>>n;
           // S.Delete(n);
           break;

        case 6:
            cout<<"\n\n\t\tEnter The Roll Number which you want to update : ";
            cin>>no;
            S.Update(no);
            break;



        default:
            cout<<"\nInvalid choice try again please!!";
        }
    }
    }
    else
    {
        cout<<"\nLogin Failed Enter The correct Details ! \n\n";
        goto x;

    }
 return 0;
}
