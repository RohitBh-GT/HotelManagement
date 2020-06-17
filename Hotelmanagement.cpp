#include<iostream>
#include<cstdio>
#include<conio.h>
#include<cstdlib>
#include<fstream>
#include<graphics.h>
#include<ctype.h>
#include<cstring>
#include<windows.h>
#include<iomanip>
#include<list>
#include<cmath>
using namespace std;
class menus
{
 public:
 void menu();
 void user();
 void admin();
 void showmenu();
};
class date
{
    int m,d,y;
public:
    date();
    date(int,int,int);
    int countleapyears(date&);
    double getdifference1(date&);
    double getdifference2(date&);
    void display();
}start,endp;
class bill
{
    double sm=400.00;
    double del=600.00;
    double A=450.00;
    double non=300.00;
public:
    double smallac();
    double deluxeac();
    double smallnonac();
    double deluxenonac();
};
class hotel : public bill,public date
{
private:
 int room;
 char name[50],address[50];
 char phone[15];
 char roomtype;
 char ac;
 int d1,d2,m1,m2,y1,y2;
 double time;
public:
 void create_room();
 void show_room();
 int retroom();
 char* retname();
 char* retadd();
 char* retphone();
 char rettype();
 char retac();
 void occ_room();
 void payment();
};
void write_room();
void display_all();
void display_sp();
void modify();
void delete_record();
void searchname();
void searchphone();
void book_room();
void vacant();
void occupied();
void bill();
int login();
void menus :: menu()
{
 char ch;
  cout<<"\n\n\t\t\t1.Admin";
  cout<<"\n\t\t\t2.User";
  cout<<"\n\t\t\t3.Exit";
  cout<<"\n\n\t\t\t\tEnter Your Choice(1-3):";
  ch=getche();
  do
  {
  switch(ch)
  {
   case '1':
       system("cls");
      admin();
      break;
   case '2':
       system("cls");
       delay(1000);
       user();
     break;
   case '3':
     exit(0);
   default:
    cout<<"\a";
  }
 }while(ch!=3);
}
void menus :: admin()
{
    again:
    int c;
    c=login();
    if(c==1)
    {
        cout<<"\n\t\t\tPassword Accessed.\n\t\t\tPress 'o' to move to admin menu->";
         char c;
         cin>>c;
         if(c=='o')
            showmenu();
    }
    else
    {
        cout<<"\n\t\t\tInvalid Password.\a\n\t\t\tEnter password again";
        char j;
        j=getche();
        if(j=='\r')
        {
            system("cls");
            goto again;
        }
    }
}
void menus :: user()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\t     User Menu\n\t\t\t\t***********************";
    cout<<"\n\n\t\t\t\t1.Book Your Room";
    cout<<"\n\t\t\t\t2.See Your Bill";
    cout<<"\n\t\t\t\t3.Back To Main Menu";
    cout<<"\n\t\t\t\tEnter your choice(1-3):";
    int p;
    cin>>p;
    switch(p)
    {
    case 1:
        vacant();
        write_room();
        cout<<"\n\n\t\t\t\tThanks For Booking";
        cout<<"\n\t\t\t\tPress '0' to return to go back->";
            int u;
            cin>>u;
            if(u==0)
                user();
                break;
    case 2:
        bill();
         cout<<"\n\n\t\t\t\tBill payed(Y/N):";
         char p;
         cin>>p;
        if(p=='Y')
          delete_record();
         cout<<"\n\t\t\t\tThank You";
         cout<<"\n\t\t\t\tPress '0' to return to go back->";
            cin>>u;
            if(u==0)
                user();
                break;
    case 3:
        system("cls");
            menu();
            break;
    default:
        cout<<"\n\n\t\t\t\tEnter correct choice\a";
        system("cls");
        user();
    }
}
void menus :: showmenu()
{
    system("cls");
        cout<<"\n\n\n\t\t\t\t   Admin Menu\n\t\t\t\t*******************";
        cout<<"\n\n\t\t\t1.Create Room";
        cout<<"\n\t\t\t2.Display Room Records";
        cout<<"\n\t\t\t3.Rooms Vacant";
        cout<<"\n\t\t\t4.Rooms Occupied";
        cout<<"\n\t\t\t5.Modify Records";
        cout<<"\n\t\t\t6.Delete Record";
        cout<<"\n\t\t\t7.Search Customer Records";
        cout<<"\n\t\t\t8.Bill/Payments";
        cout<<"\n\t\t\t9.Back To Main Menu";
        cout<<"\n\t\t\tEnter Your Choice:";
        int n;
        cin>>n;
        switch(n)
        {
        case 1:
            system("cls");
            write_room();
            cout<<"\n\t\t\t\tPress '0' to return to go back->";
            int u;
            cin>>u;
            if(u==0)
                showmenu();
                break;
        case 2:
                system("cls");
               cout<<"\n\n\t\t\t\t    Choose among following\n\t\t\t\t*******************************";
               cout<<"\n\n\t\t\t\t1.All Room Records";
               cout<<"\n\t\t\t\t2.Specific Room Records";
               cout<<"\n\t\t\t\tEnter Your Choice:";
               int t;
               cin>>t;
               if(t==1)
                display_all();
               else if(t==2)
                 display_sp();
               else
                cout<<"\n\n\t\t\t\tInvalid Choice:";
            cout<<"\n\t\t\t\tPress '0' to return to go back->";
            cin>>u;
            if(u==0)
                showmenu();
                break;
        case 3:
            vacant();
             cout<<"\n\t\t\t\tPress '0' to return to go back->";
            cin>>u;
            if(u==0)
                showmenu();
                break;
        case 4:
            occupied();
             cout<<"\n\t\t\t\tPress '0' to return to go back->";
            cin>>u;
            if(u==0)
                showmenu();
                break;
        case 5:
            modify();
            cout<<"\n\t\t\t\tPress '0' to return to go back->";
            cin>>u;
            if(u==0)
                showmenu();
                break;
        case 6:
            delete_record();
             cout<<"\n\t\t\t\tPress '0' to return to go back->";
            cin>>u;
            if(u==0)
                showmenu();
                break;
        case 7:
            system("cls");
            cout<<"\n\n\n\t\t\t\t    Choose Among Following";
            cout<<"\n\t\t\t\t****************************";
            cout<<"\n\n\t\t\t\t1.Search by Name";
            cout<<"\n\t\t\t\t2.Search by Phone No.";
            cout<<"\n\t\t\t\tEnter Your Choice:";
            int n;
            cin>>n;
            if(n==1)
                searchname();
            else if(n==2)
                searchphone();
            else
                    cout<<"\n\n\t\t\t\tInvalid choice\a";
             cout<<"\n\t\t\t\tPress '0' to return to go back->";
            cin>>u;
            if(u==0)
                showmenu();
                break;
        case 8:
            bill();
             cout<<"\n\n\t\t\t\tBill payed(Y/N):";
             char p;
             cin>>p;
               if(p=='Y')
                  delete_record();
                  cout<<"\n\t\t\t\tThank You";
               cout<<"\n\t\t\t\tPress '0' to return to go back->";
            cin>>u;
            if(u==0)
                showmenu();
                break;
        case 9:
            system("cls");
            menu();
            break;
        default:
            cout<<"\n\n\t\t\t\tEnter the correct choice\a";
            char ch;
            ch=getche();
            if(ch=='\r')
            {
                system("cls");
                showmenu();
            }
    }
}
void hotel :: create_room()
{
    int day,month,year;
    cout<<"\n\n\t\t\t\tEnter Room No.:";
    cin>>room;
    fflush(stdin);
    cout<<"\n\t\t\t\tName of Guest:";
    gets(name);
    fflush(stdin);
    cout<<"\n\t\t\t\tAddress of Guest:";
    gets(address);
    cout<<"\n\t\t\t\tPhone No.:";
    cin>>phone;
    cout<<"\n\t\t\t\tRoom Type(Small/Deluxe):";
    cin>>roomtype;
    cout<<"\n\t\t\t\tAC/Non-AC(A/N):";
    cin>>ac;
    cout<<"\n\t\t\t\tCheck-in Date(dd/mm/yyyy):";
    cin>>day;
    cin.ignore();
    cin>>month;
    cin.ignore();
    cin>>year;
    d1=day;
    m1=month;
    y1=year;
    start=date(day,month,year);
    cout<<"\n\t\t\t\tCheck-out Date(dd/mm/yyyy):";
     cin>>day;
    cin.ignore();
    cin>>month;
    cin.ignore();
    cin>>year;
    d2=day;
    m2=month;
    y2=year;
    endp=date(day,month,year);
    double duration;
    duration=getdifference2(endp)-getdifference1(start);
    time=duration;
}
void hotel :: show_room()
{
    cout<<setw(5)<<room<<setw(20)<<name<<setw(20)<<address<<setw(20)<<phone;
    cout<<setw(10);
    if(roomtype=='s')
        cout<<"Small";
    else
        cout<<"Deluxe";
    cout<<setw(11);
    if(ac=='A')
        cout<<"AC";
    else
        cout<<"Non-AC";
    cout<<setw(13);
    cout<<d1<<"/"<<m1<<"/"<<y1;
    cout<<setw(14);
    cout<<d2<<"/"<<m2<<"/"<<y2;
    cout<<"\n";
}
int hotel :: retroom()
{
    return room;
}
char* hotel :: retname()
{
    return name;
}
char* hotel :: retadd()
{
    return address;
}
char* hotel :: retphone()
{
    return phone;
}
char hotel :: rettype()
{
    return roomtype;
}
char hotel :: retac()
{
    return ac;
}
void hotel :: occ_room()
{
    cout<<"\n\t\t\t"<<room<<setw(18)<<name;
}
void hotel :: payment()
{
    cout<<"\n\n\n\t\t\t\t   Bill\n\t\t\t\t**************";
    cout<<"\n\n\t\t\tName:"<<retname();
    cout<<"\n\t\t\tPhone No.:"<<retphone();
    cout<<"\n\t\t\tAddress:"<<retadd();
    cout<<"\n\t\t\tRoom No.:"<<retroom();
    cout<<"\n\t\t\tCheck-in Date:";
    cout<<d1<<"/"<<m1<<"/"<<y1;
    cout<<"\n\t\t\tCheck-out Date:";
    cout<<d2<<"/"<<m2<<"/"<<y2;
    cout.setf(ios::showpoint);
    if(rettype()=='s'&&retac()=='A')
    {
        cout<<"\n\t\t\tBill:"<<"Rs"<<(smallac()+(0.18*smallac()))*time<<"(All taxes included)";
    }
    else if(rettype()=='s'&&retac()=='N')
    {
        cout<<"\n\t\t\tBill:"<<"Rs"<<(smallnonac()+(0.18*smallnonac()))*time<<"(All Taxes included)";
    }
    else if(rettype()=='d'&&retac()=='A')
    {

        cout<<"\n\t\t\tBill:"<<"Rs"<<(deluxeac()+(0.18*deluxeac()))*time<<"(All Taxes included)";
    }
    else
    {
        cout<<"\n\t\t\tBill:"<<"Rs"<<(deluxenonac()+(0.18*deluxenonac()))*time<<"(All Taxes included)";;
    }
}
double bill :: smallac()
{
    return(sm+A);
}
double bill :: deluxeac()
{
    return(del+A);
}
double bill :: smallnonac()
{
    return(sm+non);
}
double bill :: deluxenonac()
{
    return(del+non);
}
date :: date()
{
    d=0;
    m=0;
    y=0;
}
date :: date(int a,int b,int c)
{
    d=a;
    m=b;
    y=c;
}
const int monthdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int date :: countleapyears(date& d)
{
    int years=d.y;
    if(d.m<2)
        years--;
    return (years/4-years/100+years/400);
}
double date :: getdifference1(date& start)
{
    double n1=double(start.y*365+start.d);
    n1+=double(countleapyears(start));
    for(int i=0;i<start.m-1;i++)
    {
        n1+=double(monthdays[i]);
    }
    return n1;
}
double date :: getdifference2(date& ends)
{
    double n2=double(ends.y*365+ends.d);
    n2+=double(countleapyears(ends));
    for(int i=0;i<ends.m-1;i++)
    {
        n2+=double(monthdays[i]);
    }
    return n2;
}
void date :: display()
{
    cout<<d<<"/"<<m<<"/"<<y;
}
fstream fp;
hotel h;
void write_room()
{
    cout<<"\n\n\t\t\t\t   Booking Room\n\t\t\t\t******************************";
    cout<<"\n\n\t\t\t\t   Enter details\n";
    fp.open("room.dat",ios::out|ios::app|ios::binary);
    h.create_room();
    fp.write((char*)&h,sizeof(h));
    fp.clear();
    fp.close();
    cout<<"\n\n\t\t\t\tThe Room has been booked";
}
void display_all()
{
    system("cls");
    fp.open("room.dat",ios::in|ios::binary);
    cout<<"\n\n\t\t\t\t    Displaying all The Records";
    cout<<"\n\t\t\t\t*********************************";
    cout<<"\n\nRoom No."<<setw(20)<<"Name"<<setw(20)<<"Address"<<setw(18)<<"Phone No.";
    cout<<setw(10)<<"RoomType"<<setw(11)<<"AC/Non-AC";
    cout<<setw(18)<<"Check-in Date"<<setw(18)<<"Check-out Date\n";
    fp.seekg(0);
    while(fp.read((char*)&h,sizeof(h)))
    {
        h.show_room();
    }
   fp.close();
}
void display_sp()
{
    system("cls");
    fp.open("room.dat",ios::in|ios::binary);
    cout<<"\n\n\n\n\t\t\t\tEnter Room no. whose information you wanted:";
    int ro,flag=0;
    cin>>ro;
    fp.seekg(0);
    while((fp.read((char*)&h,sizeof(h))))
    {
        if(h.retroom()==ro)
        {
            system("cls");
             cout<<"\n\nRoom No."<<setw(20)<<"Name"<<setw(20)<<"Address"<<setw(18)<<"Phone No.";
             cout<<setw(10)<<"RoomType"<<setw(11)<<"AC/Non-AC";
             cout<<setw(18)<<"Check-in Date"<<setw(18)<<"Check-out Date\n";
             h.show_room();
             flag++;
        }
    }
    if(flag==0)
        cout<<"\n\n\t\t\t\tRoom entered not found\a";
        fp.close();
}
void occupied()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\t    Occupied Rooms\n\t\t\t\t**************************";
    cout<<"\n\n\t\t\tRoom No.";
    cout<<setw(12)<<"Name"<<endl;
    int p[10]={1,2,3,4,5,6,7,8,9,10};
    fp.open("room.dat",ios::in|ios::binary);
    fp.seekg(0);
    while(fp.read((char*)&h,sizeof(h)))
    {
        for(int i=0;i<10;i++)
        {
            if(h.retroom()==p[i])
            {
                h.occ_room();
                break;
            }
        }
    }
    fp.close();
}
void vacant()
{
    system("cls");
    fp.open("room.dat",ios::in|ios::binary);
    list<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i+1);
    }
    cout<<"\n\n\n\t\t\t\t   Vacant Rooms\n\t\t\t\t**************************";
    cout<<"\n\n\t\t\tRooms\n";
    list<int> :: iterator it;
    fp.seekg(0);
    while(fp.read((char*)&h,sizeof(h)))
    {
         for(it=v.begin();it!=v.end();it++)
         {
             if(h.retroom()==*it)
             {
                v.remove(*it);
                break;
             }
         }
    }
    for(it=v.begin();it!=v.end();it++)
    {
        cout<<"\t\t\t"<<*it<<"- Vacant\n";
    }
    fp.close();
}
void modify()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\tEnter the room no. to modify:";
    int ro,found=0;
    cin>>ro;
    fp.open("room.dat",ios::in|ios::out|ios::ate|ios::binary);
    fp.seekg(0);
    while(fp.read((char*)&h,sizeof(h)))
    {
        if(ro==h.retroom())
        {
            int pos=(-1)*sizeof(h);
            h.show_room();
            cout<<"\n\n\t\t\t\tEnter new details\n\n\t\t\t\t";
            h.create_room();
            fp.seekp(pos,ios::cur);
            fp.write((char*)&h,sizeof(h));
            cout<<"\n\t\t\t\tThe details of room has been modified";
            found++;
        }
    }
    fp.close();
    if(found==0)
        cout<<"\n\n\t\t\t\tRoom  not found\a";
}
void delete_record()
{
    system("cls");
    fstream fp2;
    fp.open("room.dat",ios::in|ios::out|ios::ate|ios::binary);
    fp2.open("Temp.dat",ios::out|ios::app|ios::binary);
    cout<<"\n\n\t\t\t\tEnter the Room no. whose data you want to delete:";
    int ro;
    char n[50];
    cin>>ro;
    fp.seekg(0);
    while(fp.read((char*)&h,sizeof(h)))
    {
        if(h.retroom()!=ro)
        {
            fp2.write((char*)&h,sizeof(h));
        }
    }
    cout<<"\n\n\t\t\t\tAll the Data saved for that room  has been deleted";
    fp2.close();
    fp.close();
    remove("room.dat");
    rename("Temp.dat","room.dat");
}
void searchname()
{
    system("cls");
    fp.open("room.dat",ios::in|ios::binary);
    cout<<"\n\n\n\n\t\t\t\tEnter Name of Person whose record you want to see:";
    char ch[50];
    fflush(stdin);
    gets(ch);
    fp.seekg(0);
    int u=0;
    while(fp.read((char*)&h,sizeof(h)))
    {
        if(strcmp(h.retname(),ch)==0)
        {
            system("cls");
             cout<<"\n\nRoom No."<<setw(20)<<"Name"<<setw(20)<<"Address"<<setw(20)<<"Phone No.";
             cout<<setw(9)<<"RoomType"<<setw(12)<<"AC/Non-AC";
             cout<<setw(15)<<"Check-in Date"<<setw(15)<<"Check-out Date\n";
            h.show_room();
            u++;
        }
    }
    fp.close();
    if(u==0)
        cout<<"\n\n\t\t\t\tNot found any by the entered name!\a";
}
void searchphone()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\tEnter Phone No. of person whose record you want to see:";
    char ch[10];
    cin>>ch;
    int k=0;
    fp.open("room.dat",ios::in|ios::binary);
    fp.seekg(0);
    while(fp.read((char*)&h,sizeof(h)))
    {
        if(strcmp(h.retphone(),ch)==0)
        {
            system("cls");
             cout<<"\n\nRoom No."<<setw(20)<<"Name"<<setw(20)<<"Address"<<setw(12)<<"Phone No.";
             cout<<setw(7)<<"RoomType"<<setw(11)<<"AC/Non-AC";
             cout<<setw(15)<<"Check-in Date"<<setw(15)<<"Check-out Date\n";
            h.show_room();
            k++;
        }
    }
    fp.close();
    if(k==0)
        cout<<"\n\n\t\t\t\tNo record found of the person whose phone no. you entered!\a";
}
void bill()
{
    system("cls");
    fp.open("room.dat",ios::in|ios::binary);
    char n[50],ph[15];
    int r;
    int t=0;
    cout<<"\n\n\n\t\t\t\tName of Guest:";
    fflush(stdin);
    gets(n);
    cout<<"\n\t\t\t\tPhone No.:";
    cin>>ph;
    cout<<"\n\t\t\t\tRoom No.:";
    cin>>r;
    fp.seekg(0);
    while(fp.read((char*)&h,sizeof(h)))
    {
        if(strcmp(h.retname(),n)==0&&strcmp(h.retphone(),ph)==0&&h.retroom()==r)
        {
            system("cls");
             h.payment();
             t++;
        }
    }
    fp.close();
    if(t==0)
        cout<<"\n\n\t\t\t\tNo one found of the entered information\a!";
}
int login()
{
    char username[100]="GabbarTiger";
    char password[100]="ScarL";
    char c[100],ch,b[100];
    int i=0;
    cout<<"\n\n\n\n\n\n\n\t\t\t\t       Administration Login System\n\t\t\t           *************************************";
    cout<<"\n\t\t\t\tUser name:";
    cin>>c;
    fflush(stdin);
    cout<<"\n\t\t\t\tPassword:";
    do
    {
        ch=getche();
        if(isalnum(ch))
        {
            b[i]=ch;
            cout<<"\b*";
            i++;
        }
        else if(ch=='\r')
        {
            b[i]='\0';
        }
            else if(ch=='\b')
            {
                i--;
                cout<<"\b";
            }
    }while(ch!='\r');
    fflush(stdin);
   if(strcmp(b,password)==0&&strcmp(c,username)==0)
    return 1;
   else
    return 0;
}
int main()
{
    COORD c;
    c.X=35;
    c.Y=11;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
    cout<<"Welcome To Sun Hotel\n";
    cout<<"\t\t\t\t**************************";
    delay(1000);
    menus m;
    m.menu();
    return 0;
}
