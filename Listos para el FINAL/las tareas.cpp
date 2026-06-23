#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct tarea{
	int id, beneficio, plazo_max;
};

bool descendente(tarea a, tarea b)
{
	return a.beneficio > b.beneficio;
}

void planificacion_de_tareas(vector<tarea> &t)
{
	sort(t.begin(),t.end(),descendente);
	int plazo_maximo = 0;
	for(auto i : t)
	{
		if(i.plazo_max > plazo_maximo)
		{
			plazo_maximo = i.plazo_max;
		}
	}
	vector<int>slots(plazo_maximo + 1, -1);
	for(auto i: t)
	{
		for(int j = plazo_maximo; j > 0; j--)
		{
			if(slots[j] == -1)
			{
				slots[j] = i.id;
				break;
			}
		}
	}
	for(int i = 1; i <= plazo_maximo; i++)
	{
		if(slots[i] != -1)
		{
			cout<<"en el instante "<< i << " se ejecuta la tarea "<< slots[i] <<endl;
		}
	}
}

int main()
{
	vector<tarea>t={{1,3,7},{2,4,8},{3,5,9},{4,6,10}};
	planificacion_de_tareas(t);
	return 0;
}
