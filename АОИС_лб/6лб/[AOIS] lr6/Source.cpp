
#pragma warning (disable : 4996)
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "hash.h"
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	hash_t h;
	int size, temp=0;
	string in_key, in_data;
	string find_key, find_data;
	
	FILE *in = fopen("input.txt", "r");
	if (!in) {
		printf("Ошибка! Невозможно открыть файл");
		exit(1);
	}
	fscanf(in, "%d", &size);
	for (int i = 0; i < size; i++){
		char buff_key[60];
		char buff_data[60];
		fscanf(in, "%s", buff_key);
		fscanf(in, "%s", buff_data);
		h.add_hash(buff_key, buff_data);
	}
	
	char kod;
	while (true)
	{
		//system("cls");
//		for (int i = 0; i < 79; i++)
	//		cout << "=";
		cout << endl;
		cout << " Просмотр таблицы - 1\n";
		cout << " Добавить запись - 2\n";
		cout << " Поиск записи - 3\n";
		cout << " Удалить запись - 4\n";
		cout << " Выход - 0\n";
	//	for (int i = 0; i < 79; i++)
		//	cout << "=";
		kod = getch();
		system("cls");
		switch (kod)
		{
		case '1':
			h.print_table();
			break;
		case '2':
			cout << "Введите ключ:\n";
			cin >> in_key;
			cout << "Введите данные:\n";
			cin >> in_data;
			h.add_hash(in_key, in_data);
			break;
		case '3':
			cout << "Введите ключ:\n";
			cin >> find_key;
			for (int i = 0; i < 79; i++)
				cout << "=";
			h.find(find_key);
			cout << endl;
			break;
		case '4':
			cout << "Введите ключ:\n";
			cin >> find_key;
			h.del(find_key);
			break;
		case '0':
			return 0;
			exit(0);
		}
	}
}
