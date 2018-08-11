#include<fstream.h>
#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>


class library
{
int bookno;
char bookname[50],author[50],publisher[50];
public:
void menu();
void getbook();
void admin();
void modbook();
void displaybook(int , char [],char [],char []);
void searchbookname(char []);
void searchbookno(int );
void searchauthor(char []);
void searchpublisher(char []);
int getno()
{return bookno; }
char *getname()
{ return bookname; }
char *getauthor()
{ return author; }
char *getpublisher()
{ return publisher;}
}l1;

class student
{
int rollno,token,bno;
char name[50];
public:
void getstud();
void display();
int getno()
{ return rollno; }
char *getname()
{return name; }
int getbno()
{ return bno; }
int gettoken()
{ return token; }
void addtoken()
{token=1; }
void resettoken()
{token=0;}
void getsbno(int a)
{bno=a;}
}s1;

void library::menu()
{
int c,num;
char ch;
void issuebook();
void depositbook();
cout<<"\n1.Want to issue a book";
cout<<"\n2.Want to book return";
cout<<"\n3.Back to menu\n";
cin>>num;
switch(num)
{
case 1:
     clrscr();
     cout<<"\n1.search book by name";
     cout<<"\n2.search book by author";
     cout<<"\n3.search book by publisher";
     cout<<"\n4.Want to issue book";
     cout<<"\n5.Back";
     cout<<"\nEnter your choice between 1 to 5\n";
     cin>>c;
     clrscr();
     switch(c)
     {
	case 1:
		 cout<<"Book name=\n";
		 gets(bookname);
		 l1.searchbookname(bookname);
		 break;
	case 2:
		 cout<<"Author name=\n";
		 gets(author);
		 l1.searchauthor(author);
		 break;
	case 3:
		 cout<<"Publisher name=\n";
		 gets(publisher);
		 l1.searchpublisher(publisher);
		 break;
       case 4:
		 issuebook();
		 break;
	case 5:
		 return;
	default:
		 cout<<"Invalid\n";
		 break;
     }
     break;
case 2:
       cout<<"return\n";
       depositbook();
       break;
case 3:
       return;
default:
       cout<<"Invalid\n";
       break;
}
}
void library::searchbookname( char name[])
{
int flag=0,id;
char nm[50],au[50],pub[50];
ifstream f1("book.txt");
if(!f1)
{cout<<"\nERROR\n";
}
else
{
while(!f1.eof())
{
f1>>id>>nm>>au>>pub;
if(strcmp(nm,name)==0)
{
cout<<"\nYour search result is as given below:\n";
l1.displaybook(id,nm,au,pub);
flag=1;
break;
}
}
if(flag==0)
{cout<<"Your search result is not available\n";
}
getch();
f1.close();
}
getch();
}

void library::displaybook(int no,char name[],char auth[],char publish[])
{
cout<<"\nBook no="<<no;
cout<<"\nBook name="<<name;
cout<<"\nAuthor name="<<auth;
cout<<"\nPublisher name="<<publish;
}

void library::searchauthor(char auth[])
{
int flag=0,no;
char nm[50],au[50],pub[50];
ifstream f1("book.txt");
if(!f1)
{cout<<"\nERROR\n";
}
else
{
while(!f1.eof())
{
f1>>no>>nm>>au>>pub;
if(strcmp(au,auth)==0)
{
cout<<"\nYour search result is as given below:\n";
l1.displaybook(no,nm,au,pub);
flag=1;
break;
}
}
if(flag==0)
{
cout<<"Your search result is not available\n";
}
getch();
f1.close();
}
getch();
}
void library::searchpublisher(char publish[])
{
int flag=0,no;
char nm[50],au[50],pub[50];
ifstream f1("book.txt");
if(!f1)
{cout<<"\nERRORn";}
else
{while(!f1.eof())
{
f1>>no>>nm>>au>>pub;
if(strcmp(pub,publish)==0)
{
cout<<"\nYour search result is as given below:\n";
l1.displaybook(no,nm,au,pub);
flag=1;
break;
}
}
if(flag==0)
{cout<<"Your search result is not available\n"; }
getch();
f1.close();
}
getch();
}

void library::admin()
{
int a,no;
clrscr();
void writebook(library );
void modifybook(int );
void deletebook(int );
void students();
clrscr();
cout<<"\n\t1.Add a new book";
cout<<"\n\t2.Update a book data";
cout<<"\n\t3.Want to delete a book";
cout<<"\n\t4.students";
cout<<"\n\t5.Back\n";
cout<<"Enter your choice between 1 to 5\n";
cin>>a;
switch(a)
{
case 1:l1.getbook();
       writebook(l1);
       break;
case 2:cout<<"\nBook number=";
       cin>>no;
       modifybook(no);
       break;
case 3:cout<<"\nBook no=";
       cin>>no;
       deletebook(no);
       break;
case 4:students();
       break;
case 5:return;

default:cout<<"\nwrong choice ";
	break;
}
}
void library::getbook()
{
cout<<"\nBook no=";
cin>>bookno;
cout<<"\nBook name=";
gets(bookname);
cout<<"\nAuthor name=";
gets(author);
cout<<"\nPublisher name=";
gets(publisher);
}
void writebook(library l1)
{
ofstream f2("book.txt",ios::app);
if(!f2)
{cout<<"\nERROR\n";
}
f2<<"\n"<<l1.getno()<<"\n"<<l1.getname()<<"\n"<<l1.getauthor()<<"\n"<<l1.getpublisher();
cout<<"\nbook added to list ";
getch();
f2.close();
}
void deletebook(int num)
{
int flag=0,no;
char nm[50],au[50],pub[50];
ifstream f1("book.txt");
if(!f1)
{cout<<"\nERROR\n";
}
else
{ofstream f2("temp.txt",ios::out);
while(!f1.eof())
{
f1>>no>>nm>>au>>pub;
if(no!=num)
{
f2<<endl<<no<<endl<<nm<<endl<<au<<endl<<pub;
}
else
{flag=1;}
}
f1.close();
f2.close();
if(flag==0)
{
cout<<"\nRecord not found\n ";
getch();
}
else
{
cout<<"\nDeleted\n";
getch();
}
remove("book.txt");
rename("temp.txt","book.txt");
}
getch();
}
void modifybook(int num)
{
int flag=0,no;
char nm[50],au[50],pub[50],c;
ifstream f1("book.txt");
if(!f1)
{
cout<<"\nERROR\n";
}
else
{
ofstream f2("temp.txt",ios::out);
while(!f1.eof())
{
f1>>no>>nm>>au>>pub;
if(no==num)
{
if(flag!=1)
{
flag=1;
l1.displaybook(no,nm,au,pub);
cout<<"\nEnter y or n";
cin>>c;
if(c=='y'||c=='Y')
{
l1.getbook();
f2<<"\n"<<l1.getno()<<"\n"<<l1.getname()<<"\n"<<l1.getauthor()<<"\n"<<l1.getpublisher();
}
else
f2<<"\n"<<no<<"\n"<<nm<<"\n"<<au<<"\n"<<pub;
}
}
else
{
f2<<"\n"<<no<<"\n"<<nm<<"\n"<<au<<"\n"<<pub;
}
}
f1.close();
f2.close();
remove("book.txt");
rename("temp.txt","book.txt");
}
getch();
}

void student::getstud()
{
cout<<"\nAdmission number=\n";
cin>>rollno;
cout<<"Student name=\n ";
gets(name);
token=0;
bno=0;
}

void writestud(student s)
{
ofstream f2("student.txt",ios::app);
f2<<endl<<s.getno()<<endl<<s.getname()<<endl<<s.getbno()<<endl<<s.gettoken();
f2.close();
}

void student::display()
{
int rno,tok,book;
char sname[50];
ifstream f1("student.txt");
if(!f1)
{
cout<<"Not exist\n";
}
else
{
while(!f1.eof())
{
f1>>rno>>sname>>book>>tok;
cout<<"\nAdmission number="<<rno<<"\n Student name="<<sname<<"\nBook no of issued="<<book<<"\nIssued books="<<tok<<"\n";
}
}
f1.close();
getch();
}
void students()
{
void deletestud(int );
int n,rno;
clrscr();
cout<<"\n\t1 add new student\n\t2 display all students\n\t3 delete student details\n";
cin>>n;
switch(n)
{
case 1:s1.getstud();
       writestud(s1);
       break;
case 2:s1.display();
       break;
case 3:cout<<"Admission number=";
       cin>>rno;
       deletestud(rno);
       break;
default:cout<<"\nInvalidn";
	break;
}
}

void deletestud(int no)
{
int flag=0,num,tok,sbno;
char nm[50],ch;
ifstream f1("student.txt");
if(!f1)
{
cout<<"error in opening file \n";
}
else
{
ofstream f2("temp.txt",ios::out);
while(!f1.eof())
{
f1>>num>>nm>>sbno>>tok;
if(no!=num)
{
f2<<endl<<num<<endl<<nm<<endl<<sbno<<endl<<tok;
}
else
{
flag=1;
}
}
f1.close();
f2.close();
if(flag==0)
{
cout<<"\nResult not found\n ";
getch();
}
else
{cout<<"\nDeleted\n";
getch();
}
remove("student.txt");
rename("temp.txt","student.txt");
}
getch();
}

void issuebook()
{
int rno,num,tok,booknum,flag=0,found=0,bnum,boknu;
char nm[50],name[50],auth[50],pub[50];
ifstream fin("book.txt");
ifstream f1("student.txt");
ofstream f2("temp.txt");
if(!f1)
{
cout<<"\nERROR";
}
else
{
cout<<"\nAdmission number=";
cin>>rno;
while(!f1.eof())
{
f1>>num>>nm>>booknum>>tok;
if(num==rno)
{
found=1;
if(tok==0)
{
cout<<"\nBook number=";
cin>>bnum;
while(!fin.eof())
{
fin>>boknu>>name>>auth>>pub;
if(boknu==bnum)
{
l1.displaybook(boknu,name,auth,pub);
flag=1;
tok=1;
booknum=boknu;
f2<<endl<<num<<endl<<nm<<endl<<booknum<<endl<<tok;
cout<<"\nIssued book";
}
}
if(flag==0)
{cout<<"\nbook does not exist ";
}
}
else
{
f2<<endl<<num<<endl<<nm<<endl<<booknum<<endl<<tok;
cout<<"\ndeposit book first ";
}
}
else
f2<<endl<<num<<endl<<nm<<endl<<booknum<<endl<<tok;
}
if(found==0)
cout<<"\nstudent record does not exist ";
f1.close();
fin.close();
f2.close();
remove("student.txt");
rename("temp.txt","student.txt");
}
getch();
}

void depositbook()
{
int rno,fine,day,snum,tok,sbno,bbno,found=0,flag=0;
char sname[50],bname[50],auth[50],pub[50];
ifstream f1("book.txt");
ifstream fin("student.txt");
ofstream f2("temp.txt");
if(!fin)
{cout<<"\nERROR";
}
else
{
cout<<"\nAdmission number=";
cin>>rno;
while(!fin.eof())
{
fin>>snum>>sname>>sbno>>tok;
if(rno==snum)
{
found=1;
if(tok==1)
{
while(!f1.eof())
{
f1>>bbno>>bname>>auth>>pub;
if(bbno==sbno)
{
l1.displaybook(bbno,bname,auth,pub);
flag=1;
cout<<"\nbook deposited in number of days ";
cin>>day;
if(day>15)
{
fine=(day-15)*3;
cout<<"\nfine to be deposited is Rs="<<fine;
}
tok=0;
sbno=0;
f2<<endl<<snum<<endl<<sname<<endl<<sbno<<endl<<tok;
cout<<"\nDeposited";}
}
if(flag==0)
{
f2<<endl<<snum<<endl<<sname<<endl<<sbno<<endl<<tok;
cout<<"\nno is not exist ";
}
}
else
{
f2<<endl<<snum<<endl<<sname<<endl<<sbno<<endl<<tok;
cout<<"\nissue book first ";
}
}
else
f2<<endl<<snum<<endl<<sname<<endl<<sbno<<endl<<tok;
}
if(found==0)
{
cout<<"\nstudent record not exist ";
}
f1.close();
fin.close();
f2.close();
remove("student.txt");
rename("temp.txt","student.txt");
}
getch();
}

void main()
{
int num;
clrscr();
void writestud(student );
cout<<"\t\t\tWelcome to library Management\n";
cout<<"\nEnter your choice as given below:";
do
{
cout<<"\n\t1.Admin department\n\t2.Student part\n\t3.exit this program\n";
cin>>num;
switch(num)
{
case 1:
	    cout<<"Welcome to admin department\n";
	    l1.admin();
	    break;
case 2:     cout<<"Welcome to student part\n";
	    l1.menu();
	    break;
case 3:     exit(0);
default:    cout<<"INVALID\n";
	    break;
}
}while(num!=3);
getch();
}