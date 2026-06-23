#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tarea
{
	int id, beneficio, plazo_max;
};

bool descendente(tarea a , tarea b)
{
	return a.beneficio > b.beneficio;
}

void planificacion_de_tareas(vector<tarea> &lista_tareas)
{
	sort(lista_tareas.begin(), lista_tareas.end(), descendente);
	int plazo_maximo = 0;
	for(const auto &i : lista_tareas)
	{
		if(i.plazo_max > plazo_maximo)
		{
			plazo_maximo = i.plazo_max;
		}
	}
	vector<int> slots(plazo_maximo + 1, -1);
	for(const auto &t : lista_tareas)
	{
		for(int j = t.plazo_max; j > 0 ; j--)
		{
			if(slots[j] == -1)
			{
				slots[j] = t.id;
				break;
			}
		}
	}
	
	for(int k = 1; k <= plazo_maximo; k++)
	{
		if(slots[k] != -1)
		{
			cout<< "En el instante " << k << " se ejecuta la tarea "<< slots[k] << endl;
		}
	}
}

int main()
{
	vector<tarea> t = {{1,50,2},{2,10,1},{3,15,2},{4,30,1}};
	planificacion_de_tareas(t);
	return 0;
}
