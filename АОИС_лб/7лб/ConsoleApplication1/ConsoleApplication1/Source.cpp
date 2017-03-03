
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
//#include "stdafx.h"

using namespace std;

class Otvet
{
public:
	char *s;
	char n;
	Otvet() { s = NULL; };
	Otvet(char N) { s = new char[N]; n = 0; };
	Otvet(char *S, int N) { s = S; n = N; };
};

void WriteNum(char x)
{
	for (int i = 7; i >= 0; --i)
	{
		printf("%i ", (x & 1 << i) != 0);
	};
	printf("\n");
};

void WriteNumWithIndex(char x, int index)
{
	for (int i = 7; i >= 0; --i)
	{
		if (i == index)
			printf("|%i| ", (x & 1 << i) != 0);
		else
			printf("%i ", (x & 1 << i) != 0);
	};
	printf("\n");
};

bool GetBit(char X, char index)
{
	return (X & 1 << index) != 0;
};

void Write(char *S, int n, int mask, int index)
{
	printf("A   ");
	WriteNumWithIndex(mask, index);
	printf("\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%i   ", i);
		WriteNumWithIndex(S[i], index);
		printf("\n");
	};
	printf("\n");
};

bool FunctionQ(char Arg, char s, int index, bool ** Values)
{
	return (!GetBit(Arg, index) && GetBit(s, index) && !Values[1][index + 1]);
}

bool FunctionL(char Arg, char s, int index, bool ** Values)
{
	return /*Values[1][index+1] || */(GetBit(Arg, index) && !GetBit(s, index) && !Values[0][index + 1]);
}

bool FunQ(char Arg, char s, int index, bool ** Values)
{
	return Values[0][index + 1] || (!GetBit(Arg, index) && GetBit(s, index) && !Values[1][index + 1]);
}

bool FunL(char Arg, char s, int index, bool ** Values)
{
	return Values[1][index + 1] || (GetBit(Arg, index) && !GetBit(s, index) && !Values[0][index + 1]);
}

bool ** InitValues(void)
{
	bool ** Values = new bool*[2];
	Values[0] = new bool[9];
	Values[1] = new bool[9];
	Values[0][8] = Values[1][8] = 0;
	return Values;
};

void OchIn(char * och, char &free, char X)
{
	och[free] = X;
	free++;
};

bool OchOut(char * och, char &free, char &X)
{
	if (free == 0)
		return 0;
	free--;
	X = och[free];
	return 1;
};

char* InitResult(char *S, int n) {
	char * Result = new char[n];
	for (int i = 0; i < n; Result[i] = S[i], ++i);
	return Result;
}

Otvet FindMax(char *S, int n)
{
	char *Result = InitResult(S, n);
	char nn = n;
	bool ** Values = InitValues();
	for (int i = 7; i >= 0; --i)
	{
		char * och = new char[n];
		char free = 0;
		//printf("S q l\n");
		for (int j = 0; j < nn; ++j)
		{
			bool q = FunctionQ(-1, Result[j], i, Values),
				l = FunctionL(-1, Result[j], i, Values);
			if (q == 0 && l == 0)
				OchIn(och, free, Result[j]);
			Values[0][i] = q;
			Values[1][i] = l;
			//printf("%i %i %i\n", j, q, l);
		};
		if (free > 0)
		{
			Result = och;
			nn = free;
		}
		//printf("\n");
		//Write(Result, nn, -1, i);
	};
	for (int i = 0; i < nn; printf("%i ", Result[i]), ++i);
	//printf("\n\n");
	Otvet otvet(Result, nn);
	return otvet;
};

Otvet FindMin(char *S, int n)
{
	char *Result = new char[n], nn = n;
	for (int i = 0; i < n; Result[i] = S[i], ++i);
	bool ** Values = InitValues();
	for (int i = 7; i >= 0; --i)
	{
		char * och = new char[n];
		char free = 0;
		//printf("S q l\n");
		for (int j = 0; j < nn; ++j)
		{
			bool q = FunctionQ(-1, Result[j], i, Values),
				l = FunctionL(-1, Result[j], i, Values);
			if (q == 0 && l == 1)
				OchIn(och, free, Result[j]);
			Values[0][i] = q;
			Values[1][i] = l;
			//printf("%i %i %i\n", j, q, l);
		};
		if (free > 0)
		{
			Result = och;
			nn = free;
		}
		//printf("\n");
		//Write(Result, nn, -1, i);
	};
	for (int i = 0; i < nn; printf("%i ", Result[i]), ++i);
	//printf("\n\n");
	Otvet otvet(Result, nn);
	return otvet;
};

void WriteOtvet(Otvet otvet)
{
	for (int i = 0; i < otvet.n; printf("%i ", otvet.s[i]), ++i);
};

bool *** InitValuesTable(int n) {
	bool *** Values = new bool**[n];
	for (int i = 0; i < n; ++i) Values[i] = InitValues();
	return Values;
}

Otvet FindMore(char *S, int n)
{
	char *Result = new char[n], nn = n;
	for (int i = 0; i < n; Result[i] = S[i], ++i);
	printf("Номер:\n");
	char *X = new char;
	scanf("%i", X);
	Otvet otvet(n);
	bool *** Values = InitValuesTable(n);
	for (int i = 0; i<n; printf("%i ", Result[i]), ++i); printf("\n");
	for (int i = 7; i >= 0; --i)
	{
		char * och = new char[n];
		char free = 0;
		//printf("  q l\n");
		for (int j = 0; j < nn; ++j)
		{
			bool q = FunQ(*X, Result[j], i, Values[j]),
				l = FunL(*X, Result[j], i, Values[j]);
			Values[j][0][i] = q;
			Values[j][1][i] = l;
			//printf("%i %i %i\n", free, q, l);
		};
		if (free > 0)
		{
			Result = och;
			nn = free;
		}
		//printf("\n");
		//Write(Result, nn, *X, i);
	};
	otvet.n = 0;
	for (int i = 0; i < n; ++i)
		if (Values[i][0][0] == 1)
			OchIn(otvet.s, otvet.n, S[i]);
	//WriteOtvet(otvet);
	//printf("\n\n");
	return otvet;
};

void TheWorstOfTheBest(char *S, int n)
{
	Otvet otvet = FindMore(S, n);
	otvet = FindMin(otvet.s, otvet.n);
	//WriteOtvet(otvet);
};

Otvet FindMoreMin(char *S, int n)
{
	char *Result = new char[n], nn = n;
	for (int i = 0; i < n; Result[i] = S[i], ++i);
	printf("Номер:\n");
	char *X = new char;
	scanf("%i", X);
	Otvet otvet(n);
	bool *** Values = InitValuesTable(n);
	for (int i = 0; i<n; printf("%i ", Result[i]), ++i); printf("\n");
	for (int i = 7; i >= 0; --i)
	{
		char * och = new char[n];
		char free = 0;
		//printf("  q l\n");
		for (int j = 0; j < nn; ++j)
		{
			bool q = FunQ(*X, Result[j], i, Values[j]),
				l = FunL(*X, Result[j], i, Values[j]);
			Values[j][0][i] = q;
			Values[j][1][i] = l;
			//printf("%i %i %i\n", free, q, l);
		};
		if (free > 0)
		{
			Result = och;
			nn = free;
		}
		//printf("\n");
		//Write(Result, nn, *X, i);
	};
	otvet.n = 0;
	for (int i = 0; i < n; ++i)
		if (Values[i][1][0] == 1)
			OchIn(otvet.s, otvet.n, S[i]);
	//WriteOtvet(otvet);
	//printf("\n\n");
	return otvet;
};

void TheWorstOfTheBestMin(char *S, int n)
{
	Otvet otvet = FindMoreMin(S, n);
	otvet = FindMax(otvet.s, otvet.n);
	//WriteOtvet(otvet);
};

void Test(char *S, int n) {
	int i;
l2:
	printf("1 - Поиск максимального\n2 - Поиск минимального\n3 - Поиск ближайшего сверху\n4 - Поиск ближайшего снизу\n"); //4 - Find More than\n0 - exit\n
	scanf("%i", &i);
	switch (i)
	{
	case 1: {FindMax(S, n); _getch(); system("cls"); goto l2; };
	case 2: {FindMin(S, n); _getch(); system("cls");  goto l2; };
	case 3: {TheWorstOfTheBest(S, n); _getch(); system("cls"); goto l2; };
	case 4: {TheWorstOfTheBestMin(S, n); _getch(); system("cls"); goto l2; };
	default: break;
	};
}

int ReadNum(void) {
	int n;
	printf("Количечтво элементов:\n");
	scanf("%i", &n);
	return n;
}

char * ReadData(int n) {
	//printf("Элементы:");
	char * S = new char[n];
	for (int j = 0; j < n; ++j)
	{
		S[j] = rand() % 10;

		//	scanf_s("%i", S + j);
		//printf("%i ", S[j]);
	};
	return S;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 5;//ReadNum();
	char * S = ReadData(n);
	Test(S, n);
	return 0;
}
