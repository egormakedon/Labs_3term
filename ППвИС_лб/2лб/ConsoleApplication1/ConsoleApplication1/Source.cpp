#include "Header.h"
//using namespace lab;

void main()
{
	setlocale(LC_ALL, "rus");

	Guns obj1("Пистолеты:");
	
	Guns obj2("Автоматы:");

	Guns obj4("..Пистолеты-пулеметы:");
	
	Guns obj3("Снайперские винтовки:");
		
	Pistols objPistols1("ПМ",1948);

	Pistols objPistols2("Glock",1963);

	Pistols objPistols3("Walther P99",1994);

	AssaultRifles objAssaultRifles1("АК", 1947,7.62);

	AssaultRifles objAssaultRifles2("Colt M4", 1984,5.56);

	AssaultRifles objAssaultRifles3("FAMAS", 1981,5.56);

	SniperRifles objSniperRifles1("СВД", 1958, 7.62,830);

	PistolsPulemets objk("Uzi",1948,9);

	obj1.show();
	
	objPistols1.show();
	objPistols2.show();
	objPistols3.show();

	obj2.show();

	objAssaultRifles1.show();
	objAssaultRifles2.show();
	objAssaultRifles3.show();

	obj4.show();

	objk.show();

	obj3.show();

	objSniperRifles1.show();
}