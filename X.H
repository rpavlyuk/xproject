#include "y.h"
struct STUDENT
       {
		char student_fio[SIZEF];   //19b +0   ф.и.о. студента
		char student_par[SIZEP];   //9b  +19  личный пароль студента
		char student_grp[SIZEG];   //9b  +28  номер группы
		int  student_nomer;        //2b  +37  порядковый номер
		struct date today0;        //8b  +39  дата начала занятий
		struct date today;         //8b  +47  дата
		float trab;                //4b  +55  суммарное время работы
		int kzan;                  //2b  +59  количество занятий
		int kt;                    //2b  +61  количество тестов
		int kot;                   //2b  +63  количество оценок за тесты
		float sot;                 //4b  +65  средняя оценка за тесты
		int kz;                    //2b  +69  количество задач
		int ekz;                   //2b  +71  оценка на экзамене
		int koz;                   //2b  +73  количество решённых задач
		float soz;                 //4b  +75  средняя оценка за задачи
		int nrejt;                 //2b  +79  начальный рейтинг
		int rejt[5];               //10b +81  0-рейтинг, 1-рейтинг теста
		int modul_5[5];            //10b +91  оценка модуля по шкале 5
		int modul_100[5];          //10b +101 оценка модуля по шкале 100
		int modul;                 //2b сумма баллов модулей
		int ekz_m;                 //2b оценка экзамена по модулю
		//*********
		int izip[10];              //20b массив запасных параметров
		char szip[80];             //80b запасная строка
		//**********
		int flajki[10];            //20b флажки
       };

struct std_arr
	{
		char fio[SIZEF];
		unsigned long pos;
	};