#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<ctype.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<iomanip.h>
//*********************************************
//            HOTEL-THE ENGINEERING LEGEND
//          IN ASSOCIATION WITH CA ASPIRANT
//**********************************************
class HOTEL
{  int i; //customer choice
 struct custom_enter    //CUSTOMER DETAILS
 { char name [20];
   char address [100];
   long IDNO ;
 }customer1;
 struct check_in       //CHECK IN SERVICE
 { int roomno;
   char roomtype;
   char othserv;
   int durofstay;
   float roomcharge;
 }checkinserv;
 struct check_out      //CHECK OUT SERVICE
 { long billno;
   float totalbill ;
}checkoutserv;
struct restaurant      //RESTAURANT SERVICE
{char foodtype;
 int noofdishes;
 float retbill;
}restserv;
struct bar             //BAR SERVICE
{ char dtype;
 float dbill;
 }barserv;
struct swimpool       //SWIMMING POOL SERVICE
{ int durofswim;
 float swimcharge;
 }poolserv;
 public:
 void welcome();            //ENTER THE DRAGON
 void custom_details();     //ENTER YOUR DETAILS
 void room_details();       //WHAT KIND OF ROOM YOU WANT?
 void billup();             //HERE IS YOUR BILL
 void custom_care();        //HOW CAN WE HELP?
 void custom_record();      //RECORDS STORED OF CUSTOMER
 void custom_display();     //DISPLAY YOUR DETAILS
 void checking_out();       //CHECKING OUT AND BILLING
};
HOTEL h1;
ofstream ofile("hotel.dat",ios::binary);
void HOTEL::welcome()
{clrscr();
 cout<<setw(47)<<"welcome to hotel"<<endl;
 cout<<setw(50)<<"THE ENGINEERING LEGEND"<<endl;
 cout<<"do you want our services?"<<endl;
 cout<<"type 'Y' for  yes and 'N' for no"<<endl;
 char ch;
 cin>>ch;
 ch=toupper(ch);
 if(ch!='Y'&& ch!='N')
 { cout<<"enter a valid choice";
   cin>>ch;
 }
 do
 { cout<<"ENTER YOUR CHOICES"<<endl;
  cout<<"1. CHECK IN"<<endl<<"2. HELP"<<endl<<"3. EXIT"<<endl;
  cin>>i;
  switch (i)
  { case 1:
    custom_details();
    custom_record();
    break;
    case 2:
    custom_care();
    break;
    case 3:
    exit(0);
    break;
    default:
    cout<<"enter a valid choice";
    cin>>i;
    break;
   }
  }while(ch=='Y'||ch=='N');
 }

 void HOTEL::custom_details()
 {clrscr();
  cout<<"enter your required data"<<endl;
  cout<<"ENTER YOUR NAME:";
  gets(customer1.name);
  cout<<"ENTER YOUR ADDRESS:";
  gets(customer1.address);
  cout<<"ENTER YOUR IDENTITY NUMBER:";
  cin>>customer1.IDNO;
  room_details();
 }
 void HOTEL::room_details()
 {clrscr();
  cout<<"what kind of room do you want??"<<endl;
  cout<<" TYPE:"<<endl;
  cout<<" 'D' for deluxe AC"<<endl;
  cout<<" 'S' for deluxe non AC"<<endl;
  cout<<" 'L' for luxury suite"<<endl;
  cin>>checkinserv.roomtype;
  checkinserv.roomtype=toupper(checkinserv.roomtype);
  switch (checkinserv.roomtype)
  {case 'D':
   checkinserv.roomno=101;
   break;
   case 'S':
   checkinserv.roomno=201;
   break;
   case 'L':
   checkinserv.roomno=301;
   break;
   default:
   cout<<"enter a valid choice";
   cin>>checkinserv.roomtype;
   }
   cout<<"do you want any other services?"<<endl;
   char ch1;
   cout<<"type 'Y' for yes and 'N' for no"<<endl;
   cin>>ch1;
   ch1=toupper(ch1);
   if(ch1=='Y')
   { cout<<"enter the service you want"<<endl;
    cout<<"TYPE:"<<endl;
    cout<<" 'R' for restaurant"<<endl;
    cout<<" 'S' for swimming pool"<<endl;
    cout<<" 'B' for bar"<<endl;
    cin>>checkinserv.othserv;
    checkinserv.othserv=toupper(checkinserv.othserv);
    switch (checkinserv.othserv)
    { case 'R':
      cout<<"enter the type of food"<<endl;
      cout<<"'V' for veg and 'N' for non-veg"<<endl;
      cin>>restserv.foodtype;
      restserv.foodtype=toupper(restserv.foodtype);
      cout<<"enter number of dishes"<<endl;
      cin>>restserv.noofdishes;
      poolserv.swimcharge=0;
      barserv.dbill=0;
      break;
      case 'S':
      cout<<"enter the duration of swim in hours"<<endl;
      cin>>poolserv.durofswim;
      restserv.retbill=0;
      barserv.dbill=0;
      break;
      case 'B':
      cout<<"enter the drink type"<<endl;
      cout<<"'A'for alcoholic and 'B' for non-alcoholic"<<endl;
      cin>>barserv.dtype;
      barserv.dtype=toupper(barserv.dtype);
      restserv.retbill=0;
      poolserv.swimcharge=0;
      break;
      default:
      cout<<"enter a valid choice"<<endl;
      cin>>checkinserv.othserv;
      }
   }
   else if(ch1=='N')
      cout<<"no extra services added"<<endl;
   else
      { cout<<"enter a valid choice"<<endl;
       cin>>checkinserv.othserv;
      }
   cout<<"enter your duration of stay in number of days"<<endl;
   cin>>checkinserv.durofstay;
   cout<<"you are allotted the room ."<<checkinserv.roomtype<<endl;
   cout<<"room number "<<checkinserv.roomno<<endl;
   cout<<"for a period of "<<checkinserv.durofstay<<" days"<<endl;
   for(long j=0;j<100000000;j++); //time delay
   clrscr();
   cout<<"do you want to check out??"<<endl;
   cout<<"type 'Y' for yes and 'N' for no"<<endl;
   char ch2;
   cin>>ch2;
   ch2=toupper(ch2);
   if(ch2=='Y')
   checking_out();
   else if(ch2=='N')
   custom_display();
   else
   cout<<"enter a valid choice"<<endl;
 }
  void HOTEL::billup()
  {   clrscr();
      switch(checkinserv.roomtype)
     { case 'D':
       checkinserv.roomcharge=checkinserv.durofstay*800;
       break;
       case 'S':
       checkinserv.roomcharge=checkinserv.durofstay*500;
       break;
       case 'L':
       checkinserv.roomcharge=checkinserv.durofstay*1500;
       break;
     }
     switch(restserv.foodtype)
     { case 'V':
      restserv.retbill=restserv.noofdishes*500;
      break;
      case 'N':
      restserv.retbill=restserv.noofdishes*750;
      break;
      default:
      restserv.retbill=0;
     }
    switch(barserv.dtype)
    { case 'A':
     barserv.dbill=3750;
     break;
     case 'B':
     barserv.dbill=770;
     break;
     default:
     barserv.dbill=0;
    }
    poolserv.swimcharge=poolserv.durofswim*500;
    checkoutserv.billno=101234;
    checkoutserv.totalbill= checkinserv.roomcharge+restserv.retbill+barserv.dbill+poolserv.swimcharge;
    cout<<"THANK YOU FOR YOUR COMFORTABLE STAY AT THE HOTEL"<<endl;
    cout<<"your bill is as follows ------"<<endl;
    cout<<"BILL NUMBER: "<<checkoutserv.billno<<endl;
    cout<<"CUSTOMER NAME: "<<customer1.name<<endl;
    cout<<"TOTAL BILL: "<<checkoutserv.totalbill<<endl;
    checkoutserv.billno++;
    for(long k=0;k<100000000;k++); //time delay
    clrscr();
    }
  void HOTEL::custom_care()
  {clrscr();
   cout<<"how can we help?";
   exit(0);
  }
  void HOTEL::custom_record()
  { ofile.write((char*)&h1,sizeof(h1));
  }
  void HOTEL::custom_display()
  { clrscr();
    cout<<"here are your details"<<endl;
    cout<<"NAME: "<<customer1.name<<endl;
    cout<<"ADDRESS: "<<customer1.address<<endl;
    cout<<"IDENTITY NUMBER: "<<customer1.IDNO<<endl;
    for(long l=0;l<100000000;l++);
    clrscr();
  }
 void HOTEL::checking_out()
 { clrscr();
  ifstream ifile("hotel.dat",ios::binary);
  if(!ifile)
  { cout<<"cannot open file"<<endl;
   return;
  }
  cout<<"time to check out"<<endl;
  cout<<"enter your identity number"<<endl;
  long id1;
  cin>>id1;
  int m=0;
  while(!ifile.eof())
  { ifile.read((char*)&h1,sizeof(h1));
    if(customer1.IDNO==id1)
    { billup();
      m++;
    }
  }
  if(m==0)
  cout<<"not found"<<endl;
  ifile.close();
 }
  void main()
  { clrscr();
   h1.welcome();
   ofile.close();
  }







































































