#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <ctime>
using namespace std;
void binary(int mass[], int numb, int n)
{
	int j = n - 1;
	while (numb != 0)
	{
		mass[j] = numb % 2;
		numb /= 2;
		--j;
	}
}
void convertMass(int razr[][17], int n)
{
	int arr[17][17] = { 0 }, temp[17][17] = { 0 };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[j][i] = razr[i][j];
	int sch = 0;
	for (int i = 0, j; i < n; i++)
	{
		sch = 0;
		j = i;
		while (sch < n)
		{
			temp[j][i] = arr[sch][i];
			j++;
			sch++;
			if (j == n)
				j = 0;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			razr[i][j] = temp[i][j];
}
void convertMassBack(int razr[][17], int n)
{
	int arr[17][17] = { 0 }, temp[17][17] = { 0 }, sch = 0;
	for (int i = 0, j; i < n; i++)
	{
		j = i;
		sch = 0;
		while (sch < n)
		{
			temp[sch][i] = razr[j][i];
			j++;
			sch++;
			if (j == n)
				j = 0;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			razr[i][j] = temp[j][i];
}
void show(int mass[], int n)
{
	for (int i = 0; i < n; i++)
		cout << mass[i] << ' ';
	cout << endl;
}
void show(int mass[][17], int arr[], int n)
{
	cout << "Диагональная матрица: \n\n";

	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(3) << mass[i][j];
		}
		cout << setw(5) << arr[i] << endl;

		cout << endl;
	}
	
}
void show(int mass[][17], int n, bool flag = false)
{
	if (flag == false)
		convertMassBack(mass, n);
	cout << "\nМатрица: \n";
	cout << ' ';
	cout << endl;
	for (int i = 0; i<n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			cout << setw(3) << mass[i][j];
		}
		cout << endl << endl;
	}
	if (flag == false)
		convertMass(mass, n);
}
void show(int mass[][17], int n, int count)
{
	cout << "Ответ: \n";
	int t = 0;
	for (int i = 0; i<count; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(3) << mass[i][j];
		}
		cout << endl << endl;
		if (t == 0)
			for (int j = n - 1; j >= 0; j--)
				t = t + mass[i][j] * (int)pow(2, n - j - 1);
	}
	cout << "В десятичном виде: ";
	for (int i = 0; i < count; i++)
		cout << t << ' ';
	cout << endl;
}
void showBase(int mass[][17], int arr[], int n)
{
	convertMassBack(mass, n);
	int t = 0;
	cout << "Числа, представленные в матрице: ";
	for (int i = 0; i < n; i++)
	{
		t = 0;
		for (int j = n - 1; j >= 0; j--)
			t = t + mass[i][j] * (int)pow(2, n - j - 1);
		cout << t << ' ';
	}
	t = 0;
	for (int i = n - 1; i >= 0; i--)
		t = t + arr[i] * (int)pow(2, n - i - 1);
	cout << endl << "Буферный регистр: " << t << endl;
	_getch();
	convertMass(mass, n);
}
int main()
{
	void NearBelow(int razr[][17], int mass[], int n);
	void Not(int mass[][17], int arr[], int n);
	void Max(int mass[][17], int[], int n);
	void Min(int mass[][17], int[], int n);
	void And(int mass[][17], int arr[], int n);
	void Sum(int mass[][17], int arr[], int n);
	void NearAlow(int razr[][17], int mass[], int n);
	void Or(int mass[][17], int arr[], int n);
	void Oror(int mass[][17], int arr[], int n);
	void AndAnd(int mass[][17], int arr[], int n);
	void No(int mass[][17], int arr[], int n);
	void Impl(int mass[][17], int arr[], int n);
	int ReadWord(int mass[][17], int arr[], int n);
	void WriteWord(int mass[][17], int arr[], int n);
	void ShowFirstMatr(int[][17], int);
	void WriteRow(int[][17], int[], int);
	void menu(int&, int);
	void ReadRow(int[][17], int[], int);
	void Sort(int razr[][17], int mass[], int n);
	setlocale(LC_ALL, "Russian");
	int n, razr[17][17] = { 0 }, numbers[17] = { 0 }, arr[17][17] = { 0 }, mass[17] = { 0 };
	cout << "введите число 0-16\n"; cin >> n;
	int qwe = 0;
	for (int i = 0; i < n - 1; i++)
		qwe = qwe + pow(2, i);
	for (int i = 0; i < n; i++)
	{
		numbers[i] = rand() % qwe;
		binary(razr[i], numbers[i], n);
	}
	int x, choice;
	cout << "введите число:\n"; cin >> x;
	binary(mass, x, n);
	show(razr, n, true);
	cout << endl;
	convertMass(razr, n);
	show(razr, mass, n);
	while (true)
	{
		menu(choice, n);
		switch (choice) {
		case 1: ReadRow(razr, mass, n); break;
		case 2: WriteRow(razr, mass, n); break;
		case 3: WriteWord(razr, mass, n); break;
		case 4: ReadWord(razr, mass, n); break;
		case 5: And(razr, mass, n); break;
		case 6: Or(razr, mass, n); break;
		case 7: Not(razr, mass, n); break;
		case 8: ShowFirstMatr(razr, n); break;
		case 9: show(razr, mass, n); break;
		case 10: showBase(razr, mass, n); break;
		case 11: Sum(razr, mass, n); break;
		case 12: Sort(razr, mass, n); break;
		case 13: Oror(razr, mass, n); break;
		case 14: AndAnd(razr, mass, n); break;
		case 15: No(razr, mass, n); break;
		case 16: Impl(razr, mass, n); break;
			/*case 8: NearBelow(razr, mass, n); break;
			case 9: NearAlow(razr, mass, n); break;
			case 10: Min(razr, mass, n); break;
			case 11: Max(razr, mass, n); break;
			case 12: ShowFirstMatr(razr, n); break;
			case 13: show(razr, mass, n); break;
			case 14: showBase(razr, mass, n); break;
			case 15: Sum(razr, mass, n); break;
			case 16: Sort(razr, mass, n); break;
			case 17: Oror(razr, mass, n); break;
			case 18: AndAnd(razr, mass, n); break;
			case 19: No(razr, mass, n); break;
			case 20: Impl(razr, mass, n); break;*/
		case 0: return 0;
		default: cout << "Нет такого пункта меню!!!"; continue;
		}

	}
	_getch();
	return 0;
}
void Sum(int razr[][17], int mass[], int n)
{
	string s;
	int bin[3] = { 0 };
	convertMassBack(razr, n);
	cout << "Введите аргумент поиска 000-111: "; cin >> s;
	bin[0] = s[0] - '0';
	bin[1] = s[1] - '0';
	bin[2] = s[2] - '0';
	int sj[5] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			if (razr[i][j] != bin[j])
				goto metka;
		int t, q;
		t = razr[i][3] * pow(2, 3) + razr[i][4] * pow(2, 2) + razr[i][5] * pow(2, 1) + razr[i][6];
		q = razr[i][7] * pow(2, 3) + razr[i][8] * pow(2, 2) + razr[i][9] * pow(2, 1) + razr[i][10];
		t = t + q;
		binary(sj, t, 5);
		razr[i][11] = sj[0];
		razr[i][12] = sj[1];
		razr[i][13] = sj[2];
		razr[i][14] = sj[3];
		razr[i][15] = sj[4];
	metka:;
	}
	convertMass(razr, n);
}
bool isAll(int ans[][17], int row, int n, int c = 1)
{
	for (int i = 0; i < n; i++)
		if (ans[i][row] == c)
			return false;
	return true;
}
void Max(int razr[][17], int arr[], int n)
{
	convertMassBack(razr, n);
	int sch = n;
	int ans[17][17] = { 0 };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans[i][j] = razr[i][j];
	for (int i = 0; i < n; i++)
	{
		if (isAll(ans, i, sch) == true)
			continue;
		for (int j = sch - 1; j >= 0; j--)
			if (ans[j][i] == 0)
			{
				for (int k = j; k < sch; k++)
					for (int m = 0; m < n; m++)
						ans[k][m] = ans[k + 1][m];
				sch--;
			}
	}
	convertMass(razr, n);
	show(ans, n, sch);
	for (int i = 0; i < n; i++)
		arr[i] = ans[0][i];
}
void Min(int razr[][17], int arr[], int n)
{
	convertMassBack(razr, n);
	int sch = n;
	int ans[17][17] = { 0 };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans[i][j] = razr[i][j];
	for (int i = 0; i < n; i++)
	{
		if (isAll(ans, i, sch, 0) == true || isAll(ans, i, sch) == true)
			continue;
		for (int j = sch - 1; j >= 0; j--)
			if (ans[j][i] == 1)
			{
				for (int k = j; k < sch; k++)
					for (int m = 0; m < n; m++)
						ans[k][m] = ans[k + 1][m];
				sch--;
			}
	}
	convertMass(razr, n);

	show(ans, n, sch);
	for (int i = 0; i < n; i++)
		arr[i] = ans[0][i];
}
void NearAlow(int razr[][17], int mass[], int n)
{
	bool flag = false;
	convertMassBack(razr, n);
	int g[17][17] = { 0 }, l[17][17] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			g[i][j] = g[i][j - 1] | ((!mass[j - 1]) & razr[i][j - 1] & (!l[i][j - 1]));
			l[i][j] = l[i][j - 1] | (mass[j - 1] & (!razr[i][j - 1]) & (!g[i][j - 1]));
		}
	}
	cout << 'g' << ' ' << 'l' << endl;
	for (int i = 0; i < n; i++)
		cout << g[i][n] << ' ' << l[i][n] << endl;
	convertMass(razr, n);
	showBase(razr, mass, n);
	convertMassBack(razr, n);
	show(razr, n, true);
	int ans[17][17] = { 0 }, sch = 0;
	for (int i = 0; i < n; i++)
	{
		if (g[i][n] == 1 & l[i][n] == 0)
		{
			for (int j = 0; j < n; j++)
				ans[sch][j] = razr[i][j];
			sch++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (isAll(ans, i, sch, 0) == true || isAll(ans, i, sch) == true)
			continue;
		for (int j = sch - 1; j >= 0; j--)
			if (ans[j][i] == 1)
			{
				for (int k = j; k < sch; k++)
					for (int m = 0; m < n; m++)
						ans[k][m] = ans[k + 1][m];
				sch--;
			}
	}
	convertMass(razr, n);
	if (sch == 0)
		cout << "Нет таких чисел!!!\n";
	else
		show(ans, n, sch);

}
void NearBelow(int razr[][17], int mass[], int n)
{
	convertMassBack(razr, n);
	int g[17][17] = { 0 }, l[17][17] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			g[i][j] = g[i][j - 1] | ((!mass[j - 1]) & razr[i][j - 1] & (!l[i][j - 1]));
			l[i][j] = l[i][j - 1] | (mass[j - 1] & (!razr[i][j - 1]) & (!g[i][j - 1]));
		}
	}
	cout << 'g' << ' ' << 'l' << endl;
	for (int i = 0; i < n; i++)
		cout << g[i][n] << ' ' << l[i][n] << endl;
	convertMass(razr, n);
	showBase(razr, mass, n);
	show(razr, n, true);
	convertMassBack(razr, n);
	int ans[17][17] = { 0 }, sch = 0;
	for (int i = 0; i < n; i++)
	{
		if (g[i][n] == 0 & l[i][n] == 1)
		{
			for (int j = 0; j < n; j++)
				ans[sch][j] = razr[i][j];
			sch++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (isAll(ans, i, sch) == true)
			continue;
		for (int j = sch - 1; j >= 0; j--)
			if (ans[j][i] == 0)
			{
				for (int k = j; k < sch; k++)
					for (int m = 0; m < n; m++)
						ans[k][m] = ans[k + 1][m];
				sch--;
			}
	}
	convertMass(razr, n);
	if (sch == 0)
		cout << "Нет таких чисел!!!\n";
	else
		show(ans, n, sch);

}
void And(int mass[][17], int arr[], int n)
{
	int s1, s2, d;
	cout << "Введите 1 разрядный столбец: "; cin >> s1;
	cout << "Введите 2 разрядный столбец: "; cin >> s2;
	cout << "Введите номер разрядного столбца для ответа: "; cin >> d;
	convertMassBack(mass, n);
	for (int i = 0; i < n; i++)
		arr[i] = mass[i][s1];
	for (int i = 0; i < n; i++)
		mass[i][d] = (arr[i] & mass[i][s2]);
	convertMass(mass, n);
}
void Or(int mass[][17], int arr[], int n)
{
	int s1, s2, d;
	cout << "Введите 1 разрядный столбец: "; cin >> s1;
	cout << "Введите 2 разрядный столбец: "; cin >> s2;
	cout << "Введите номер разрядного столбца для ответа: "; cin >> d;
	convertMassBack(mass, n);
	for (int i = 0; i < n; i++)
		arr[i] = mass[i][s1];
	for (int i = 0; i < n; i++)
		mass[i][d] = (arr[i] | mass[i][s2]);
	convertMass(mass, n);
}
void Oror(int mass[][17], int arr[], int n)
{
	int s1, s2, d;
	cout << "Введите 1 разрядный столбец: "; cin >> s1;
	cout << "Введите 2 разрядный столбец: "; cin >> s2;
	cout << "Введите номер разрядного столбца для ответа: "; cin >> d;
	convertMassBack(mass, n);
	for (int i = 0; i < n; i++)
		arr[i] = mass[i][s1];
	for (int i = 0; i < n; i++) {
		if (arr[i] == mass[i][s2])
			mass[i][d] = 0;
		else mass[i][d] = 1;
	}
	convertMass(mass, n);
}
void No(int mass[][17], int arr[], int n)
{
	int s1, s2, d;
	cout << "Введите 1 разрядный столбец: "; cin >> s1;
	cout << "Введите 2 разрядный столбец: "; cin >> s2;
	cout << "Введите номер разрядного столбца для ответа: "; cin >> d;
	convertMassBack(mass, n);
	for (int i = 0; i < n; i++)
		arr[i] = mass[i][s1];
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0 && mass[i][s2] == 1)
			mass[i][d] = 1;
		else mass[i][d] = 0;
	}
	convertMass(mass, n);
}
void AndAnd(int mass[][17], int arr[], int n)
{
	int s1, s2, d;
	cout << "Введите 1 разрядный столбец: "; cin >> s1;
	cout << "Введите 2 разрядный столбец: "; cin >> s2;
	cout << "Введите номер разрядного столбца для ответа: "; cin >> d;
	convertMassBack(mass, n);
	for (int i = 0; i < n; i++)
		arr[i] = mass[i][s1];
	for (int i = 0; i < n; i++) {
		if (arr[i] == mass[i][s2])
			mass[i][d] = 1;
		else mass[i][d] = 0;
	}
	convertMass(mass, n);
}
void Not(int mass[][17], int arr[], int n)
{
	int s1, d;
	cout << "Введите 1 разрядный столбец: "; cin >> s1;
	cout << "Введите номер разрядного столбца для ответа: "; cin >> d;
	convertMassBack(mass, n);
	for (int i = 0; i < n; i++)
		arr[i] = mass[i][s1];
	for (int i = 0; i < n; i++)
		mass[i][d] = (!arr[i]);
	convertMass(mass, n);
}
void Impl(int mass[][17], int arr[], int n)
{
	int s1, s2, d;
	cout << "Введите 1 разрядный столбец: "; cin >> s1;
	cout << "Введите 2 разрядный столбец: "; cin >> s2;
	cout << "Введите номер разрядного столбца для ответа: "; cin >> d;
	convertMassBack(mass, n);
	for (int i = 0; i < n; i++)
		arr[i] = mass[i][s1];
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0 && mass[i][s2] == 1)
			mass[i][d] = 0;
		else mass[i][d] = 1;
	}
	convertMass(mass, n);
}
void Sort(int razr[][17], int mass[], int n)
{
	convertMassBack(razr, n);
	int ans[17][17] = { 0 }, t[17] = { 0 };
	for (int i = 0; i < n; i++)
		for (int j = n - 1, sch = 0; j >= 0; j--, sch++)
		{
			t[i] = t[i] + razr[i][j] * pow(2, sch);
		}
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (t[j] < t[j - 1])
				swap(t[j], t[j - 1]);
	int temp[17] = { 0 };
	for (int i = 0; i < n; i++)
	{
		binary(temp, t[i], n);
		for (int j = 0; j < n; j++)
			razr[i][j] = temp[j];
	}
	convertMass(razr, n);
}
int ReadWord(int mass[][17], int arr[], int n)
{
	int row, ans = 0;
	cout << "Введите номер разрядного столбца, с которого хотите считать: "; cin >> row;
	convertMassBack(mass, n);
	for (int i = n - 1, j = 0; i >= 0; i--, j++)
	{
		arr[i] = mass[row][i];
		ans = ans * 10 + arr[i];
	}
	convertMass(mass, n);
	return ans;
}
void WriteWord(int mass[][17], int arr[], int n)
{
	int numb, temp[17] = { 0 }, row;
	cout << "Введите число, которое хотите записать: "; cin >> numb;
	cout << "Введите номер разрядного столбца, куда хотите записать: "; cin >> row;
	binary(temp, numb, n);
	convertMassBack(mass, n);
	for (int i = 0; i < n; i++)
	{
		mass[row][i] = temp[i];
		arr[i] = temp[i];
	}
	convertMass(mass, n);
}
void WriteRow(int mass[][17], int arr[], int n)
{
	int choice;
	cout << "Введите номер разрядного столбца: "; cin >> choice;
	convertMassBack(mass, n);
	for (int i = n - 1, j = 0; i >= 0; i--, j++)
		mass[n - i - 1][choice] = arr[j];
	convertMass(mass, n);
}
void ShowFirstMatr(int razr[][17], int n)
{
	convertMassBack(razr, n);
	show(razr, n, true);
	convertMass(razr, n);
}
void ReadRow(int mass[][17], int arr[], int n) {
	int choice;
	cout << "Выберите номер разрядного столбца: ";
	while (true)
	{
		cin >> choice;
		if (choice < 0 || choice >= n)
		{
			cout << "Нет такого разрядного столбца!!!\nПопробуйте еще раз: ";
			continue;
		}
		convertMassBack(mass, n);
		for (int i = 0, j = n - 1; i < n; j--, i++)
			arr[n - i - 1] = mass[j][choice];
		convertMass(mass, n);
		break;
	}
}
void menu(int& choice, int n)
{
	cout << endl;
	cout << "Выберите действие:\n";
	cout << "1 - Считывание разрядного столбца" << endl;
	cout << "2 - Запись в память разрядного столбца" << endl;
	cout << "3 - Запись слова в память" << endl;
	cout << "4 - Считывание слова из памяти" << endl;
//	cout << "5 - Конъюнкция (И)" << endl;
	cout << "6 - Дизъюнкция (ИЛИ)" << endl;
	cout << "7 - Отрицание (НЕ)" << endl;
	/*	cout << "8 - Поиск ближайшего снизу" << endl;
	cout << "9 - Поиск ближайшего сверху" << endl;
	cout << "10 - Поиск наименьшего числа" << endl;
	cout << "11 - Поиск наибольшего числа" << endl;
	cout << "12 - Показать матрицу" << endl;
	cout << "13 - Показать диагональную матрицу" << endl;
	cout << "14 - Показать в десятичном виде" << endl;
	cout << "15 - Cумма Aj и Bj" << endl;
	cout << "16 - Упорядоченная выборка (сортировка)" << endl;
	cout << "17 - Неравнозначность (ИЛИ-ИЛИ)" << endl;
	cout << "18 - Эквивалентность (И-И)" << endl;
	cout << "19 - Запрет 2-го аргумента (НЕТ)" << endl;
	cout << "20 - Импликация от 2-го аргумента к 1-му" << endl;*/
	cout << "8 - Показать матрицу" << endl;
	cout << "9 - Показать диагональную матрицу" << endl;
//	cout << "10 - Показать в десятичном виде" << endl;
	cout << "11 - Cумма Aj и Bj" << endl;
//	cout << "12 - Упорядоченная выборка (сортировка)" << endl;
	cout << "13 - Неравнозначность (ИЛИ-ИЛИ)" << endl;
	cout << "14 - Эквивалентность (И-И)" << endl;
//	cout << "15 - Запрет 2-го аргумента (НЕТ)" << endl;
//	cout << "16 - Импликация от 2-го аргумента к 1-му" << endl;
	cout << "0 - Выход" << endl;
	cin >> choice;
	cout << endl;
}