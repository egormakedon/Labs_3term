#include <iostream>
using namespace std;

void TabIst();
void SDNF();
void TKNF();
void sintez();

int main()
{
	setlocale(0, "");

	cout << "ÎÄÑ-3" << endl << endl;

	TabIst();

	SDNF();

	TKNF();

	sintez();

	return 0;
}

void TabIst()
{
	cout << "Òàáëèöà èñòèííîñòè:" << endl;
	cout << " _________0_____1_____2_____3_____4_____5_____6_____7__" << endl ;
	cout << "|__X1__|__0__|__0__|__0__|__0__|__1__|__1__|__1__|__1__|"<<endl;	
	cout << "|__X2__|__0__|__0__|__1__|__1__|__0__|__0__|__1__|__1__|"<<endl;
	cout << "|__X3__|__0__|__1__|__0__|__1__|__0__|__1__|__0__|__1__|" << endl;
	cout << "|__S___|__0__|__1__|__1__|__0__|__1__|__0__|__0__|__1__|" << endl;
	cout << "|__P___|__0__|__0__|__0__|__1__|__0__|__1__|__1__|__1__|" << endl;
}

void SDNF()
{
	cout << endl;

	cout << "P ÑÄÍÔ(X1i,X2i,X3i) = !X1i*X2i*X3i + X1i*!X2i*X3i + X1i*X2i*!X3i + X1i*X2i*X3i" << endl;
	
	cout << "S ÑÄÍÔ(X1i,X2i,X3i) = !X1i*!X2i*X3i + !X1i*X2i*!X3i + X1i*!X2i*!X3i + X1i*X2i*X3i" << endl;
}

void TKNF()
{
	cout << endl;

	cout << "P ÑÄÍÔ(X1i,X2i,X3i)" << endl;

	cout << " X1 |_______________" << endl;
	cout << "  1 |___|_1_|_1_|_1_|" << endl;
	cout << "  0 |___|___|_1_|___|______" << endl;
	cout << "      00  01  11  10   X2X3" << endl;

	cout << endl;

	cout << "S ÑÄÍÔ(X1i,X2i,X3i)" << endl;

	cout << " X1 |_______________" << endl;
	cout << "  1 |_1_|___|_1_|___|" << endl;
	cout << "  0 |___|_1_|___|_1_|______" << endl;
	cout << "      00  01  11  10   X2X3" << endl;

	cout << endl;

	cout << "P ÒÄÍÔ(X1i,X2i,X3i) = X1i*X3i + X1i*X2i + X2i*X3i" << endl;
	cout << "S ÒÄÍÔ(X1i,X2i,X3i) = !X1i*!X2i*X3i + !X1i*X2i*!X3i + X1i*!X2i*!X3i + X1i*X2i*X3i" << endl;
}

void sintez()
{
	cout << endl;

	cout << "P* = P * (!X1i+!X2i+!X3i)" << endl;
	
	cout << "S = P * (!X1i+!X2i+!X3i) + X1i*X2i*X3i" << endl;
}