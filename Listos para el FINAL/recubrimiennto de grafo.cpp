#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n = 7;
	vector<pair<int,int>>grafo = {{1,2},{1,4},{2,3},{2,4},{2,5},{3,5},{4,5},{4,6},{5,7},{6,7}};
	vector<int> solucion;
	while(!grafo.empty())
	{
		vector<int>grado(n+1);
		for(auto i : grafo)
		{
			grado[i.first]++;
			grado[i.second]++;
		}
		
		int mejor = 1;
		for(int i = 2; i <= n; i++)
		{
			if(grado[i] > grado[mejor])
			{
				mejor = i;
			}
		}
		solucion.push_back(mejor);
		
		int idx = 0;
		for(auto i : grafo)
		{
			if (i.first != mejor && i.second != mejor)
			{
				grafo[idx++] = i;
			}
		}
		grafo.resize(idx);
	}
	
	cout<<"nodos seleccionados:\n";
	for(auto i : solucion)
	{
		cout<<i<<" ";
	}
	return 0;
}
