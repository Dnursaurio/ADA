#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct contenedor
{
	int peso, id;
};

bool ascendente(contenedor a, contenedor b)
{
	return a.peso < b.peso;
}

void mochila(vector<contenedor> &m, int cap_max)
{
	sort(m.begin(), m.end(), ascendente);
	int peso_total = 0;
	vector<contenedor>seleccionados;
	for(contenedor i : m)
	{
		if(peso_total + i.peso < cap_max)
		{
			seleccionados.push_back(i);
			peso_total += i.peso;
		}
	}
	cout<<"item selecionados\n";
	for(auto i: seleccionados)
	{
		cout<<"el item "<< i.id << " que pesa " << i.peso << endl;
	}
	cout<<"peso total "<< peso_total<<endl;
	cout<<"peso restante " << cap_max - peso_total<< endl;
	cout<<"elementos seleccionados "<< seleccionados.size();
}

int main()
{
	vector<contenedor> b = {{20,1},{50,2},{90,3},{120,4}};
	int capacidad_tn = 120;
	mochila(b,capacidad_tn);
	return 0;
}
