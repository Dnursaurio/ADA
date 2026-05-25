#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Programa
{
	int id, espacio;
};

bool menor_a_mayor(Programa a, Programa b)
{
	return a.espacio < b.espacio;
}

void Maximizar(vector<Programa> p, int capacidad_max)
{
	sort(p.begin(), p.end(), menor_a_mayor);
	
	int cap_total = 0;
	vector<Programa>seleccionados;
	
	for(Programa a: p)
	{
		if(cap_total + a.espacio <= capacidad_max)
		{
			seleccionados.push_back(a);
			cap_total += a.espacio;
		}
	}
	
	cout<<"programas seleccionados:" << endl;
	for(Programa b:seleccionados)
	{
		cout<<"el programa " << b.id << " ocupa " << b.espacio << "KB"<<endl;
	}
	cout << "la capacidad total ocupada es: " << cap_total << endl;
	cout << "la capacidad restantee es: " << capacidad_max - cap_total << endl;
	cout << "el total seleccionado es: " << seleccionados.size() << endl;
}

int main()
{
	vector<Programa> p = {{12,41},{9,18},{23,26},{19,90}};
	int capacidad = 30;
	Maximizar(p,capacidad);
	return 0;
}
