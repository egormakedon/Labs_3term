#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Graf
{
private:
	friend class Graf <T>;
	vector<vector <T> > graf;

public:
	Graf()
	{}

	~Graf()
	{}

	void empty();
	void clear();
	int addvertex(T u);
	int addedge(T u, T v);
	int findvertex(T u);
	int findedge(T u, T v);
	void kolvertex();
	void koledge();
	int stepenvertex(T u);
	int erasevertex(T u);
	int eraseedge(T u, T v);

public:
    class Node_Iterator
    {
    	private:
    		Graf<T> *gr;
    		int index;

    	public:
    		Node_Iterator(Graf<T> &graf)
    		{
    			gr = &graf;
    			index = 0;
    		}

    		bool next()
    		{
    			if (gr->graf.size() <= index+1) return false;
    			index++;

    			return true;
    		}

    		void get()
    		{
    			int kol=0;

    			for (int i=1; i<gr->graf[index].size();i++)
    			{
    				cout<<gr->graf[index][i]+1<<" ";
    				kol++;
    			}

    			if (kol==0) cout<<"Смежных вершин нет";

    			cout<<endl;
    		}

    		bool prev()
    		{
    			if (index==0) return false;
    			index--;

    			return true;
    		}
    };
};

int main()
{
	setlocale(0,"");

	cout<<"Лабораторная работа №4 (Усложненная)"<<endl<<"Ориентированный граф (Список смежности)"<<endl<<endl;
	cout<<"1. Проверка на пустой контейнер"<<endl;
	cout<<"2. Очистка контейнера"<<endl;
	cout<<"3. Добавление вершины"<<endl;
	cout<<"4. Добавление дуги"<<endl;
	cout<<"5. Проверка присутствия вершины в графе"<<endl;
	cout<<"6. Проверка присутствия дуги между вершинами"<<endl;
	cout<<"7. Получение количества вершин"<<endl;
	cout<<"8. Получение количества дуг"<<endl;
	cout<<"9. Степень вершины"<<endl;
	cout<<"10. Удаление вершины"<<endl;
	cout<<"11. Удаление дуги"<<endl;
	cout<<"12. Двунаправленный итератор по смежным вершинам"<<endl;
	cout<<"0. Завершение программы"<<endl<<endl;

	Graf<int> graf;

	int kl;
	while (true)
	{
		cin>>kl;

		if (kl==0) return 0;
		if (kl==1) graf.empty();
		if (kl==2) graf.clear();
		if (kl==3) {int u; cin>>u; graf.addvertex(u-1);}
		if (kl==4) {int u,v; cin>>u>>v; graf.addedge(u-1,v-1);}
		if (kl==5) {int u; cin>>u; graf.findvertex(u-1);}
		if (kl==6) {int u,v; cin>>u>>v; graf.findedge(u-1,v-1);}
		if (kl==7) graf.kolvertex();
		if (kl==8) graf.koledge();
		if (kl==9) {int u; cin>>u; graf.stepenvertex(u-1);}
		if (kl==10) {int u; cin>>u; graf.erasevertex(u-1);}
		if (kl==11) {int u,v; cin>>u>>v; graf.eraseedge(u-1,v-1);}
		if (kl==12)
		{
			Graf<int>::Node_Iterator it(graf);

			cout<<endl;
			cout<<"1. Переход к следующей вершине"<<endl;
			cout<<"2. Переход к предыдущей вершине"<<endl;
			cout<<"3. Вывод смежных вершин"<<endl;
			cout<<"4. Выход из итератора"<<endl;
			cout<<endl;

			while(true)
			{
				cin>>kl;

				if (kl==1) {if (it.next()==false) cout<<"Итератор находится на последней вершине"<<endl; else cout<<"Итератор перешел на следующую вершину"<<endl;}
				if (kl==2) {if (it.prev()==false) cout<<"Итератор находится на первой вершине"<<endl; else cout<<"Итератор перешел на предыдущую вершину"<<endl;}
				if (kl==3) it.get();
				if (kl==4) {cout<<"Выход из итератора"<<endl<<endl;break;}
			}
		}
	}

	return 0;
}

template <typename T>
void Graf<T>::empty()
{
	if (graf.empty()==true) cout<<"Контейнер пуст"<<endl;
	else cout<<"Контейнер не пустой"<<endl;
}

template <typename T>
void Graf<T>::clear()
{
	graf.clear();
	cout<<"Контейнер очищен"<<endl;
}

template <typename T>
int Graf<T>::addvertex(T u)
{
	vector<T> temp1;
	temp1.push_back(u);

	for (int i=0;i<graf.size();i++)
	{
		vector<T> temp2;
		temp2=graf[i];

		for (int j=1;j<graf[i].size();j++)
			temp2.pop_back();

		if (temp1==temp2) {cout<<"Вершина уже есть в графе"<<endl;return 0;}
	}

	graf.push_back(temp1);

	cout<<"Вершина добавлена"<<endl;

	return 0;
}

template <typename T>
int Graf<T>::addedge(T u, T v)
{
	int kol=0;
	vector<T> temp1;
	vector<T> temp2;
	temp1.push_back(u);
	temp2.push_back(v);

	for (int i=0;i<graf.size();i++)
	{
		vector<T> temp3;
		temp3=graf[i];

		for (int j=1;j<graf[i].size();j++)
			temp3.pop_back();

		if (temp1==temp3) kol++;
		if (temp2==temp3) kol++;
	}

	if (kol!=2) {cout<<"Неверные параметры"<<endl;return 0;}
	else
	{
		for (int i=0;i<graf.size();i++)
		{
			vector<T> temp3;
			temp3=graf[i];

			for (int j=1;j<graf[i].size();j++)
				temp3.pop_back();

			if (temp1==temp3)
			{
				for (int j=1; j<graf[i].size();j++)
					if (graf[i][j]==v) {cout<<"Дуга уже есть в графе"<<endl;return 0;}
			}
		}

	graf[u].push_back(v);
	cout<<"Дуга добавлена"<<endl;

	return 0;
	}
}

template <typename T>
int Graf<T>::findvertex(T u)
{
	vector<T> temp1;
	temp1.push_back(u);

	for (int i=0;i<graf.size();i++)
	{
		vector<T> temp2;
		temp2=graf[i];

		for (int j=1;j<graf[i].size();j++)
			temp2.pop_back();

		if (temp1==temp2) {cout<<"Вершина есть в графе"<<endl;return 0;}
	}

	cout<<"Вершины нет в графе"<<endl;

	return 0;
}

template <typename T>
int Graf<T>::findedge(T u, T v)
{
	int kol=0;
	vector<T> temp1;
	vector<T> temp2;
	temp1.push_back(u);
	temp2.push_back(v);

	for (int i=0;i<graf.size();i++)
	{
		vector<T> temp3;
		temp3=graf[i];

		for (int j=1;j<graf[i].size();j++)
			temp3.pop_back();

		if (temp1==temp3) kol++;
		if (temp2==temp3) kol++;
	}

	if (kol!=2) {cout<<"Неверные параметры"<<endl;return 0;}
	else
	{
		for (int i=0;i<graf.size();i++)
		{
			vector<T> temp3;
			temp3=graf[i];

			for (int j=1;j<graf[i].size();j++)
				temp3.pop_back();

			if (temp1==temp3)
			{
				for (int j=1; j<graf[i].size();j++)
					if (graf[i][j]==v) {cout<<"Дуга присутствует между вершинами"<<endl;return 0;}
			}
		}

	cout<<"Дуги нету между вершинами"<<endl;

	return 0;
	}
}

template <typename T>
void Graf<T>::kolvertex()
{
	cout<<"Количество вершин: "<<graf.size()<<endl;
}

template <typename T>
void Graf<T>::koledge()
{
	int kol=0;

	for (int i=0;i<graf.size();i++)
		kol=kol+graf[i].size();

	cout<<"Количество дуг: "<<kol-graf.size()<<endl;
}

template <typename T>
int Graf<T>::stepenvertex(T u)
{
	vector<T> temp1;
	temp1.push_back(u);

	for (int i=0;i<graf.size();i++)
	{
		vector<T> temp2;
		temp2=graf[i];

		for (int j=1;j<graf[i].size();j++)
			temp2.pop_back();

		if (temp1==temp2) {cout<<"Степень вершины: "<<graf[u].size()-1<<endl;return 0;}
	}

	cout<<"Такой вершины нет в графе"<<endl;

	return 0;
}

template <typename T>
int Graf<T>::erasevertex(T u)
{
	int kol=0;
	vector<T> temp1;
	temp1.push_back(u);

	for (int i=0;i<graf.size();i++)
	{
		vector<T> temp2;
		temp2=graf[i];

		for (int j=1;j<graf[i].size();j++)
			temp2.pop_back();

		if (temp1==temp2) {kol++; break;}
	}

	if (kol==0) {cout<<"Вершины нет в графе"<<endl;return 0;}
	else
	{
		for (int i=0;i<graf.size();i++)
		{
			vector<T> temp2;
			temp2=graf[i];

			for (int j=1;j<graf[i].size();j++)
				temp2.pop_back();

			for (int j=0;j<graf[i].size();j++)
				if (graf[i][j]==u) {graf[i].erase(graf[i].begin()+j);j=0;continue;}

			if (temp1==temp2) {graf.erase(graf.begin()+i);i=0;continue;}
		}

		cout<<"Вершина удалена"<<endl;

		return 0;
	}
}

template <typename T>
int Graf<T>::eraseedge(T u, T v)
{
	int kol=0;
	vector<T> temp1;
	vector<T> temp2;
	temp1.push_back(u);
	temp2.push_back(v);

	for (int i=0;i<graf.size();i++)
	{
		vector<T> temp3;
		temp3=graf[i];

		for (int j=1;j<graf[i].size();j++)
			temp3.pop_back();

		if (temp1==temp3) kol++;
		if (temp2==temp3) kol++;
	}

	if (kol!=2) {cout<<"Неверные параметры"<<endl;return 0;}
	else
	{
		for (int i=0;i<graf.size();i++)
		{
			vector<T> temp3;
			temp3=graf[i];

			for (int j=1;j<graf[i].size();j++)
				temp3.pop_back();

			if (temp1==temp3)
			{
				for (int j=0; j<graf[i].size();j++)
					if (graf[i][j]==v) {graf[i].erase(graf[i].begin()+j);cout<<"Дуга удалена"<<endl;return 0;}
			}
		}


	cout<<"Такой дуги нет в графе"<<endl;

	return 0;
	}
}
