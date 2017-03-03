#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int MAX_SIZE = 50;
int get_symbol_code(unsigned char in);
char bufRus[256];

class hash_t
{

private:
	struct cell{
		string key;
		bool flag;
		bool collision;
		bool connect;
		int terminal;
		string data;
	};

	cell* table;
public:
	hash_t()
	{
		table = new cell[MAX_SIZE];
		for (int i = 0; i < MAX_SIZE; i++)
		{
			table[i].flag = true;
			table[i].collision = false;
			table[i].connect = false;
			table[i].terminal = 1;
		}
	}
	~hash_t(){
		delete[]table;
	}

	int hashing(string input_key)
	{
		int key_size = input_key.size(); //������ ��������� �����
		//������ � ������� ������������� ��� ������+������ ������ �����+������ ��������� �����
		int addr = key_size - 1 + get_symbol_code(input_key[0]) + get_symbol_code(input_key[key_size - 1]);
		return addr;
	}
	void add_hash(string input_key, string input_data)
	{
		int addr = hashing(input_key);
		if (addr > MAX_SIZE)
		{
			for (int i = 0; i < 79; i++)
				cout << "=";
			cout << endl << " ����� �� ������� �������!" << endl;
			return;
		}
		if (table[addr].flag == true)
		{
			table[addr].key = input_key;
			table[addr].data = input_data;
			table[addr].flag = false;
			
		}
		else 
		if (table[addr].data != input_data & table[addr].key.compare(input_key) != 0)
			{
				table[addr].collision = true;
				table[addr].terminal = 0;
				int new_addr = rehash(addr);
				//table[new_addr].collision = true;
				table[new_addr].key = input_key;
				table[new_addr].data = input_data;
				table[new_addr].flag = false;
				table[new_addr].terminal = 1;
			}
			else
			if (table[addr].data != input_data & table[addr].key.compare(input_key) == 0)
			{
				for (int i = 0; i < 79; i++)
					cout << "=";
				cout << endl << " ������ ����� ��� ������������ ������ ������!" << endl;
			}
			else
			{
				for (int i = 0; i < 79; i++)
					cout << "=";
				cout << endl << " ����� ������ ��� ������� � �������!" << endl;
			}
	}
	int rehash(int addr)
	{
		for (int i = addr; i < MAX_SIZE; i++)
			if (table[i].flag == true)
				return i;
		for (int i = addr; i < 0; i--)
			if (table[i].flag == true)
				return i;
	}
	void print_table(){
		int coll;
		int flag;
		int term; //������������ ������
		int con = 0; //������ �����
		printf(" ---------|---|---|---|---|------------|\n");
		
		/*
		"�"  //������ ��������
		"U"     //������ "������"
		"T"      //������������ ������
		"L"        //������ �����
		"D"    // ������ ������������
		"Po"   //��������� ������� ������������;
		*/
		printf("|   ����  | � | U | T | L |   ������   |\n");
		printf(" ---------|---|---|---|---|------------|\n");
		for (int i = 0; i < MAX_SIZE; i++)
		{
			if (table[i].flag) flag = 0;
			else flag = 1;

			if (table[i].collision) coll = 1;
			else coll = 0;

			char key[1024];
			strcpy(key, table[i].key.c_str());
			char data[1024];
			strcpy(data, table[i].data.c_str());
			term = table[i].terminal;
			printf("|%*s| %d | %d | %d | %d |%*s|\n", 9, key, coll, flag, term, con, 12, data);
			printf(" ---------|---|---|---|---|------------|\n");
		}

	}
	void find(string input_key){
		int sch = 0;
		for (int i = 0; i < MAX_SIZE; i++)
		{
			if (table[i].flag == true)
				continue;
			if (table[i].key.compare(input_key)==0){
				print_found(i);
				sch++;
			}
		}
		if (sch == 0)
			cout << " ������ �� �������!\n";

	}
	void print_found(int addr){
	
		cout << endl;
		for (int i = 0; i < 79; i++)
			cout << "-";
		cout << endl << " ����: " << table[addr].key << endl;
		cout << " ������: " << table[addr].data << endl;	
		for (int i = 0; i < 79; i++)
			cout << "-";
	}

	void del(string input_key){
		int sch = 0;
		for (int i = 0; i < MAX_SIZE; i++){
			if (table[i].flag == true)
				continue;
			if (table[i].key.compare(input_key) == 0)
			{
				int a0 = hashing(input_key);

				for (int j = 0; j < MAX_SIZE; j++)
				{
					if (table[j].flag == true)
						continue;
					int a1 = hashing(table[j].key);
					if (a0 == a1)
					{
						//table[j].flag = true;
						table[j].collision = false;
						table[j].terminal = 1;
						break;
					}
				}
				table[i].flag = true;
				table[i].collision = false;
				table[i].key.clear();
				table[i].data.clear();
				sch++;
			}
		}
		if (sch == 0)
			cout << " ����� ������ ���!\n";
	
		return;
	}
};
int get_symbol_code(unsigned char in)
{
	if (in == (unsigned char)'�')
		return 1;
	if (in == (unsigned char)'�')
		return 2;
	if (in == (unsigned char)'�')
		return 3;
	if (in == (unsigned char)'�')
		return 4;
	if (in == (unsigned char)'�')
		return 5;
	if (in == (unsigned char)'�')
		return 6;
	if (in == (unsigned char)'�')
		return 7;
	if (in == (unsigned char)'�')
		return 8;
	if (in == (unsigned char)'�')
		return 9;
	if (in == (unsigned char)'�')
		return 10;
	if (in == (unsigned char)'�')
		return 11;
	if (in == (unsigned char)'�')
		return 12;
	if (in == (unsigned char)'�')
		return 13;
	if (in == (unsigned char)'�')
		return 14;
	if (in == (unsigned char)'�')
		return 15;
	if (in == (unsigned char)'�')
		return 16;
	if (in == (unsigned char)'�')
		return 17;
	if (in == (unsigned char)'�')
		return 18;
	if (in == (unsigned char)'�')
		return 19;
	if (in == (unsigned char)'�')
		return 20;
	if (in == (unsigned char)'�')
		return 21;
	if (in == (unsigned char)'�')
		return 22;
	if (in == (unsigned char)'�')
		return 23;
	if (in == (unsigned char)'�')
		return 24;
	if (in == (unsigned char)'�')
		return 25;
	if (in == (unsigned char)'�')
		return 26;
	if (in == (unsigned char)'�')
		return 27;
	if (in == (unsigned char)'�')
		return 28;
	if (in == (unsigned char)'�')
		return 29;
	if (in == (unsigned char)'�')
		return 30;
	if (in == (unsigned char)'�')
		return 31;
	if (in == (unsigned char)'�')
		return 32;
	if (in == (unsigned char)'�')
		return 33;

	return 0;

}
#endif //HASH_TABLE_H
