#include <fstream>
#include "world.h"

int main()
{
	setlocale(0, "");

	cout << "		Модель океана, ППВИС - 3лб\n";
	cout << "pl - Планктон		" << "ak - Акула		" << "ko - Косатка\n\n";

	ifstream f1("input.txt");

	int mode, n, m, cycles;
	string end;

	f1 >> mode;
	f1 >> cycles;
	f1 >> n >> m;

	living *w;
	w = new living(n, m);

	while (true)
	{
		int i, j;

		getline(f1, end);

		if (end == "end") break;

		else
		{
			if (end == "pl") { f1 >> i >> j; w->build(i-1, j-1, "pl"); }
			if (end == "ak") { f1 >> i >> j; w->build(i-1, j-1, "ak"); }
			if (end == "ko") { f1 >> i >> j; w->build(i-1, j-1, "ko"); }
		}		
	}
	
	if (mode == 1)
	{
		w->draw();
		for (int i = 0; i < cycles; i++)
		{
			w->next();
			w->draw();
		}		
	}
	
	else if (mode == 2)
	{
		w->draw();
		for (int i = 0; i < cycles; i++)
		{
			w->next();
			system("pause");
			w->draw();
		}
	}

	cout << "END!" << endl;
	delete w;
	f1.close();
	return 0;
}