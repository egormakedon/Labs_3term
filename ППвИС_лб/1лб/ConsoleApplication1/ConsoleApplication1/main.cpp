#include "head.h"

cube t;

int main()
{
	setlocale(0, "");

	int kl;
	t.set();

	while (true)
	{
		system("cls");
		t.show();

		cout << endl << "1 - поворот верхней грани по ч. стрелке" <<"            "<< "7 - поворот правой грани по ч. стрелке"<<endl;
		cout << "2 - поворот верхней грани против ч. стрелки" << "        " << "8 - поворот правой грани против ч. стрелки\n" << endl;
		cout << "3 - поворот левой грани по ч. стрелке" << "              " << "9 - поворот задней грани по ч. стрелке" << endl;
		cout << "4 - поворот левой грани против ч. стрелки" << "          " << "10 - поворот задней грани против ч. стрелки\n" << endl;
		cout << "5 - поворот центральной грани по ч. стрелке" << "        " << "11 - поворот нижней грани по ч. стрелке" << endl;
		cout << "6 - поворот центральной грани против ч. стрелки" << "    " << "12 - поворот нижней грани против ч. стрелки" << endl<<endl;

		cout << "13 - Скрамбл кубика" << endl << endl;

		cout << "0 - завершение игры" << endl << endl;

		cin >> kl;
		switch (kl)
		{
			case(1):
				t.p1();
				break;

			case(2):
				t.p2();
				break;

			case(3):
				t.p3();
				break;

			case(4):
				t.p4();
				break;

			case(5):
				t.p5();
				break;

			case(6):
				t.p6();
				break;

			case(7):
				t.p7();
				break;

			case(8):
				t.p8();
				break;

			case(9):
				t.p9();
				break;

			case(10):
				t.p10();
				break;


			case(11):
				t.p11();
				break;


			case(12):
				t.p12();
				break;

			case(13):
				t.random();
				break;
		}

		if (kl == 0) break;
	}

	return 0;
}