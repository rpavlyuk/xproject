#include "y.h"
struct STUDENT
       {
		char student_fio[SIZEF];   //19b +0   �.�.�. ��㤥��
		char student_par[SIZEP];   //9b  +19  ���� ��஫� ��㤥��
		char student_grp[SIZEG];   //9b  +28  ����� ��㯯�
		int  student_nomer;        //2b  +37  ���浪��� �����
		struct date today0;        //8b  +39  ��� ��砫� ����⨩
		struct date today;         //8b  +47  ���
		float trab;                //4b  +55  �㬬�୮� �६� ࠡ���
		int kzan;                  //2b  +59  ������⢮ ����⨩
		int kt;                    //2b  +61  ������⢮ ��⮢
		int kot;                   //2b  +63  ������⢮ �業�� �� ����
		float sot;                 //4b  +65  �।��� �業�� �� ����
		int kz;                    //2b  +69  ������⢮ �����
		int ekz;                   //2b  +71  �業�� �� ��������
		int koz;                   //2b  +73  ������⢮ ����� �����
		float soz;                 //4b  +75  �।��� �業�� �� �����
		int nrejt;                 //2b  +79  ��砫�� ३⨭�
		int rejt[5];               //10b +81  0-३⨭�, 1-३⨭� ���
		int modul_5[5];            //10b +91  �業�� ����� �� 誠�� 5
		int modul_100[5];          //10b +101 �業�� ����� �� 誠�� 100
		int modul;                 //2b �㬬� ������ ���㫥�
		int ekz_m;                 //2b �業�� �������� �� �����
		//*********
		int izip[10];              //20b ���ᨢ ������� ��ࠬ��஢
		char szip[80];             //80b ����᭠� ��ப�
		//**********
		int flajki[10];            //20b 䫠���
       };

struct std_arr
	{
		char fio[SIZEF];
		unsigned long pos;
	};