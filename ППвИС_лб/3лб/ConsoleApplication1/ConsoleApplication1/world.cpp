#include "world.h"

void living::build(int i, int j, string name)
{
	living *ptr;

	if (name == "pl")
	{
		plankton *obj;
		obj = new plankton(i, j);
		
		ptr = obj;
		world[i][j] = *ptr;
	}

	if (name == "ak")
	{
		akula *obj;
		obj = new akula(i, j);

		ptr = obj;
		world[i][j] = *ptr;
	}

	if (name == "ko")
	{
		kosatka *obj;
		obj = new kosatka(i, j);

		ptr = obj;
		world[i][j] = *ptr;
	}

	delete ptr;
}

void living::draw()
{
	for (int j = 0; j<M; j++)
		cout << " ______";

	cout << endl;

	for (int i = 0; i < N; i++)
	{
		cout << "|";

		for (int j = 0; j < M; j++)
		{
			cout << "  ";

			cout << world[i][j].name; 
			
			cout << "  |";
		}

		cout << endl << "|";

		for (int j = 0; j < M; j++)
			cout << "______|";

		cout << endl;
	}
}

void living::move_pl()
{
	srand(time(0));

	int x; 

	for (int i=0;i<N;i++)
		for (int j = 0; j < M; j++)
		{
			if (world[i][j].name == "pl")
			{
				while (true)
				{
					x = rand() % 8;
					
					if ((x == 0) && (j - 1 >= 0))
					{
						if (world[i][j - 1].name == "  ")
						{
							world[i][j - 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 1) && (j + 1 < M))
					{
						if (world[i][j + 1].name == "  ")
						{
							world[i][j + 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 2) && (i - 1 >= 0))
					{
						if (world[i-1][j].name == "  ")
						{
							world[i-1][j] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 3) && (i + 1 < N))
					{
						if (world[i+1][j].name == "  ")
						{
							world[i+1][j] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 4) && (i - 1 >=0 ) && (j - 1 >= 0))
					{
						if (world[i - 1][j - 1].name == "  ")
						{
							world[i - 1][j - 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 5) && (i - 1 >= 0) && (j + 1 < M))
					{
						if (world[i - 1][j + 1].name == "  ")
						{
							world[i - 1][j + 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 6) && (i + 1 < N) && (j - 1 >=0))
					{
						if (world[i + 1][j - 1].name == "  ")
						{
							world[i + 1][j - 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 7) && (i + 1 < N) && (j + 1 < M))
					{
						if (world[i + 1][j + 1].name == "  ")
						{
							world[i + 1][j + 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}
				}
			}
		}
}

void living::die_pl()
{
	for (int i=0;i<N;i++)
		for (int j = 0; j < M; j++)
		{
			if (world[i][j].name == "pl")
			{
				if (world[i][j].age == 3) world[i][j].name = "  ";
				else world[i][j].age++;
			}
		}
}

void living::reproduction_pl()
{
	for (int i = 0; i<N; i++)
		for (int j = 0; j < M; j++)
		{
			if (world[i][j].name == "pl")
			{
				if (world[i][j].age == 2)
				{
					if ((j - 1 >= 0) && (world[i][j - 1].name == "  "))
					{
						plankton *obj;
						obj = new plankton(i, j - 1);

						world[i][j - 1] = *obj;
						continue;
					}

					if ((j + 1 < M)&& (world[i][j + 1].name == "  "))
					{
						plankton *obj;
						obj = new plankton(i, j + 1);

						world[i][j + 1] = *obj;
						continue;
					}

					if ((i - 1 >= 0)&& (world[i-1][j].name == "  "))
					{
						plankton *obj;
						obj = new plankton(i-1, j);
						
						world[i-1][j] = *obj;
						continue;
					}

					if ((i + 1 < N)&&(world[i+1][j].name == "  "))
					{
						plankton *obj;
						obj = new plankton(i + 1, j);

						world[i + 1][j] = *obj;
						continue;
					}

					if ((i - 1 >= 0) && (j - 1 >= 0)&& (world[i - 1][j - 1].name == "  "))
					{
						plankton *obj;
						obj = new plankton(i - 1, j - 1);
						
						world[i - 1][j - 1] = *obj;
						continue;
					}

					if ((i - 1 >= 0) && (j + 1 < M)&& (world[i - 1][j + 1].name == "  "))
					{
						plankton *obj;
						obj = new plankton(i - 1, j + 1);

						world[i - 1][j + 1] = *obj;
						continue;
					}

					if ((i + 1 < N) && (j - 1 >= 0)&& (world[i + 1][j - 1].name == "  "))
					{
						plankton *obj;
						obj = new plankton(i + 1, j - 1);
						
						world[i + 1][j - 1] = *obj;
						continue;
					}

					if ((i + 1 < N) && (j + 1 < M)&& (world[i + 1][j + 1].name == "  "))
					{
						plankton *obj;
						obj = new plankton(i + 1, j + 1);

						world[i + 1][j + 1] = *obj;
						continue;
					}

					if ((j - 1 >= 0) && (world[i][j - 1].name == "pl"))
					{
						world[i][j - 1].age=0;
						continue;
					}

					if ((j + 1 < M) && (world[i][j + 1].name == "pl"))
					{
						world[i][j + 1].age = 0;
						continue;
					}

					if ((i - 1 >= 0) && (world[i - 1][j].name == "pl"))
					{
						world[i - 1][j].age = 0;
						continue;
					}

					if ((i + 1 < N) && (world[i + 1][j].name == "pl"))
					{
						world[i + 1][j].age = 0;
						continue;
					}

					if ((i - 1 >= 0) && (j - 1 >= 0) && (world[i - 1][j - 1].name == "pl"))
					{
						world[i - 1][j - 1].age = 0;
						continue;
					}

					if ((i - 1 >= 0) && (j + 1 < M) && (world[i - 1][j + 1].name == "pl"))
					{
						world[i - 1][j + 1].age = 0;
						continue;
					}

					if ((i + 1 < N) && (j - 1 >= 0) && (world[i + 1][j - 1].name == "pl"))
					{
						world[i + 1][j - 1].age = 0;
						continue;
					}

					if ((i + 1 < N) && (j + 1 < M) && (world[i + 1][j + 1].name == "pl"))
					{
						world[i + 1][j + 1].age=0;
						continue;
					}
				}
			}
		}
}

void living::move_ak()
{
	srand(time(0));

	int x;

	for (int i = 0; i<N; i++)
		for (int j = 0; j < M; j++)
		{
			if (world[i][j].name == "ak")
			{
				while (true)
				{
					x = rand() % 8;

					if ((x == 0) && (j - 1 >= 0))
					{
						if (world[i][j - 1].name == "  ")
						{
							world[i][j - 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 1) && (j + 1 < M))
					{
						if (world[i][j + 1].name == "  ")
						{
							world[i][j + 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 2) && (i - 1 >= 0))
					{
						if (world[i - 1][j].name == "  ")
						{
							world[i - 1][j] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 3) && (i + 1 < N))
					{
						if (world[i + 1][j].name == "  ")
						{
							world[i + 1][j] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 4) && (i - 1 >= 0) && (j - 1 >= 0))
					{
						if (world[i - 1][j - 1].name == "  ")
						{
							world[i - 1][j - 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 5) && (i - 1 >= 0) && (j + 1 < M))
					{
						if (world[i - 1][j + 1].name == "  ")
						{
							world[i - 1][j + 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 6) && (i + 1 < N) && (j - 1 >= 0))
					{
						if (world[i + 1][j - 1].name == "  ")
						{
							world[i + 1][j - 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 7) && (i + 1 < N) && (j + 1 < M))
					{
						if (world[i + 1][j + 1].name == "  ")
						{
							world[i + 1][j + 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}
				}
			}
		}
}

void living::eat_ak()
{
	for (int i=0;i<N;i++)
		for (int j = 0; j < M; j++)
		{
			if (world[i][j].name == "ak")
			{
				if (world[i][j].age == -3) world[i][j].name = "  ";
				
				else
				{
					if ((j - 1 >= 0) && (world[i][j - 1].name == "pl"))
					{
						world[i][j - 1].name = "  ";
						world[i][j].age = 0;
						continue;
					}

					if ((j + 1 < M) && (world[i][j + 1].name == "pl"))
					{
						world[i][j + 1].name = "  ";
						world[i][j].age = 0;
						continue;
					}

					if ((i - 1 >= 0) && (world[i - 1][j].name == "pl"))
					{
						world[i - 1][j].name = "  ";
						world[i][j].age = 0;
						continue;
					}

					if ((i + 1 < N) && (world[i + 1][j].name == "pl"))
					{
						world[i + 1][j].name = "  ";
						world[i][j].age = 0;
						continue;
					}

					if ((i - 1 >= 0) && (j - 1 >= 0) && (world[i - 1][j - 1].name == "pl"))
					{
						world[i - 1][j - 1].name = "  ";
						world[i][j].age = 0;
						continue;
					}

					if ((i - 1 >= 0) && (j + 1 < M) && (world[i - 1][j + 1].name == "pl"))
					{
						world[i - 1][j + 1].name = "  ";
						world[i][j].age = 0;
						continue;
					}

					if ((i + 1 < N) && (j - 1 >= 0) && (world[i + 1][j - 1].name == "pl"))
					{
						world[i + 1][j - 1].name = "  ";
						world[i][j].age = 0;
						continue;
					}

					if ((i + 1 < N) && (j + 1 < M) && (world[i + 1][j + 1].name == "pl"))
					{
						world[i + 1][j + 1].name = "  ";
						world[i][j].age = 0;
						continue;
					}

					world[i][j].age--;
				}
			}
		}
}

void living::move_ko()
{
	srand(time(0));

	int x;

	for (int i = 0; i<N; i++)
		for (int j = 0; j < M; j++)
		{
			if (world[i][j].name == "ko")
			{
				while (true)
				{
					x = rand() % 8;

					if ((x == 0) && (j - 1 >= 0))
					{
						if (world[i][j - 1].name == "  ")
						{
							world[i][j - 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 1) && (j + 1 < M))
					{
						if (world[i][j + 1].name == "  ")
						{
							world[i][j + 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 2) && (i - 1 >= 0))
					{
						if (world[i - 1][j].name == "  ")
						{
							world[i - 1][j] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 3) && (i + 1 < N))
					{
						if (world[i + 1][j].name == "  ")
						{
							world[i + 1][j] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 4) && (i - 1 >= 0) && (j - 1 >= 0))
					{
						if (world[i - 1][j - 1].name == "  ")
						{
							world[i - 1][j - 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 5) && (i - 1 >= 0) && (j + 1 < M))
					{
						if (world[i - 1][j + 1].name == "  ")
						{
							world[i - 1][j + 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 6) && (i + 1 < N) && (j - 1 >= 0))
					{
						if (world[i + 1][j - 1].name == "  ")
						{
							world[i + 1][j - 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}

					if ((x == 7) && (i + 1 < N) && (j + 1 < M))
					{
						if (world[i + 1][j + 1].name == "  ")
						{
							world[i + 1][j + 1] = world[i][j];
							world[i][j].name = "  ";
							break;
						}
						else continue;
					}
				}
			}
		}
}

void living::eat_ko()
{
	for (int i = 0; i<N; i++)
		for (int j = 0; j < M; j++)
		{
			if (world[i][j].name == "ko")
			{
				if (world[i][j].age == -3) world[i][j].name = "  ";

				else
				{
					if ((j - 1 >= 0) && (world[i][j - 1].name == "ak"))
					{
						world[i][j - 1].name = "  ";
						world[i][j].age = 0;
						continue;
					}

					if ((j + 1 < M) && (world[i][j + 1].name == "ak"))
					{
						world[i][j + 1].name = "  ";
						world[i][j].age = 0;
						continue;
					}

					if ((i - 1 >= 0) && (world[i - 1][j].name == "ak"))
					{
						world[i - 1][j].name = "  ";
						world[i][j].age = 0;
						continue;
					}

					if ((i + 1 < N) && (world[i + 1][j].name == "ak"))
					{
						world[i + 1][j].name = "  ";
						world[i][j].age = 0;
						continue;
					}

					if ((i - 1 >= 0) && (j - 1 >= 0) && (world[i - 1][j - 1].name == "ak"))
					{
						world[i - 1][j - 1].name = "  ";
						world[i][j].age = 0;
						continue;
					}

					if ((i - 1 >= 0) && (j + 1 < M) && (world[i - 1][j + 1].name == "ak"))
					{
						world[i - 1][j + 1].name = "  ";
						world[i][j].age = 0;
						continue;
					}

					if ((i + 1 < N) && (j - 1 >= 0) && (world[i + 1][j - 1].name == "ak"))
					{
						world[i + 1][j - 1].name = "  ";
						world[i][j].age = 0;
						continue;
					}

					if ((i + 1 < N) && (j + 1 < M) && (world[i + 1][j + 1].name == "ak"))
					{
						world[i + 1][j + 1].name = "  ";
						world[i][j].age = 0;
						continue;
					}

					world[i][j].age--;
				}
			}
		}

}

void living::next()
{
	move_pl();
	reproduction_pl();
	die_pl();

	move_ak();
	eat_ak();

	move_ko();
	eat_ko();
}