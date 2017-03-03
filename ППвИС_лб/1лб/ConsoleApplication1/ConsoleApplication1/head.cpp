#include "head.h"

void cube::set()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			gran1[i][j] = 1;
			gran2[i][j] = 2;
			gran3[i][j] = 3;
			gran4[i][j] = 4;
			gran5[i][j] = 5;
			gran6[i][j] = 6;
		}
}

void cube::p1() 
{
	for (int j = 0; j < 3; j++)
		swap(gran3[0][j], gran4[0][j]);

	for (int j = 0; j < 3; j++)
		swap(gran4[0][j], gran5[0][j]);

	for (int j = 0; j < 3; j++)
		swap(gran5[0][j], gran2[0][j]);	

	swap(gran1[0][0], gran1[2][0]);
	swap(gran1[2][0], gran1[2][2]);
	swap(gran1[2][2], gran1[0][2]);

	swap(gran1[0][1], gran1[1][0]);
	swap(gran1[1][0], gran1[2][1]);
	swap(gran1[2][1], gran1[1][2]);

}

void cube::p2()
{
	for (int j = 0; j < 3; j++)
		swap(gran3[0][j], gran2[0][j]);

	for (int j = 0; j < 3; j++)
		swap(gran2[0][j], gran5[0][j]);

	for (int j = 0; j < 3; j++)
		swap(gran5[0][j], gran4[0][j]);

	swap(gran1[0][0], gran1[0][2]);
	swap(gran1[0][2], gran1[2][2]);
	swap(gran1[2][2], gran1[2][0]);

	swap(gran1[1][0], gran1[1][2]);
	swap(gran1[1][2], gran1[2][1]);
	swap(gran1[2][1], gran1[1][0]);
}

void cube::p3()
{
	for (int i = 0; i < 3; i++)
		swap(gran1[i][0], gran5[i][2]);

	for (int i = 0; i < 3; i++)
		swap(gran5[i][2], gran6[i][0]);

	for (int i = 0; i < 3; i++)
		swap(gran6[i][0], gran3[i][0]);

	swap(gran2[0][0], gran2[2][0]);
	swap(gran2[2][0], gran2[2][2]);
	swap(gran2[2][2], gran2[0][2]);

	swap(gran2[0][1], gran2[1][0]);
	swap(gran2[1][0], gran2[2][1]);
	swap(gran2[2][1], gran2[1][2]);
}

void cube::p4()
{
	for (int i = 0; i < 3; i++)
		swap(gran1[i][0], gran3[i][0]);

	for (int i = 0; i < 3; i++)
		swap(gran3[i][0], gran6[i][0]);

	for (int i = 0; i < 3; i++)
		swap(gran6[i][0], gran5[i][2]);

	swap(gran2[0][0], gran2[0][2]);
	swap(gran2[0][2], gran2[2][2]);
	swap(gran2[2][2], gran2[2][0]);

	swap(gran2[1][0], gran2[1][2]);
	swap(gran2[1][2], gran2[2][1]);
	swap(gran2[2][1], gran2[1][0]);
}

void cube::p5()
{
	for (int j = 0; j < 3; j++)
		swap(gran1[2][j], gran2[j][2]);

	for (int j = 0; j < 3; j++)
		swap(gran2[j][2], gran6[0][j]);

	for (int j = 0; j < 3; j++)
		swap(gran6[0][j], gran4[j][0]);

	swap(gran3[0][0], gran3[2][0]);
	swap(gran3[2][0], gran3[2][2]);
	swap(gran3[2][2], gran3[0][2]);

	swap(gran3[0][1], gran3[1][0]);
	swap(gran3[1][0], gran3[2][1]);
	swap(gran3[2][1], gran3[1][2]);
}

void cube::p6()
{
	for (int j = 0; j < 3; j++)
		swap(gran1[2][j], gran4[j][0]);

	for (int j = 0; j < 3; j++)
		swap(gran4[j][0], gran6[0][j]);

	for (int j = 0; j < 3; j++)
		swap(gran6[0][j], gran2[j][2]);

	swap(gran3[0][0], gran3[0][2]);
	swap(gran3[0][2], gran3[2][2]);
	swap(gran3[2][2], gran3[2][0]);

	swap(gran3[1][0], gran3[1][2]);
	swap(gran3[1][2], gran3[2][1]);
	swap(gran3[2][1], gran3[1][0]);
}

void cube::p7()
{
	for (int i = 0; i < 3; i++)
		swap(gran1[i][2], gran3[i][2]);

	for (int i = 0; i < 3; i++)
		swap(gran3[i][2], gran6[i][2]);

	for (int i = 0; i < 3; i++)
		swap(gran6[i][2], gran5[i][0]);

	swap(gran4[0][0], gran4[2][0]);
	swap(gran4[2][0], gran4[2][2]);
	swap(gran4[2][2], gran4[0][2]);

	swap(gran4[0][1], gran4[1][0]);
	swap(gran4[1][0], gran4[2][1]);
	swap(gran4[2][1], gran4[1][2]);
}

void cube::p8()
{
	for (int i = 0; i < 3; i++)
		swap(gran1[i][2], gran5[i][0]);

	for (int i = 0; i < 3; i++)
		swap(gran5[i][0], gran6[i][2]);

	for (int i = 0; i < 3; i++)
		swap(gran6[i][2], gran3[i][2]);

	swap(gran4[0][0], gran4[0][2]);
	swap(gran4[0][2], gran4[2][2]);
	swap(gran4[2][2], gran4[2][0]);

	swap(gran4[1][0], gran4[1][2]);
	swap(gran4[1][2], gran4[2][1]);
	swap(gran4[2][1], gran4[1][0]);
}

void cube::p9()
{
	for (int i = 0; i < 3; i++)
		swap(gran1[0][i], gran4[i][2]);

	for (int i = 0; i < 3; i++)
		swap(gran4[i][2], gran6[2][i]);

	for (int i = 0; i < 3; i++)
		swap(gran6[2][i], gran2[i][0]);

	swap(gran5[0][0], gran5[2][0]);
	swap(gran5[2][0], gran5[2][2]);
	swap(gran5[2][2], gran5[0][2]);

	swap(gran5[0][1], gran5[1][0]);
	swap(gran5[1][0], gran5[2][1]);
	swap(gran5[2][1], gran5[1][2]);
}

void cube::p10()
{
	for (int i = 0; i < 3; i++)
		swap(gran1[0][i], gran2[i][0]);

	for (int i = 0; i < 3; i++)
		swap(gran2[i][0], gran6[2][i]);

	for (int i = 0; i < 3; i++)
		swap(gran6[2][i], gran4[i][2]);

	swap(gran5[0][0], gran5[0][2]);
	swap(gran5[0][2], gran5[2][2]);
	swap(gran5[2][2], gran5[2][0]);

	swap(gran5[1][0], gran5[1][2]);
	swap(gran5[1][2], gran5[2][1]);
	swap(gran5[2][1], gran5[1][0]);
}

void cube::p11()
{
	for (int j = 0; j < 3; j++)
		swap(gran3[2][j], gran2[2][j]);

	for (int j = 0; j < 3; j++)
		swap(gran2[2][j], gran5[2][j]);

	for (int j = 0; j < 3; j++)
		swap(gran5[2][j], gran4[2][j]);

	swap(gran6[0][0], gran6[2][0]);
	swap(gran6[2][0], gran6[2][2]);
	swap(gran6[2][2], gran6[0][2]);

	swap(gran6[0][1], gran6[1][0]);
	swap(gran6[1][0], gran6[2][1]);
	swap(gran6[2][1], gran6[1][2]);
}

void cube::p12()
{
	for (int j = 0; j < 3; j++)
		swap(gran3[2][j], gran4[2][j]);

	for (int j = 0; j < 3; j++)
		swap(gran4[2][j], gran5[2][j]);

	for (int j = 0; j < 3; j++)
		swap(gran5[2][j], gran2[2][j]);

	swap(gran6[0][0], gran6[0][2]);
	swap(gran6[0][2], gran6[2][2]);
	swap(gran6[2][2], gran6[2][0]);

	swap(gran6[1][0], gran6[1][2]);
	swap(gran6[1][2], gran6[2][1]);
	swap(gran6[2][1], gran6[1][0]);
}

void cube::random()
{
	for (int i = 0; i < 100; i++)
	{
		int x = rand() % 12 + 1;
		
		if (x == 1) p1();
		if (x == 2) p2();
		if (x == 3) p3();
		if (x == 4) p4();
		if (x == 5) p5();
		if (x == 6) p6();
		if (x == 7) p7();
		if (x == 8) p8();
		if (x == 9) p9();
		if (x == 10) p10();
		if (x == 11) p11();
		if (x == 12) p12();
	}
}

void cube::show()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "         ";
		for (int j = 0; j < 3; j++)
			cout << gran1[i][j] << " ";
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << gran2[i][j] << " ";

		cout << "   ";

		for (int j = 0; j < 3; j++)
			cout << gran3[i][j] << " ";

		cout << "   ";

		for (int j = 0; j < 3; j++)
			cout << gran4[i][j] << " ";

		cout << "   ";

		for (int j = 0; j < 3; j++)
			cout << gran5[i][j] << " ";

		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "         ";
		for (int j = 0; j < 3; j++)
			cout << gran6[i][j] << " ";
		cout << endl;
	}
}

