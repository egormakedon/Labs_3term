#include "Header.h"

void lab::Guns::show()
{
	cout << name << endl;
}

void lab::Pistols::show()
{
	cout << "..Название: " << name << endl << "  Год: " << god << endl;
}

void lab::AssaultRifles::show() {
	cout << "..Название: " << name << endl << "  Год: " << god << endl << "  Калибр: " << kalibr << endl;
}

void lab::SniperRifles::show() {
	cout << "..Название: " << name << endl << "  Год: " << god << endl << "  Калибр: " << kalibr << endl << "  Начальная скорость пули: " << sk << endl;
}

void lab::PistolsPulemets::show()
{
	cout << "  ..Название: " << name << endl << "    Год: " << Pistols::god << endl << "    Калибр: " << kalibr << endl;
}