#include <iostream>
#include <string>
using namespace std;

struct stroka
{
	char c1[100];
	int kp;
}z[15];

void set(char s[])
{
	cin >> s;
}

void minusotric(char s[])
{
	int i, j;
	i = 0;

	while (true)
	{
		if ((s[i] == '!') && (s[i + 1] == '('))
		{
			int kol = 1, p1, p2, ps;

			j = i + 2;

			while (true)
			{
				if (s[j] == ')') kol--;
				if (s[j] == '(') kol++;

				if (kol == 0) break;
				else j++;
			}

			p1 = i - 1;
			p2 = j + 1;

			char b[50], c[50], a[50];
			for (ps = 0; ps < 50; ps++)
			{
				a[ps] = '.';
				b[ps] = '.';
				c[ps] = '.';
			}

			if (p1 > 0)
			{
				for (ps = 0; ps <= p1; ps++)
					b[ps] = s[ps];
			}

			if (p2 < strlen(s) - 1)
			{
				for (ps = p2; ps < strlen(s); ps++)
					c[ps] = s[ps];
			}

			ps = 2;

			i = i + 2;
			j = j - 1;

			while (true)
			{
				a[ps] = s[i];
				ps = ps + 2;
				if (i == j) break;
				else i++;
			}

			int k = 0;
			while (true)
			{
				if (a[k] == '(')
				{
					a[k - 1] = '!';
					while (true)
					{
						if (a[k] == ')') break;
						else k++;
					}
				}

				if (a[k] == '*')
				{
					a[k] = '+'; k++;
				}
				if (a[k] == '+')
				{
					a[k] = '*';
					k++;
				}
				if (a[k] == 'x')
				{
					a[k - 1] = '!';
				}

				k++;

				if (k >= ps) break;
			}

			for (k = 0; k < strlen(s); k++)
				s[k] = '.';

			k = -1;
			ps = 0;

			if (p1 > 0)
			{
				while (true)
				{
					if (b[ps] == '.') ps++;
					else
					{
						k++;
						s[k] = b[ps];
						ps++;
					}
					if (ps >= 50) break;
				}
			}

			ps = 0;

			while (true)
			{
				if (a[ps] == '.') ps++;
				else
				{
					k++;
					s[k] = a[ps];
					ps++;
				}
				if (ps >= 50) break;
			}

			ps = 0;

			if (p2 < strlen(s) - 1)
			{
				while (true)
				{
					if (c[ps] == '.') ps++;
					else
					{
						k++;
						s[k] = c[ps];
						ps++;
					}
					if (ps >= 50) break;
				}
			}

			for (i = 0; i < strlen(s); i++)
			{
				if ((s[i] == '!') && (s[i + 1] == '!'))
				{
					s[i] = '.';
					s[i + 1] = '.';
				}
			}

			i = 0;

		}

		else i++;

		if (i>strlen(s) - 1) break;

	}
}

void showSDNF(int k1, int k2, char st[], int a)
{
	int kj, i, k;

	for (i = 0; i<a; i++)
		if (st[i] == '+')	kj = i;

	kj++;


	cout << "SDNF: ";

	if (k1 == 1)
	{
		cout << "x1*";
		for (i = 0; i < a; i++)
		{
			if (st[i] == '+') break;
			cout << st[i];
		}
		cout << "+";

		cout << "!x1*";
		for (i = 0; i < a; i++)
		{
			if (st[i] == '+') break;
			cout << st[i];
		}

		cout << "+";
	}

	if (k1 == 2)
	{
		for (i = 0; i < a; i++)
		{
			if (st[i] == '*')
			{
				k = i;
				break;
			}
			cout << st[i];
		}

		cout << "*x2*";

		for (i = k + 1; i < a; i++)
		{
			if (st[i] == '+') break;

			cout << st[i];
		}

		cout << "+";

		for (i = 0; i < a; i++)
		{
			if (st[i] == '*')
			{
				k = i;
				break;
			}
			cout << st[i];
		}

		cout << "*!x2*";

		for (i = k + 1; i < a; i++)
		{
			if (st[i] == '+') break;
			cout << st[i];
		}

		cout << "+";

	}

	if (k1 == 3)
	{
		for (i = 0; i < a; i++)
		{
			if (st[i] == '+') break;
			cout << st[i];
		}



		cout << "*x3+";

		for (i = 0; i < a; i++)
		{
			if (st[i] == '+') break;
			cout << st[i];
		}

		cout << "*!x3+";

	}



	if (k2 == 1)
	{
		cout << "x1*";
		for (i = kj; i < a; i++)
		{
			cout << st[i];
		}
		cout << "+";

		cout << "!x1*";
		for (i = kj; i < a; i++)
		{
			cout << st[i];
		}


	}

	if (k2 == 2)
	{
		for (i = kj; i <a; i++)
		{
			if (st[i] == '*')
			{
				k = i;
				break;
			}
			cout << st[i];
		}

		cout << "*x2*";

		for (i = k + 1; i < a; i++)
		{
			cout << st[i];
		}

		cout << "+";

		for (i = kj; i < a; i++)
		{
			if (st[i] == '*')
			{
				k = i;
				break;
			}
			cout << st[i];
		}

		cout << "*!x2*";

		for (i = k + 1; i < a; i++)
		{
			cout << st[i];
		}


	}

	if (k2 == 3)
	{
		for (i = kj; i < a; i++)
		{
			cout << st[i];
		}

		cout << "*x3+";

		for (i = kj; i < a; i++)
		{
			cout << st[i];
		}

		cout << "*!x3";

	}

	cout << endl;
}

void showSKNF(char st[], int a)
{
	int plus, i, k, kk1, kk2, k1, k2, kk, ii, kol, j, k3,ksk,jkj[10],sum=255,pps[10];

	cout << "SKNF: ";

	char g, h, v[500],vk[500],index[4];

	for (i = 0; i < a; i++)
	{
		if (st[i] == '+') plus = i;
	}

	plus++;

	for (i = 0; i < a; i++)
	{
		if (st[i] == '*')
		{
			k = i;
			break;
		}
	}


	for (i = 0; i < k; i++)
	{
		if ((st[i] != '!') && (st[i] != 'x')) g = st[i];
	}

	for (i = k + 1; i < plus - 1; i++)
	{
		if ((st[i] != '!') && (st[i] != 'x')) h = st[i];
	}


	if (g == '1') k1 = 1;
	if (g == '2') k1 = 2;
	if (g == '3') k1 = 3;
	if (h == '1') k2 = 1;
	if (h == '2') k2 = 2;
	if (h == '3') k2 = 3;

	kk = k;

	for (i = plus; i < a; i++)
	{
		if (st[i] == '*') k = i;
	}

	for (i = plus; i < k; i++)
	{
		if ((st[i] != '!') && (st[i] != 'x')) g = st[i];
	}

	for (i = k + 1; i < a; i++)
	{
		if ((st[i] != '!') && (st[i] != 'x')) h = st[i];
	}


	if (g == '1') kk1 = 1;
	if (g == '2') kk1 = 2;
	if (g == '3') kk1 = 3;
	if (h == '1') kk2 = 1;
	if (h == '2') kk2 = 2;
	if (h == '3') kk2 = 3;


	ii = 0;
	{
		{v[ii] = '(';

		if (k1 < kk1)
		{
			for (i = 0; i < kk; i++)
			{
				ii++;
				v[ii] = st[i];
			}
			ii++;
			v[ii] = '+';

			for (i = plus; i < k; i++)
			{
				ii++;
				v[ii] = st[i];
			}
		}
		else
		{
			for (i = plus; i < k; i++)
			{
				ii++;
				v[ii] = st[i];
			}

			ii++;
			v[ii] = '+';

			for (i = 0; i < kk; i++)
			{
				ii++;
				v[ii] = st[i];
			}
		}
		ii++;
		v[ii] = ')';

		ii++; }

		{v[ii] = '(';

		if (k1 < kk2)
		{
			for (i = 0; i < kk; i++)
			{
				ii++;
				v[ii] = st[i];
			}
			ii++;
			v[ii] = '+';

			for (i = k + 1; i < a; i++)
			{
				ii++;
				v[ii] = st[i];
			}
		}
		else
		{
			for (i = k + 1; i < a; i++)
			{
				ii++;
				v[ii] = st[i];
			}

			ii++;
			v[ii] = '+';

			for (i = 0; i < kk; i++)
			{
				ii++;
				v[ii] = st[i];
			}
		}
		ii++;
		v[ii] = ')';

		ii++; }

		{
			v[ii] = '(';

			if (k2 < kk1)
			{
				for (i = kk + 1; i < plus - 1; i++)
				{
					ii++;
					v[ii] = st[i];
				}
				ii++;
				v[ii] = '+';

				for (i = plus; i < k; i++)
				{
					ii++;
					v[ii] = st[i];
				}
			}
			else
			{
				for (i = plus; i < k; i++)
				{
					ii++;
					v[ii] = st[i];
				}

				ii++;
				v[ii] = '+';

				for (i = kk + 1; i < plus - 1; i++)
				{
					ii++;
					v[ii] = st[i];
				}
			}
			ii++;
			v[ii] = ')';

			ii++;

		}

		{
			v[ii] = '(';

			if (k2 < kk2)
			{
				for (i = kk + 1; i < plus - 1; i++)
				{
					ii++;
					v[ii] = st[i];
				}
				ii++;
				v[ii] = '+';

				for (i = k + 1; i < a; i++)
				{
					ii++;
					v[ii] = st[i];
				}
			}
			else
			{
				for (i = k + 1; i < a; i++)
				{
					ii++;
					v[ii] = st[i];
				}

				ii++;
				v[ii] = '+';

				for (i = kk + 1; i < plus - 1; i++)
				{
					ii++;
					v[ii] = st[i];
				}
			}
			ii++;
			v[ii] = ')';

			ii++;

		}
	}


	i = 0;
	ksk = -1;

	while (true)
	{
		if (v[i] == '(')
		{
			for (k = 0; k < ii; k++)
			{
				if (v[k] == ')')
				{
					j = k;
					break;
				}
			}

			v[i] = '.';
			v[j] = '.';

			i++;
			j--;

			k1 = k2 = k3 = 0;
			for (k = i; k <= j; k++)
			{
				if (v[k] == '1') k1 = 1;
				if (v[k] == '2') k2 = 1;
				if (v[k] == '3') k3 = 1;

			}

			kol = 0;

			if (k1 == 0) kol++;
			if (k2 == 0) kol++;
			if (k3 == 0) kol++;

			if (kol > 1) i = 0;
			else
			{
				if (k1 == 0)
				{
					ksk++;
					vk[ksk] = '(';
					ksk++;
					vk[ksk] = 'x';
					ksk++;
					vk[ksk] = '1';
					ksk++;
					vk[ksk] = '+';

					for (k = i; k <= j; k++)
					{
						ksk++;
						vk[ksk] = v[k];
					}

					ksk++;
					vk[ksk] = ')';
					ksk++;
					vk[ksk] = '(';
					ksk++;
					vk[ksk] = '!';
					ksk++;
					vk[ksk] = 'x';
					ksk++;
					vk[ksk] = '1';
					ksk++;
					vk[ksk] = '+';


					for (k = i; k <= j; k++)
					{
						ksk++;
						vk[ksk]= v[k];
					}

					ksk++;
					vk[ksk] = ')';
					
				}

				if (k2 == 0)
				{
					ksk++;
					vk[ksk] = '(';

					for (k = i; k <= j; k++)
					{
						if (v[k] == '+')
						{
							kk = k;
							break;
						}
						ksk++;
						vk[ksk]= v[k];
					}

					ksk++;
					vk[ksk] = '+';
					ksk++;
					vk[ksk] = 'x';
					ksk++;
					vk[ksk] = '2';
					ksk++;
					vk[ksk] = '+';

					for (k = kk + 1; k <= j; k++)
					{
						ksk++;
						vk[ksk]= v[k];
					}

					ksk++;
					vk[ksk] = ')';
					ksk++;
					vk[ksk] = '(';

					for (k = i; k <= j; k++)
					{
						if (v[k] == '+')
						{
							kk = k;
							break;
						}
						ksk++;
						vk[ksk]= v[k];
					}

					ksk++;
					vk[ksk] = '+';
					ksk++;
					vk[ksk] = '!';
					ksk++;
					vk[ksk] = 'x';
					ksk++;
					vk[ksk] = '2';
					ksk++;
					vk[ksk] = '+';
					

					for (k = kk + 1; k <= j; k++)
					{
						ksk++;
						vk[ksk]= v[k];
					}

					ksk++;
					vk[ksk] = ')';
		

				}

				if (k3 == 0)
				{
					ksk++;
					vk[ksk] = '(';
					

					for (k = i; k <= j; k++)
					{
						ksk++;
						vk[ksk]= v[k];
					}

					ksk++;
					vk[ksk] = '+';
					ksk++;
					vk[ksk] = 'x';
					ksk++;
					vk[ksk] = '3';
					ksk++;
					vk[ksk] = ')';
					ksk++;
					vk[ksk] = '(';

					for (k = i; k <= j; k++)
					{
						ksk++;
						vk[ksk]= v[k];
					}

					ksk++;
					vk[ksk] = '+';
					ksk++;
					vk[ksk] = '!';
					ksk++;
					vk[ksk] = 'x';
					ksk++;
					vk[ksk] = '3';
					ksk++;
					vk[ksk] = ')';
				}





			}



			i = 0;
		}
		else i++;

		if (i > ii - 1) break;
	}

	j = 0;
	k = -1;

	for (i = 0; i <= ksk; i++)
	{
		if (vk[i] != ')')
		{
			k++;
			z[j].c1[k] = vk[i];
		}
		else
		{
			k++;
			z[j].c1[k] = vk[i];
			z[j].kp = k;
			k = -1;
			j++;
		}
	}

	k3 = -1;
	for (i = 0; i < j - 1; i++)
	{
		kol = 0;
		for (k = i + 1; k < j; k++)
		{
			if (strcmp(z[i].c1, z[k].c1) == 0) kol++;
		}

		if (kol == 0)
		{
			for (ksk = 0; ksk <= z[i].kp; ksk++)
				cout << z[i].c1[ksk];

			k3++;
			jkj[k3] = i;
		}
	}
	for (ksk = 0; ksk <= z[j-1].kp; ksk++)
		cout << z[j-1].c1[ksk];

	cout << endl << "INDEX: i=";

	for (ii = 0; ii <= 7; ii++)
		pps[ii] = 0;

	k3++;
	jkj[k3] = j - 1;
	kk = -1;
	for (i = 0; i <= k3; i++)
	{
		ii = -1;
		for (ksk = 0; ksk <= z[jkj[i]].kp; ksk++)
		{
			if ((z[jkj[i]].c1[ksk] == 'x') && (z[jkj[i]].c1[ksk - 1] == '!')) { ii++; index[ii] = '1'; }
			if ((z[jkj[i]].c1[ksk] == 'x') && (z[jkj[i]].c1[ksk - 1] != '!')) { ii++; index[ii] = '0'; }
		}

		
		if ((index[0] == '0') && (index[1] == '0') && (index[2] == '0')) { sum = sum - 128; kk++; pps[0] = 1; }
		if ((index[0] == '0') && (index[1] == '0') && (index[2] == '1')) { sum = sum - 64; kk++; pps[1] = 1;}
		if ((index[0] == '0') && (index[1] == '1') && (index[2] == '0')) { sum = sum - 32; kk++; pps[2] = 1;}
		if ((index[0] == '0') && (index[1] == '1') && (index[2] == '1')) { sum = sum - 16; kk++; pps[3] = 1;}
		if ((index[0] == '1') && (index[1] == '0') && (index[2] == '0')) { sum = sum - 8; kk++; pps[4] = 1;}
		if ((index[0] == '1') && (index[1] == '0') && (index[2] == '1')) { sum = sum - 4; kk++; pps[5] = 1;}
		if ((index[0] == '1') && (index[1] == '1') && (index[2] == '0')) { sum = sum - 2; kk++; pps[6] = 1;}
		if ((index[0] == '1') && (index[1] == '1') && (index[2] == '1')) { sum = sum - 1; kk++; pps[7] = 1;}
		
		

	}
	cout << sum << endl;

	/*for (i = 0; i < kk; i++)
	{
		for (j = i + 1; j <= kk; j++)
			if (pps[i]>=pps[j]) swap(pps[i], pps[j]);
	}*/

	cout << "/\\(";
	for (i = 0; i <= 7; i++)
	{
		if (pps[i] == 1)cout << i<<" ";
			
	}

	cout << ")";
	cout << endl;

	cout << "\\/(";
	for (i = 0; i <= 7; i++)
	{
		if (pps[i] == 0) cout << i << " ";
	}

	cout << ")";

	cout << endl;

}

int main()
{
	char s[50], st[70];
	int a[6], k1, k2, i, k;

	set(s);
	minusotric(s);

	for (i = 0; i < strlen(s); i++)
	{
		if ((s[i] == '(') || (s[i] == ')')) s[i] = '.';
	}

	i = -1;
	k = 0;
	while (true)
	{
		if (s[k] != '.')
		{
			i++;
			st[i] = s[k];
			k++;
		}
		else k++;

		if (k > strlen(s) - 1) break;
	}

	for (k = 0; k < 3; k++)
	{
		a[k] = 0;
	}

	for (k = 0; k <= i; k++)
	{
		if (st[k] == '1') a[0] = 1;
		if (st[k] == '2') a[1] = 1;
		if (st[k] == '3') a[2] = 1;

		if (st[k] == '+')
		{
			if (a[0] == 0)  k1 = 1;

			if (a[1] == 0)  k1 = 2;

			if (a[2] == 0)  k1 = 3;

			a[0] = 0; a[1] = 0; a[2] = 0;
		}

		if (k == i)
		{
			if (a[0] == 0)  k2 = 1;

			if (a[1] == 0)  k2 = 2;

			if (a[2] == 0)  k2 = 3;
		}
	}

	showSDNF(k1, k2, st, i + 1);
	showSKNF(st, i + 1);

	cout << endl;
	return 0;
}