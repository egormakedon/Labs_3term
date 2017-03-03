#ifndef head
#define head

#include <iostream>
#include <string>
using namespace std;

namespace lab {

	class Guns
	{
	protected:
		string name;

	public:
		Guns()
		{
			name = "";
		}

		Guns(string input)
		{
			name = input;

		}

		virtual void show();
};

	class Pistols : public virtual Guns
	{

	public:
		int god;
		Pistols()
		{}

		Pistols(string input1, int input2) : Guns()
		{
			name = input1;
			god = input2;
		}

		void show();
};

	class AssaultRifles : public virtual Guns
	{
	private:
		int god;


	public:
		double kalibr;
		AssaultRifles()
		{}

		AssaultRifles(string input1, int input2, double input3) : Guns()
		{
			name = input1;
			god = input2;
			kalibr = input3;
		}

		/*virtual*/ void show();
	};
	
	class SniperRifles : public Guns
	{
	private:
		int god;
		double kalibr;
		int sk;

	public:
		SniperRifles(string input1, int input2, double input3, int input4) : Guns()
		{
			name = input1;
			god = input2;
			kalibr = input3;
			sk = input4;
		}

		void show();
			
		



	};
	
	class PistolsPulemets : public  AssaultRifles, public Pistols
	{
	public:
		PistolsPulemets(string input, int input1, double input2)
		{
			Guns::name = input;
			Pistols::god = input1;
			AssaultRifles::kalibr = input2;
		}

		void show();

	};
}
#endif