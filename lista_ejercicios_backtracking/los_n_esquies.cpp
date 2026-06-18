#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <climits>

using namespace std;

int mejor_costo_global = INT_MAX;

void n_esquies(int n, vector<int>&alturas, vector<pair<int,bool>>&esquies, int idx_alumno, int costo_acumulado)
{
	if(idx_alumno == n)
	{
		if(costo_acumulado < mejor_costo_global)
		{
			mejor_costo_global = costo_acumulado;
		}
		return;
	}
	for(int i = 0; i < n; i++)
	{
		if(esquies[i].second == 0)
		{
			esquies[i].second = 1;
			int resta = abs(alturas[idx_alumno] - esquies[i].first);
			if(costo_acumulado + resta < mejor_costo_global)
			{
				n_esquies(n,alturas,esquies,idx_alumno + 1, costo_acumulado + resta);
			}
			esquies[i].second = 0;
		}
	}
}

int main()
{
	int n = 4;
	vector<int>alturas = {178, 168, 190, 170};
	vector<pair<int,bool>> esquies = {
		{183, 0},
		{188, 0},
		{168, 0},
		{175, 0} 
	};
	n_esquies(n,alturas,esquies,0,0);
	cout<<"el minimo requerido es :"<< mejor_costo_global << endl;
	return 0;
}
