#include <stdio.h>
#include <conio.h>
#include <fstream.h>
#include <stdlib.h>
#include <math.h>
#include <dir.h>
#include <dos.h>
#include <string.h>
#include "x.h"

fstream f;
char path[MAXPATH];
char jpath[MAXPATH];
char fio[SIZEF], grp[SIZEG], init[10];
char error[255];
struct STUDENT setup;
struct date dt;

void main()
{
 cout<<"@2002 DjPavlik EDO Setup Utility"<<endl<<"All rights reserved."<<endl
     <<"Created by DjPavlik"<<endl<<"E-mail: djpavlik@torba.com"<<endl
     <<"NOTE! Is recomended you to run KEYUKR.COM first."<<endl;
 cout<<endl<<"Enter PATH where you store your EDO files (ex.:A:\\EDO)>";
 cin>>path;
 sprintf(jpath,"%s\\jurnaldo.dat",path);
 f.open(path, ios::in | ios::out);
 if(!f)
 {
  sprintf(error,"Could not open\\create files in %s",path);
  cout<<endl<<error<<endl;
  exit(0);
 }
 cout<<"Sirname(ex. Петренко)>"; scanf("%s",&fio);cout<<"Initials(ex. П.П.)>";
 scanf("%s",&init);
 sprintf(setup.student_fio,"%s %s",fio,init);

 cout<<"Group:"; scanf("%s",&grp); sprintf(setup.student_grp,"%s",grp);
 getdate(&dt);
 setup.today0.da_year=(int)dt.da_year;
 setup.today0.da_day=(char)dt.da_day;
 setup.today0.da_mon=(char)dt.da_mon;

 f.seekg(0);
 f.write((char*)&setup,sizeof(setup));
 f.close();
 getch();
}