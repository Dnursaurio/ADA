#include <ioStream>
#include <vector>
#include <queue>

using namespace std;

struct arista
{
	int peso, destino;
};

struct menor_a_mayor
{
	bool operator()(const arista &a, const arista &b)
	{
		return a.peso > b.peso;
	}
};

void prim(vector<vector<arista>>g, int nro_nodos)
{
	priority_queue<arista, vector<arista>, menor_a_mayor> pqmin;
	vector<bool> ya_recorrido(nro_nodos, 0);
	ya_recorrido[0] = 1;
	for (const auto &p : g[0])
	{
		pqmin.push(p);
	}
	
	while(!pqmin.empty())
	{
		arista barata = pqmin.top();
		pqmin.pop();
		
		if(ya_recorrido[barata.destino] == 1)
		{
			continue;
		}
		else
		{
			ya_recorrido[barata.destino] = 1;
			cout << "¡Conquistado el nodo " << barata.destino << " con costo " << barata.peso << "!" << endl;
			for(const auto &a: g[barata.destino])
			{
				pqmin.push(a);
			}
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
				arista ida = {peso, destino};
				cout << "  -> Al nodo " << ida.destino << " con peso " << ida.peso << endl;
				grafo[i].push_back(ida);
				arista retorno = {peso, i};
				grafo[destino].push_back(retorno);
			}
		}
		cout<<"-----------------------------------"<<endl;
	}
	prim(grafo,nro_nodos);
	return 0;
}
