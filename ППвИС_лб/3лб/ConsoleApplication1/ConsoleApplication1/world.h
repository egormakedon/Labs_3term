#ifndef _world_
#define _world_

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <time.h>
using namespace std;

class living
{
protected:
	int N, M;
	int row, column, age, sex;
	living **world;
	string name;
	
public:
	living(){}

	living(int inN, int inM)
	{
		this->N = inN;
		this->M = inM;

		world = new living*[N];

		for (int i = 0; i < N; i++)
			world[i] = new living[M];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				world[i][j].name = "  ";
	}

	~living(){}

	void build(int i, int j, string name);
	void draw();
	void next();

	void move_pl();
	void die_pl();
	void reproduction_pl();

	void move_ak();
	void eat_ak();

	void move_ko();
	void eat_ko();
};

class plankton : public living
{
public:
	plankton(int r, int c) : living()
	{
		name = "pl";
		age = 0;
		row = r;
		column = c;
	}

	~plankton(){}
};

class akula : public living
{
public:
	akula(int r, int c) : living()
	{
		srand(time(0));

		name = "ak";
		age = 0;
		row = r;
		column = c;
		sex = rand() % 2;
	}

	~akula(){}
};

class kosatka : public living
{
public:
	kosatka(int r, int c) : living()
	{
		srand(time(0));

		name = "ko";
		age = 0;
		row = r;
		column = c;
		sex = rand() % 2;
	}

	~kosatka(){}
};

#endif