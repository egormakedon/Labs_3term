#include "Header.h"

void lab::Guns::show()
{
	cout << name << endl;
}

void lab::Pistols::show()
{
	cout << "..��������: " << name << endl << "  ���: " << god << endl;
}

void lab::AssaultRifles::show() {
	cout << "..��������: " << name << endl << "  ���: " << god << endl << "  ������: " << kalibr << endl;
}

void lab::SniperRifles::show() {
	cout << "..��������: " << name << endl << "  ���: " << god << endl << "  ������: " << kalibr << endl << "  ��������� �������� ����: " << sk << endl;
}

void lab::PistolsPulemets::show()
{
	cout << "  ..��������: " << name << endl << "    ���: " << Pistols::god << endl << "    ������: " << kalibr << endl;
}