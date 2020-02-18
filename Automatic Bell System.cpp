#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <time.h>//to get system time
#include <windows.h>//to chnge text colours
#include <mmsystem.h>//to play sound of bell (audio in wave format)

struct time
{
int bellno;
int hours;
int minutes;
int seconds;
}T1,T2,T3[30],t5,t6;
int m;

//FUNCTION TO VERIFY PASSWORD FOR ADDING AND DELEING RECORD
int verify_password()
{
char password[10],word[10];
strcpy(password,"abhijith");
cout<<"Enter password:";
for (int i=0;i<strlen(password);i++)
 {
  word[i]=getch();
  cout<<"*";
 }
if(strcmp(word,password)==0)
return(1);
}

//FUNCTION TO ADD BELL TIMING
void addobjects()
{
ofstream fout;
char ch;
fout.open("time1.dat",ios::out|ios::binary|ios::app);
if(!fout)
{
cerr<<"Error in opening";
exit(0);
}
do
{
cout<<"\nEnter time details:\nBell number: ";
cin>>T1.bellno;
cout<<"\nHour: ";
cin>>T1.hours;
cout<<"\nminute: ";
cin>>T1.minutes;
cout<<"\nsecond:";
cin>>T1.seconds;
fout.write((char*)&T1,sizeof(T1));
cout<<"\nDo you wish to add more,Enter y for yes:\n";
cin>>ch;
}
while(ch=='y');
fout.close();
}

//FUNCTION TO DELETE BELL TIMING
void deleterec(int r) //takes bell number that needs to be deleted
{
ofstream fout ("temp.dat",ios::binary);
ifstream fin ("time1.dat",ios::binary);
if(!fout||!fin)
{
cerr<<"Error in opening";
exit(0);
}
int flag=0;
while(fin.read((char*)&t5,sizeof(t5)))
{if(t5.bellno!=r)
fout.write((char*)&t5,sizeof(t5));
else flag=1;
}
fin.close();
fout.close();
remove("time1.dat");
rename("temp.dat","time1.dat");
if(flag==1)
cout<<"\nRecord deleted\n";
else
cout<<"\nRecord not found\n";
}

//FUNCTION TO DISPLAY ALL BELL TIMINGS
void display()
{
ifstream fin;
fin.open("time1.dat",ios::in|ios::binary);
if(!fin)
{
cerr<<"Error in opening";
exit(0);
}
cout<<"\nBell number\thh:mm:ss\n\n";
while(fin.read((char*)&t6,sizeof(t6)))
{
cout<<"    "<<t6.bellno<<"\t\t"<<t6.hours<<":"<<t6.minutes<<":"<<t6.seconds<<"\n" ;}
getch();
}

/*FUNCTION TO READ THE BINARY FILE AND PASS
ALL BELL TIMINGS TO A STRUCTURE FOR COMPARISON*/
void filetostruct()
{
m=0;
time ;
ifstream fin;
fin.open("time1.dat",ios::in|ios::binary);
while(!fin.eof())
{
fin.read((char*)&T2,sizeof(T2));
T3[m].hours=T2.hours;
T3[m].minutes=T2.minutes;
T3[m].seconds=T2.seconds;
m++;}
fin.close();
}

//FUNCTION FOR COMPARING BELL TIMING WITH CURRENT TIME AND GIVE BELL
void comparetime()
{
int count;
system("Color 0B");
while(count<m)
//for(int j=0;;j++)
{
time_t rawtime;
struct tm * timeinfo;
time ( &rawtime );
timeinfo = localtime ( &rawtime );
cout<<"Current time:  "<<timeinfo->tm_hour<<":"<<timeinfo->tm_min<<":"<<timeinfo->tm_sec<<"\n";
for (int l=0;l<m;l++)
{
if (T3[l].hours==timeinfo->tm_hour&&T3[l].minutes==timeinfo->tm_min&&T3[l].seconds==timeinfo->tm_sec)
{
system("Color EC");
PlaySound("schoolbell.wav",NULL,SND_ASYNC|SND_FILENAME);
for (int i=0;i<300;i++)
{
cout<<"TIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\n";
cout<<"TIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\n";
cout<<"TIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\n";
cout<<"TIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\n";
cout<<"TIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\n";
cout<<"TIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\n";
cout<<"TIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\n";
cout<<"TIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\n";
cout<<"TIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\nTIME FOR BELL\n";
}
system("Color 0B");
count++;
}}}
clrscr();
system("Color 0B");
cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tB E L L I N G   F I N I S H E D\n\n\t\t\t\tT H A N K   Y O U";
cout<<"\n\n\n\n\n\n\n\n\t\t\t press any key to exit";
getch();
}

//FUNCTION TO GIVE A BELL MANUALLY
void manualbell()
{
clrscr();
system("Color EC");
PlaySound("schoolbell.wav",NULL,SND_ASYNC|SND_FILENAME);
for (int i=0;i<30;i++)
cout<<"BELLING....\tBELLING....\tBELLING....\tBELLING....\n";
getch();
}

//FUNCTION TO DISPLAY WELCOME PAGE
void welcome()
{
system("Color 0A");
clrscr();
cout<<endl<<endl<<endl<<endl;
cout<<endl;
cout<<"\n\n\t\t\t   *** WELCOME TO ***";
cout<<endl;
cout<<"\n\n\t\tCOMPUTER PROJECT ON AUTOMATIC BELLING SYSTEM";
cout<<"\n\n \t\t\t\t\t\tBY :\n";
cout<<"\n \t\t\t\t\t\tAbhijith SS";
cout<<"\n \t\t\t\t\t\tCLASS:XII";
cout<<"\n\n\n\n\t\t\tpress any key to continue...";
getch();
}

//FUNCTION TO DISPLAY EXIT PAGE
void thanks()
{
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\t********** T H A N K Y O U   F O R   W O R K I N G *******";
cout<<"\n\n\n\n\n\n\n\t\t\t press any key to exit";
getch();
exit(0);
}

void main()
{
clrscr();
welcome();
system("Color 0E");
int opt;
while(opt!=6)
{
system("Color 0E");
clrscr();
cout<<"\n\t====================== MAIN MENU =======================\n";
cout<<"\n\t[1] SHOW BELL TIMINGS";
cout<<"\n\n\t[2] ADD BELL TIMING";
cout<<"\n\n\t[3] DELETE BELL TIMING";
cout<<"\n\n\t[4] START AUTOMATIC BELLING";
cout<<"\n\n\t[5] BELL MANUALLY";
cout<<"\n\n\t[6] QUIT";
cout<<"\n\t=============================================================\n";
cout<<"\n\n\t\tEnter your choice : ";
cin>>opt;
switch(opt)
{
case 1:
clrscr();
system("Color 0F");
cout<<"\n B E L L   T I M I N G S";
cout<<"\n =======================\n";
display();
break;
case 2:
clrscr();
system("Color 0F");
cout<<"\nA D D   B E L L   T I M E";
cout<<"\n=========================\n\n";
int decider;
decider=verify_password();
if(decider==1)
{cout<<"\nAccess granted\n";
addobjects();}
else
{
cout<<"\nPassword doesnot match.Access denied!!\n";
getch();
}
break;
case 3:
clrscr();
system("Color 0F");
cout<<"\nD E L E T E   B E L L   T I M E";
int deciderr,bno;
cout<<"\n================================\n\n";
deciderr=verify_password();
if(deciderr==1)
{
int bno;
char yesorno;
cout<<"\nAccess granted\n";
do
{
cout<<"\nEnter bell number of bell timing to be deleted\n";
cin>>bno;
deleterec(bno);
cout<<"\nDo you want to delete more(y/n)\n";
cin>>yesorno;
}
while(yesorno=='y');
}
else
{
cout<<"\nPassword doesnot match.Access denied!!\n";
getch();
}
break;
case 4:
filetostruct();
comparetime();
break;
case 5:
manualbell();
break;
case 6:
system("Color 0D");
thanks();
break;
default:
cout<<"\n\t\tW R O N G  C H O I C E!!";
getch();
}}
getch();
}


