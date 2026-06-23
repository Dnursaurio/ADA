#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct contenedor
{
	int peso, id;
};

bool menor_a_mayor (contenedor a, contenedor b)
{
	return a.peso < b.peso;
}

void mochila(vector<contenedor> &b, int capacidad_max)
{
	sort(b.begin(), b.end(), menor_a_mayor);
	
	int peso_total = 0;
	vector<contenedor> seleccionados;
	for(contenedor c : b)
	{
		if(peso_total + c.peso <= capacidad_max)
		{
			seleccionados.push_back(c);
			peso_total += c.peso;
		}
	}
	cout<<"items seleccionados "<<endl;
	for(contenedor d : seleccionados)
	{
		cout<< "peso de cada caja "<< d.peso << " en el contenedor "<< d.id << endl;
	}
	cout<< "peso total " << peso_total << endl;
	cout<< "peso restante "<< capacidad_max - peso_total << endl;
	cout<< "cantidad selecionada "<< seleccionados.size() << endl;
}

int main()
{
	cout<<"item A maximizar el ";
	vector<contenedor> b = {{20,1},{50,2},{90,3},{120,4}};
	int capacidad_tn = 120;
	mochila(b,capacidad_tn);
	return 0;
}
