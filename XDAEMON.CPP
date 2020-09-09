//Dear students,
//we know how is it difficult to pass all that modular tests,
//to get good marks, to have a valid rating that gives you the
//chance to pass modulars etc.
//This program is your dream, this program will help you get
//a good result in 0.001 seconds.
//Here is a full source code of XDEAMON util.
//*********************
//*Created by DjPavlik*
//*********************
//<><><><><><><><><><><><><
//E-mail>>djpavlik@ukr.net<
//<><><><><><><><><><><><><
//UNIX forever !!! Visit www.FreeBSD.org NOW !!!
////////////////////////////////////////////////
//All rights reserved.
//Version 1.2.0.2


#include <stdio.h>
#include <conio.h>
#include <fstream.h>
#include <stdlib.h>
#include <math.h>
#include <dir.h>
#include <dos.h>
#include <string.h>
#include "x.h"


fstream fconf, fjur;
char path[MAXPATH],jpath[MAXPATH];
struct std_arr stud[60];

void Spysok(int,int);
void ShowStatistics(int,int);
void ShowData(int);
int Menu();
void Personal(int);
void Edit(int);
void Close();

void main()
{

 char sname[20], sname1[5], fio[SIZEF];
 long pos=0,cor_pos;
 int count,num=0;

 fconf.open("xconf",ios::in | ios::nocreate);
 if(!fconf) { cout<<"Couldn't open CONFIG"<<endl; getch();return;}
 fconf>>path;
 if(path) cout<<"Path for use: "<<path<<endl;
 fconf.close();

 //opening jurnal
 sprintf(jpath,"%s\\jurnal.dat",path);
 fjur.open(jpath,ios::in | ios::nocreate | ios::binary);
 if(!fjur) {cout<<"JURNAL could not be opened!!!"<<endl; getch();return;}
 fjur.seekg(pos);
 cout<<"Hacking JURNAL.";
 do
 {
  fjur>>sname;
  fjur>>sname1;
  printf("Trying >>"); printf(sname);
  sprintf(stud[num].fio,"%s %s",sname,sname1);
  /*Correction !!!*/
   cor_pos=0;
   while(!fjur.eof())
   {
    fjur.seekg(cor_pos);
    fjur.read((char*)&fio,sizeof(fio));
    if(!strcmpi(stud[num].fio,fio))
    {
     stud[num].pos=cor_pos;
     break;
    }
    cor_pos++;
   }
  /*END*/
  printf(">>Entry point fixed at %i>> *SUCCESS!!!* \n",cor_pos);
  pos+=sizeof(STUDENT);
  num++;
  fjur.seekg(pos);
 }
 while(!fjur.eof());
 cout<<endl<<"WELL DONE !!!"<<endl;
 fjur.close();
 count=num-1;

 while(1)
 {
  int mnu=Menu();
  switch(mnu)
  {
   case 1: Personal(count);break;
   case 2: Edit(count);break;
   case 3: ShowStatistics(0,count);
   case 4: cout<<"Better send me E-mail: djpavlik@ukr.net"<<endl;
	   getch();
	   break;
   case 5: {Close(); break;}
  }
 }


 /*
 char key;
 cout<<"Again?(Y/N)";
 cin>>key;
 if(key=='y' || key=='Y') goto begin;
 //if(key=='n' || key=='N') exit(0);
 ShowStatistics(0,count);
 getch();                */

}

void Spysok(int from, int to)
{
 clrscr();
 int i,j=0;
 for(i=from;i<to;i++,j++)
 {
  if(j<20)
  {
   printf("%i.%s\n",i+1,stud[i].fio);
  }
  if(j>=20&&j<40)
  {
   gotoxy(25,i-19);
   printf("%i.%s",i+1,stud[i].fio);
  }
  if(j>=40&&j<60)
  {
   gotoxy(50,i-39);
   printf("%i.%s",i+1,stud[i].fio);
  }
 }
 gotoxy(1,22);
}

void ShowData(int stud_num)
{
 long rec_pos;
 struct STUDENT std;
 rec_pos=stud[stud_num].pos;
 fjur.open(jpath,ios::in | ios::nocreate | ios::binary);
 fjur.seekg(rec_pos);
 fjur.read((char*)&std,sizeof(std));
 printf("Name: %s\n",std.student_fio);
 printf("Password: %s\n",std.student_par);
 printf("Group: %s\n",std.student_grp);
 printf("Number: %i\n",std.student_nomer);
 printf("Start date: %i-%i-%i\n",std.today0.da_day,std.today0.da_mon,std.today0.da_year);
 printf("Last date: %i-%i-%i\n",std.today.da_day,std.today.da_mon,std.today.da_year);
 printf("All working time: %f\n",std.trab);
 printf("Lessons number: %i\n",std.kzan);
 printf("Tests number: %i\n",std.kt);
 printf("Number of tests' marks: %i\n",std.kot);
 printf("Avarage test mark: %f\n",std.sot);
 printf("Number of questions: %i\n",std.kz);
 printf("Number of answered questions: %i\n",std.koz);
 printf("Avarage questions mark: %f\n",std.soz);
 printf("EKZAMEN mark: %i\n",std.ekz);
 printf("Start REJTING: %i\n",std.nrejt);
 printf("REJTING: %i | %i | %i\n" , std.rejt[0], std.rejt[1], std.rejt[2]);
 printf("Module in 5 marks scale: %i | %i\n",std.modul_5[0], std.modul_5[1]);
 printf("Module in 100 marks scale: %i | %i\n",std.modul_100[0], std.modul_100[1]);
 printf("Module total: %i\n", std.modul);
 printf("Ekzamen by modules: %i\n", std.ekz_m);
 fjur.close();
}

void ShowStatistics(int from, int to)
{
 long rec_pos=0;
 int format=0;
 struct STUDENT rec;
 fstream jur;

 printf("Name\t\tGroup\tRating\tModular#1\tModular#2\tTotal\tEkzamen\n");
 jur.open(jpath,ios::in | ios::binary | ios::nocreate);
 for(int z=1;z<80;z++) printf("-");
 cout<<endl;
 for(int i=from;i<to;i++)
 {
  rec_pos=stud[i].pos;
  jur.seekg(rec_pos);
  jur.read((char*)&rec,sizeof(rec));
  //printf("%s\t %s\t %i\t %i\t %i\t %i\t %i\n",rec.student_fio,rec.student_grp,
  //	 rec.nrejt,rec.modul_100[0],rec.modul_100[1],rec.modul,rec.ekz);
  if(strlen(rec.student_fio)>15)
  {
   sprintf(rec.student_fio,"Mr.LongX");
  }
  cout<<rec.student_fio<<"\t"<<rec.student_grp<<"\t"<<
  rec.nrejt<<"\t"<<rec.modul_100[0]<<"\t\t"<<
  rec.modul_100[1]<<"\t\t"<<rec.modul<<"\t"<<rec.ekz<<endl;

  format++;
  if(format>20){cout<<"Press any key to continue..."<<endl; getch(); format=0;}

 }
 jur.close();
 cout<<endl<<"Any key to MAIN MENU"<<endl;
}

int Menu()
{
 int choise;
 clrscr();
 cout<<"@2002 Lviv Polytechnic HACKERS Group"<<endl
     <<"Leaded by DJ P. All rights reserved."<<endl
     <<"SOON you'll see	FULL UKRANIAN version of the program."<<endl
     <<"E-mail: 6719449@sms.umc.com.ua"<<endl
     <<endl<<"PROGRAMMING: DJ P. - main source, hacking & uncoding this shit"<<endl
     <<"e[X]eN - assistance, file accessing modules (he is my broth.)"<<endl
     <<"Cheetah & Poisson - testing, moral help"<<endl;
 cout<<endl<<"What do you want to do:"<<endl<<"1. View your personal status."
     <<endl<<"2. CHANGE something here."<<endl<<"3. View statistics."
     <<endl<<"4. Send MONEY for author of the program :-)"
     <<endl<<"5. Close this thing."<<endl<<endl;
 cout<<"Your choise(1-5) ";
 choise=getch();
 if(choise=='1') return(1);
 if(choise=='2') return(2);
 if(choise=='3') return(3);
 if(choise=='4') return(4);
 if(choise=='5') return(5);
 else return(0);
}

void Personal(int num)
{
 int unum;
 int count=num-1;
 clrscr();
 Spysok(0,num);
 in:
 cout<<"Type number according to your name: ";
 cin>>unum;
 if(unum<1||unum>count+1) {cout<<"WRONG number."<<endl;goto in;}
 ShowData(unum-1);
 cout<<endl<<"Any key to MAIN MENU"<<endl;
 getch();
}
void Edit(int num)
{
 int unum, rejt,mod1,mod2,var;
 float f_var;
 char c_rejt,c_mod1,c_mod2,c_var;
 int count=num-1;
 struct STUDENT data;
 fstream fedit;
 clrscr();
 Spysok(0,num);
 in:
 cout<<"Type number according to your name (for EDIT): ";
 cin>>unum;
 if(unum<1||unum>count+1) {cout<<"WRONG number."<<endl;goto in;}
 fedit.open(jpath,ios::in | ios::out | ios::nocreate | ios::binary);
 fedit.seekg(stud[unum-1].pos);
 fedit.read((char*)&data,sizeof(data));
 edit:
 cout<<endl<<"What do you want to EDIT:"<<endl<<"1. Rating."
     <<endl<<"2. Modular#1."<<endl<<"3. Modular#2"
     <<endl<<"4. Labs count"<<endl<<"5. NUM of questions."
     <<endl<<"6. NUM of answered questions."<<endl<<"7. MAIN"<<endl<<endl;
 cout<<"Your choise(1-7) ";
 int choise=getch();
 switch(choise)
 {
  case '1':cout<<"Enter rating(0-100): ";
	scanf("%i",&rejt); c_rejt=(char)rejt;
	fedit.seekg(stud[unum-1].pos+73);//94 -mod1
	fedit.write((char*)&c_rejt,sizeof(c_rejt));
	break;
  case '2':cout<<"Enter modular#1(0-50): ";
	scanf("%i",&mod1); c_mod1=(char)mod1;
	fedit.seekg(stud[unum-1].pos+93);//94 -mod1
	fedit.write((char*)&c_mod1,sizeof(c_mod1));
	break;
  case '3':cout<<"Enter modular#2(0-50): ";
	scanf("%i",&mod2); c_mod2=(char)mod2;
	fedit.seekg(stud[unum-1].pos+95);//94 -mod1
	fedit.write((char*)&c_mod2,sizeof(c_mod2));
	break;
  case '4':cout<<"Number of labs: ";
	scanf("%i",&var);c_var=(char)var;
	fedit.seekg(stud[unum-1].pos+107);//94 -mod1
	fedit.write((char*)&c_var,sizeof(c_var));
	break;


  case '7':return;
 }
 //fedit.write((char*)&data,sizeof(STUDENT));
 //fedit.seekg(stud[unum-1].pos);
 fedit.close();

 goto edit;
}

void Close()
{
 cout<<endl<<"Closing all open file and descriptors..."<<"Done"<<endl
     <<"Closing program. Thank you for using XDAEMON."<<endl;
 exit(0);
}