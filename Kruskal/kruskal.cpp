#include <ioStream>
#include <vector>
#include <algorithm>

using namespace std;

struct arista
{
	int inicio, peso, destino;
};

bool menor_a_mayor(arista a, arista b)
{
	return a.peso < b.peso;
}

int nodo_raiz(vector<int> &raiz, int nodo)
{
	while(nodo != raiz[nodo])
	{
		nodo = raiz[nodo];
	}
	return nodo;
}

void kruskal(vector<arista> g, int nro_nodos)
{
	sort(g.begin(), g.end(), menor_a_mayor);
	vector<int> raiz(nro_nodos);
	for(int i = 0; i < nro_nodos; i++)
	{
		raiz[i] = i;
	}
	for(arista &a :g)
	{
		int raiz_inicio = nodo_raiz(raiz, a.inicio);
		int raiz_final = nodo_raiz(raiz, a.destino);
		
		if(raiz_inicio != raiz_final)
		{
			cout<< "el inicio es en el nodo " << a.inicio << " con destino en " << a.destino << " y tiene un peso de " << a.peso << endl;
			raiz[raiz_inicio] = raiz_final;
		}
	}
}

int main()
{
	int nro_nodos = 5;
	vector <vector<arista>> grafo(nro_nodos);
	//creando el grafo;
	cout<< "tenemos un grafo con "<<nro_nodos<<" nodos "<<endl;
	for(int i = 0; i < nro_nodos; i++)
	{
		cout<<"-----------------------------------"<<endl;
		cout<< "el nodo " << i << " con destino(s) a "<< endl;
		int nro_destinos = 1 + rand() % 3;
		for(int o = 0; o < nro_destinos; o++)
		{
			int destino = rand() % nro_nodos;
			if(destino != i)
			{
				int peso = 4 + rand() % (10 - 4 + 1);
				arista ida = {i, peso, destino};
				cout << "  -> Al nodo " << ida.destino << " con peso " << ida.peso << endl;
				grafo[i].push_back(ida);
				arista retorno = {destino, peso, i};
				grafo[destino].push_back(retorno);
			}
		}
		cout<<"-----------------------------------"<<endl;
	}
	
	vector<arista> grafo_plano;
	for(vector<vector<arista>>::iterator i = grafo.begin(); i != grafo.end(); i++)
	{
		for(vector<arista>::iterator o = i->begin(); o != i->end(); o++)
		{
			grafo_plano.push_back(*o);
		}
	}
	
	kruskal(grafo_plano, nro_nodos);
	return 0;
}
