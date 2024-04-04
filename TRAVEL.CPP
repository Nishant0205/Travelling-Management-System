//                               HEADER FILES

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>

//                       MEMBER FUNCTIONS DECLARATION

void welcome();
void member();
void log_in();
void header();
void hotel();
void about();
void contact();
void ne(int h);
void travel_del(int j);
void hotel_del(int a);
void safe();
void dis(int a);
void payment();

//				    MAIN PART

 void main()
 {
 clrscr();
 int i,ch;
 clrscr();
  for(i=12;i>1;i--)
  {
  delay(500);
  clrscr();
  gotoxy(23,i);
  cout<<"WELCOME TO NISHANT TOUR AND TRAVELS ";
  }
  while(ch!='0')
  {
  header();
  gotoxy(10,5);
  cout<<"PRESS 1. LOG IN";
  gotoxy(10,6);
  cout<<"PRESS 2. REGISTER";
  gotoxy(10,7);
  cout<<"PRESS 0. EXIT";
  gotoxy(12,9);
  cout<<"ENTER CHOICE ";
  ch=getch();
  switch(ch)
    {
  case'1':
  log_in();
  break;

  case'2':
  member();
  break;

  case'0':
  break;

  default:
  cout<<endl<<"ENTER VALID CHOICE";
  break;
    }
  }
 getch();
 }

//				    HEADER

 void header()
 {
 clrscr();
 gotoxy(28,2);
 cout<<" NISHANT TOUR AND TRAVELS ";
 gotoxy(28,3);
 cout<<"**************************";
 cout<<endl<<endl;
 }


//                                MAIN MENU

 class s
 {
 public:
 char name[20];
 int memno;
 int age;

 void main_menu()
 {
 int choice;
 while(choice!='0')
 {
 header();
 cout<<"   MAIN MENU"<<endl;
 cout<<"______________";
 cout<<endl<<endl;
 cout<<"  PRESS 1.PROFILE"<<endl;
 cout<<"  PRESS 2.TRAVEL"<<endl;
 cout<<"  PRESS 3.HOTELS"<<endl;
 cout<<"  PRESS 4.ABOUT"<<endl;
 cout<<"  PRESS 5.CONTACT US"<<endl;
 cout<<"  PRESS 0.EXIT"<<endl;
 cout<<endl<<"              ENTER CHOICE ";
 choice=getch();
  switch(choice)
    {
  case'1':
  y.profile();
  break;

  case'2':
  ol();
  break;

  case'3':
  safe();
  break;

  case'4':
  about();
  break;

  case'5':
  contact();
  break;

  case'0':
  break;

  default:
  cout<<endl<<"ENTER VALID CHOICE";
  break;
    }
  }
 }

 void input()
 {
 header();
 cout<<"ENTER MEMBERSHIP NUMBER ";
 cin>>memno;
 cout<<endl<<"ENTER NAME  ";
 gets(name);
 cout<<endl<<"ENTER AGE   ";
 cin>>age;
 header();
 cout<<"THANKS FOR REGISTRING !!!!"<<endl;
 cout<<endl<<"PRESS ANY KEY FOR MAIN MENU " ;
 getch();
 }

 int return_paas()
 {
 return memno;
 }
 }x;

 void log_in()
 {
 int paas,z,memno1;
 int c;
 int f=0;
 header();
 cout<<endl<<"ENTER MEMBERSHIP NUMBER ";
 cin>>memno1;
 ifstream fin;
 fin.open("mem.dat",ios::binary);
   while(fin.read((char*) &x,sizeof(x)))
   {
   z=x.return_paas();
   if(memno1==z)
   {
   f=1;
   }
   }
 if(f==1)
 {
 f=0;
 x.main_menu();
 }
 else if(f==0)
 {
 cout<<endl<<"NOT REGISTERD"<<endl;
 getch();
 }
 fin.close();
 }

 void member()
 {
 clrscr();
 s z;
 int f=0;
 header();
 ifstream fin;
 fin.open("mem.dat",ios::binary);
 cout<<"ENTER MEMBERSHIP NUMBER TO CHECK ";
 cin>>x.memno;
 while(fin.read((char*)&z,sizeof(z)))
 {
 if(z.memno==x.memno)
 {
 f=1;
 }
 }
 if(f==0)
 {
 ofstream fout;
 fout.open("mem.dat",ios::binary|ios::app);
 x.input();
 fout.write((char*)&x,sizeof(x));
 fout.close();
 x.main_menu();
 }
 else
 {
 cout<<"MEMBER EXISTS ";
 getch();
 }
 fin.close();
 }


//				 PROFILE

 class pro_ile
 {
 public:
 void profile()
 {
 int choice,memno1,f=0;
 header();
 cout<<"ENTER MEMBERSHIP NUMBER ";
 cin>>memno1;
 ifstream fin;
 fin.open("mem.dat",ios::binary);
 while(fin.read ((char *) &x, sizeof(x)))
 {
 if(memno1==x.memno)
 {
 f=1;
 header();
 cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
 cout<<"    MEMBERSHIP NUMBER   "<<x.memno<<endl<<endl;
 cout<<"    NAME                "<<x.name<<endl<<endl;
 cout<<"    AGE                 "<<x.age<<endl<<endl;
 cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl<<endl;
 cout<<" PRESS 1.BOOKINGS OF TRAVEL "<<endl;
 cout<<" PRESS 2.BOOKINGS OF HOTELS "<<endl;
 cout<<" PRESS 3.MODIFY "<<endl;
 cout<<" PRESS 4.DELETE "<<endl;
 cout<<" PRESS 0.MAIN MENU "<<endl;
 cout<<endl<<"         ENTER CHOICE ";
 choice=getch();
  switch(choice)
    {
   case'1':
   ne(memno1);
   break;

   case'2':
   dis(memno1);
   break;

   case'3':
   modify(x.memno);
   break;

   case'4':
   del(x.memno);
   break;

   case'0':
   x.main_menu();
   break;

   case'9':
   break;

   default:
   cout<<endl<<"ENTER VALID CHOICE";
   break;
  }
   break;
    }
  }
  if(f==0)
  {
  cout<<"NO THANKS";
  getch();
  }
 fin.close();
 getch();
 }

 void del(int a)
 {
 int f=0;
 ifstream fin;
 fin.open("mem.dat",ios::binary);
 ofstream fout;
 fout.open("temp.dat",ios::binary);
 while(fin.read((char *)&x,sizeof(x)))
 {
 if(a==x.memno)
  {
 f=1;
  }
 else
  {
 fout.write((char *)&x, sizeof(x));
  }
 }
 fout.close();
 fin.close();
 remove("mem.dat");
 rename("TEMP.dat","MEM.dat");
 if(f==1)
 {
 header();
 cout<<"MEMBER DELETD"<<endl<<endl;
 cout<<"PRESS ANY KEY TO CONTINUE ";
 getch();
 }
 }

 void modify(int a)
 {
 int f=0;
 char ch,ch1,ch2;
 ifstream fin;
 fin.open("mem.dat",ios::binary);
 ofstream fout;
 fout.open("temp.dat",ios::binary,ios::app);
 while(fin.read((char *)&x,sizeof(x)))
 {
 if(a==x.memno)
 {
 clrscr();
 header();
 f=1;
 fin.open("mem.dat",ios::binary,ios::in|ios::out|ios::app);
 cout<<"  MODIFYING NAME IS "<<x.name<<endl;
 cout<<"  WANT TO MODIFY IT (y/n) ";
 cin>>ch;
 if(ch=='y'||ch=='Y')
 {
 cout<<endl<<"  ENTER MODIFIED NAME ";
 gets(x.name);
 }
 cout<<endl<<"  MODIFYING AGE IS "<<x.age<<endl;
 cout<<"  WANT TO MODIFY IT (y/n) ";
 cin>>ch1;
 if(ch1=='y'||ch=='Y')
 {
 cout<<endl<<"  ENTER MODIFIED AGE " ;
 cin>>x.age;
 }
 fout.write((char*)&x,sizeof(x));
 }
 else
 {
 fout.write((char *)&x, sizeof(x));
 }
 }
 fout.close();
 fin.close();
 remove("mem.dat");
 rename("TEMP.dat","MEM.dat");
 if(f==1)
 {
 cout<<endl<<endl<<"                          !!MEMBER MODIFIED!!"<<endl<<endl;
 cout<<"           PRESS ANY KEY TO CONTINUE ";
 getch();
 }
 }
 }y;

//				     TRAVEL

 class tra_vel
 {
 public:
 int memno;
 char from[30],to[30];
 int distance;
 int dd;
 int mm;
 int yy;

 void travel()
 {
 int choice;
 header();
 cout<<"ENTER MEMBRSHIP NUMBER ";
 cin>>memno;
 cout<<"FROM ";
 gets(from);
 cout<<endl<<endl;
 cout<<"TO ";
 gets(to);
 cout<<endl<<endl;
 cout<<"ENTER DISTANCE ";
 cin>>distance;
 cout<<endl<<endl;
 cout<<"TRAVELLING DATE (dd/mm/yy) ";
 cin>>dd>>mm>>yy;
 header();
 cout<<"PRESS 1. BY BUS "<<endl;
 cout<<"PRESS 2. BY TRAIN "<<endl;
 cout<<"PRESS 3. BY PLANE "<<endl;
 cout<<"PRESS 4. MAIN_MENU "<<endl;
 }

 void bus(int distance)
 {
 float rate;
 int choice,time;
 time=distance/60+1;
 rate=distance*2;
 rate+=18*rate/100;
 header();
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<"\t"<<"|  1.KALRA BUS                 |"<<endl;
 cout<<"\t"<<"|  Departure Time ::  5::00 AM |"<<endl;
 cout<<"\t"<<"|  Reaching Time  ::  "<<5+time<<"::00 AM |"<<endl;
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<endl;
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<"\t"<<"|  2.VOLVO BUS                 |"<<endl;
 cout<<"\t"<<"|  Departure Time :: 12::00 PM |"<<endl;
 cout<<"\t"<<"|  Reaching Time  :: "<<12+time<<"::00 PM |"<<endl;
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<endl;
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<"\t"<<"|  3.RED BUS                   |"<<endl;
 cout<<"\t"<<"|  Departure Time ::  7::00 PM |"<<endl;
 cout<<"\t"<<"|  Reaching Time  :: "<<7+time<<"::00 PM |"<<endl;
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<endl<<"PRESS 1.FOR CONTINUE "<<endl;
 cout<<"PRESS ANYOTHER FOR MAIN MENU "<<endl;
 cout<<"ENTER CHOICE ";
 choice=getch();
 switch(choice)
 {
 case'1':
 pay_bill(rate,time);
 break;

 default:
 x.main_menu();
 break;
 }
 }

 void train(int distance)
 {
 float rate;
 int choice,time;
 time=distance/70+1;
 rate=distance*1.5;
 rate+=18*rate/100;
 header();
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<"\t"<<"|  1.SHAHEED EXPRESS           |"<<endl;
 cout<<"\t"<<"|  Departure Time ::  5::00 AM |"<<endl;
 cout<<"\t"<<"|  Reaching Time  ::  "<<5+time<<"::00 AM |"<<endl;
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<endl;
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<"\t"<<"|  2.INTERCITY                 |"<<endl;
 cout<<"\t"<<"|  Departure Time :: 12::00 PM |"<<endl;
 cout<<"\t"<<"|  Reaching Time  :: "<<12+time<<"::00 PM |"<<endl;
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<endl;
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<"\t"<<"|  3.GAREEB RATH               |"<<endl;
 cout<<"\t"<<"|  Departure Time ::  7::00 PM |"<<endl;
 cout<<"\t"<<"|  Reaching Time  :: "<<7+time<<"::00 PM |"<<endl;
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<endl<<"PRESS 1.FOR CONTINUE "<<endl;
 cout<<"PRESS ANYOTHER FOR MAIN MENU "<<endl;
 cout<<"ENTER CHOICE ";
 choice=getch();
 switch(choice)
 {
 case'1':
 pay_bill(rate,time);
 break;

 default:
 x.main_menu();
 break;
 }
 }

 void plane(int distance)
 {
 char ch[30];
 float rate;
 int choice,time;
 time=distance/150+1;
 rate=distance*5;
 rate+=18*rate/100;
 header();
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<"\t"<<"|  1.SHARANA AIRLINES          |"<<endl;
 cout<<"\t"<<"|  Departure Time ::  5::00 AM |"<<endl;
 cout<<"\t"<<"|  Reaching Time  ::  "<<5+time<<"::00 AM |"<<endl;
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<endl;
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<"\t"<<"|  2.INDIAN AIRLINES           |"<<endl;
 cout<<"\t"<<"|  Departure Time :: 12::00 PM |"<<endl;
 cout<<"\t"<<"|  Reaching Time  :: "<<12+time<<"::00 PM |"<<endl;
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<endl;
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<"\t"<<"|  3.JET AIRWAYS               |"<<endl;
 cout<<"\t"<<"|  Departure Time ::  5::00 PM |"<<endl;
 cout<<"\t"<<"|  Reaching Time  ::  "<<5+time<<"::00 PM |"<<endl;
 cout<<"\t"<<"--------------------------------"<<endl;
 cout<<endl<<"PRESS 1.FOR CONTINUE "<<endl;
 cout<<"PRESS ANYOTHER FOR MAIN MENU "<<endl;
 cout<<"ENTER CHOICE ";
 choice=getch();
 switch(choice)
 {
 case'1':
 pay_bill(rate,time);
 break;

 default:
 x.main_menu();
 break;
 }
 }


 void pay_bill(float rate,int time)
 {
 char name[30];
 header();
 cout<<"ENTER NAME "<<endl<<"(BUS/TRAIN/PLANE) ";
 gets(name);
 getch();
 header();
 cout<<"_____________________________________PAY BILL___________________________________"<<endl;
 cout<<"\t"<<"       	MEMBERSHIP NUMBER   "<<memno<<endl;
 cout<<"	      	TRAVELLING FROM     "<<from<<endl;
 cout<<"	        TRAVELLING TO       "<<to<<endl;
 cout<<"		DISTANCE TRAVELLED  "<<distance<<endl;
 cout<<"		PAYMENT             RS "<<rate<<endl;
 cout<<"		JOURNEY TIME        "<<time<<" hrs"<<endl;
 cout<<"________________________________________________________________________________";
 gotoxy(5,18);
 cout<<"NOTE "<<endl;
 cout<<"1.This is a system generated receipt."<<endl;
 cout<<"2.Read the TERMS AND CONDITIONS carefully."<<endl;
 cout<<"3.Total fare includes all charges including Basic fare, government taxes."<<endl;
 cout<<"4.Refund and cancellation will not be entertained once the booking is confirmed."<<endl;
 gotoxy(20,15);
 cout<<"PRESS ANY KEY TO CONTINUE ";
 getch();
 payment();
 }
 }w;

 void ol()
 {
 int choice;
 ofstream fout4;
 fout4.open("A.dat",ios::binary,ios::app);
 w.travel();
 fout4.write((char*) &w , sizeof(w));
 fout4.close();
 cout<<endl<<"         ENTER CHOICE ";
 choice=getch();
 switch(choice)
 {
 case'1':
 w.bus(w.distance);
 break;

 case'2':
 w.train(w.distance);
 break;

 case'3':
 w.plane(w.distance);
 break;

 case'9':
 break;
 }
 }

 void ne(int h)
 {
 int k=0;
 char b;
 tra_vel l;
 ifstream fin1;
 fin1.open("A.dat",ios::binary);
 while(fin1.read((char*)&l,sizeof(l)))
 {
 if(h==l.memno)
 {
 header();
 cout<<l.memno<<"\t"<<l.from<<"\t"<<l.to<<"\t"<<l.distance<<"\t"<<l.dd<<"/"<<l.mm<<"/"<<l.yy;
 k=1;
 gotoxy(10,15);
 cout<<"WANT TO CANCEL BOOKING (y/n)";
 cin>>b;
 if(b=='y'||b=='Y')
 {
 travel_del(h);
 }
 }
 }
 if(k=='0')
 {
 header();
 cout<<"NO RECORD FOUND"<<endl;
 getch();
 }
 fin1.close();
 }

 class hot_el
 {
 public:
 int memno;
 char city[30];
 int days;
 struct da
 {
 int d;
 int m;
 int y;
 }B;
 struct da1
 {
 int d1;
 int m1;
 int y1;
 }C;
 void hotel()
 {
 int choice;
 header();
 cout<<"ENTER MEMBERSHIP NUMBER ";
 cin>>memno;
 cout<<endl<<"ENTER CITY ";
 gets(city);
 cout<<endl<<"NUMBER OF DAYS ";
 cin>>days;
 cout<<endl<<"CHECK IN DATE (dd/mm/yy)";
 cin>>B.d>>B.m>>B.y;
 cout<<endl<<"CHECK OUT DATE (dd/mm/yy)";
 cin>>C.d1>>C.m1>>C.y1;
 header();
 cout<<"\t"<<"-----------------------------------------------------"<<endl;
 cout<<"\t"<<"|  1.HOTEL RADDISON                                 |"<<endl;
 cout<<"\t"<<"|  STAR RATING -->>>  * * *                         |"<<endl;
 cout<<"\t"<<"|  BREAKFAST AND MEAL INCLUDED         ' YES '      |"<<endl;
 cout<<"\t"<<"-----------------------------------------------------"<<endl;
 cout<<endl;
 cout<<"\t"<<"-----------------------------------------------------"<<endl;
 cout<<"\t"<<"|  2.HOTEL TAJ                                      |"<<endl;
 cout<<"\t"<<"|  STAR RATING -->>>  * * * *                       |"<<endl;
 cout<<"\t"<<"|  BREAKFAST AND MEAL INCLUDED         ' YES '      |"<<endl;
 cout<<"\t"<<"-----------------------------------------------------"<<endl;
 cout<<endl;
 cout<<"\t"<<"-----------------------------------------------------"<<endl;
 cout<<"\t"<<"|  3.HOTEL THE GRAND                                |"<<endl;
 cout<<"\t"<<"|  STAR RATING -->>>  * * * * *                     |"<<endl;
 cout<<"\t"<<"|  BREAKFAST AND MEAL INCLUDED         ' YES '      |"<<endl;
 cout<<"\t"<<"-----------------------------------------------------"<<endl;
 cout<<endl<<"PRESS 1.FOR CONTINUE "<<endl;
 cout<<"PRESS ANYOTHER FOR MAIN MENU "<<endl;
 }

 void bill()
 {
 int pament;
 pament=1000*days;
 char name[30];
 header();
 cout<<"ENTER NAME OF HOTEL ";
 gets(name);
 getch();
 header();
 cout<<"_____________________________________PAY BILL___________________________________"<<endl;
 cout<<"\t"<<"       	MEMBERSHIP NUMBER   "<<memno<<endl;
 cout<<"	      	CITY                "<<city<<endl;
 cout<<"	        DAYS                "<<days<<endl;
 cout<<"		CHECK IN            "<<B.d<<"/"<<B.m<<"/"<<B.y<<endl;
 cout<<"		CHECK OUT           "<<C.d1<<"/"<<C.m1<<"/"<<C.y1<<endl;
 cout<<"		PAYMENT             "<<pament<<endl;
 cout<<"________________________________________________________________________________";
 gotoxy(5,18);
 cout<<"NOTE "<<endl;
 cout<<"1.This is a system generated receipt."<<endl;
 cout<<"2.Read the TERMS AND CONDITIONS carefully."<<endl;
 cout<<"3.Total fare includes all charges including Basic fare, government taxes."<<endl;
 cout<<"4.Refund and cancellation will not be entertained once the booking is confirmed."<<endl;
 gotoxy(20,15);
 cout<<"PRESS ANY KEY TO CONTINUE ";
 getch();
 payment();
 }
 }z;

 void safe()
 {
 int choice;
 ofstream fout;
 fout.open("hotls.dat",ios::binary,ios::app);
 z.hotel();
 fout.write((char*)&z,sizeof(z));
 fout.close();
 cout<<"ENTER CHOICE ";
 choice=getch();
 switch(choice)
 {
 case'1':
 z.bill();
 break;

 default:
 x.main_menu();
 break;
 }
 }

//			    MEMBER FUCTION DEFINATION

 void dis(int a)
 {
 char b;
 hot_el k;
 ifstream fin2;
 fin2.open("hotls.dat",ios::binary);
 while(fin2.read((char*)&k,sizeof(k)))
 {
 if(a==k.memno)
 {
 header();
 cout<<k.memno<<"\t"<<k.city<<"\t"<<k.days<<"\t"<<k.B.d<<"/"<<k.B.m<<"/"<<k.B.y<<"\t"<<k.C.d1<<"/"<<k.C.m1<<"/"<<k.C.y1;
 gotoxy(10,15);
 cout<<"WANT TO CANCEL BOOKING (y/n)";
 cin>>b;
 if(b=='y'||b=='Y')
 {
 hotel_del(a);
 }
 }
 }
 fin2.close();
 }

 void travel_del (int j)
 {
 int f=0;
 ifstream fin;
 fin.open("A.dat",ios::binary);
 ofstream fout;
 fout.open("temp.dat",ios::binary);
 while(fin.read((char *)&x,sizeof(x)))
 {
 if(j==x.memno)
  {
 f=1;
  }
 else
  {
 fout.write((char *)&x, sizeof(x));
  }
 }
 fout.close();
 fin.close();
 remove("A.dat");
 rename("TEMP.dat","A.dat");
 if(f==1)
 {
 header();
 cout<<"BOOKING DELETD"<<endl<<endl;
 cout<<"PRESS ANY KEY TO CONTINUE ";
 getch();
 }
 }

 void hotel_del(int a)
 {
 int f=0;
 ifstream fin;
 fin.open("hotls.dat",ios::binary);
 ofstream fout;
 fout.open("temp.dat",ios::binary);
 while(fin.read((char *)&x,sizeof(x)))
 {
 if(a==x.memno)
  {
 f=1;
  }
 else
  {
 fout.write((char *)&x, sizeof(x));
  }
 }
 fout.close();
 fin.close();
 remove("hotls.dat");
 rename("TEMP.dat","hotls.dat");
 if(f==1)
 {
 header();
 cout<<"BOOKING DELETD"<<endl<<endl;
 cout<<"PRESS ANY KEY TO CONTINUE ";
 getch();
 }
 }

 void payment()
 {
 char naam[30];
 long number;
 header();
 cout<<"  CARD DETAILS  "<<endl;
 cout<<"________________"<<endl;
 cout<<endl<<"ENTER NAME OF CARD HOLDER ";
 gets(naam);
 cout<<"ENTER CARD NUMBER ";
 cin>>number;
 getch();
 header();
 gotoxy(10,8);
 cout<<"!! PAYMENT SUCCESSFULL !!";
 gotoxy(10,10);
 cout<<"THANKS FOR BOOKING ";
 gotoxy(8,14);
 cout<<"PRESS ANY KEY TO CONTINUE ";
 getch();
 }

 void about()
 {
 header();
 cout<<"    AGREEMENT BETWEEN USER AND US "<<endl;
 cout<<"  __________________________________"<<endl;
 cout<<endl<<"APPLICABILITY "<<endl;
 cout<<"This user agreement along with terms of sevice forms the tc for the use of this app. " <<endl;
 cout<<endl<<"CONTENT"<<endl;
 cout<<"All content are registered by us and protected under applicable intellectual property laws "<<endl;
 cout<<endl<<"PRICING "<<endl;
 cout<<"the total price displayed on the payment page includes basic fare, taxes and convinence fees. If user does not pay the entire amount we reserve the right to cancel booking "<<endl;
 cout<<endl<<endl<<endl<<"PRESS ANY KEY FOR MAIN MENU !!! ";
 getch();
 }

 void contact()
 {
 header();
 cout<<"    CONTACT US"<<endl;
 cout<<"  --------------"<<endl<<endl;
 cout<<endl<<"  MOBILE NUMBERS  "<<endl;
 cout<<"                   8895959595"<<endl;
 cout<<"                   9998999898"<<endl;
 cout<<endl<<endl<<"  EMAIL ID "<<endl;
 cout<<"                   nishu941@gmail.com"<<endl;
 cout<<endl<<endl<<endl<<"PRESS ANY KEY FOR MAIN MENU !!! ";
 getch();
 }

//                             PROGRAM ENDED