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

		cout << endl << "1 - ������� ������� ����� �� �. �������" <<"            "<< "7 - ������� ������ ����� �� �. �������"<<endl;
		cout << "2 - ������� ������� ����� ������ �. �������" << "        " << "8 - ������� ������ ����� ������ �. �������\n" << endl;
		cout << "3 - ������� ����� ����� �� �. �������" << "              " << "9 - ������� ������ ����� �� �. �������" << endl;
		cout << "4 - ������� ����� ����� ������ �. �������" << "          " << "10 - ������� ������ ����� ������ �. �������\n" << endl;
		cout << "5 - ������� ����������� ����� �� �. �������" << "        " << "11 - ������� ������ ����� �� �. �������" << endl;
		cout << "6 - ������� ����������� ����� ������ �. �������" << "    " << "12 - ������� ������ ����� ������ �. �������" << endl<<endl;

		cout << "13 - ������� ������" << endl << endl;

		cout << "0 - ���������� ����" << endl << endl;

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