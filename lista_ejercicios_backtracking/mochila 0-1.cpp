#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int mejor_beneficio_global = 0;

void mochila(int n, int M, vector<int>&pesos, vector<int>&beneficios, int idx_objeto, int beneficio_acum, int peso_acum)
{
	if(idx_objeto == n)
	{
		if(beneficio_acum > mejor_beneficio_global)
		{
			mejor_beneficio_global = beneficio_acum;
		}
		return;
	}
	if(peso_acum + pesos[idx_objeto] <= M)
	{
		mochila(n,M,pesos,beneficios,idx_objeto + 1, beneficio_acum + beneficios[idx_objeto], peso_acum + pesos[idx_objeto]);
	}
	mochila(n,M,pesos,beneficios,idx_objeto + 1, beneficio_acum, peso_acum);
}

int main()
{
	int n = 5;
	vector<int> pesos = {1, 11, 21, 23, 33};
	vector<int> beneficios = {11, 21, 31, 33, 43};
	int M = 61;
	mochila(n,M,pesos,beneficios,0,0,0);
	cout<<"el minimo requerido es: "<< mejor_beneficio_global << endl;
	return 0;
}
