#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct licencia
{
	double delta; //ese delta es el aumento del precio
};
	
bool descendente(licencia a, licencia b)
{
	return a.delta > b.delta;
}

void costo_minimo(vector<licencia>l, int n, double precio_base)
{
	sort(l.begin(), l.end(), descendente);
	double costo_total = 0;
	for(int k = 0; k < n; k++)
	{
		double precio_actual = precio_base * pow(1 + l[k].delta,k);
		costo_total += precio_actual;
	}
	cout<< "la adquisicion de todas la licencias te costara " << costo_total << endl;
}

int main()
{
	vector<licencia>l={{0.1},{0.5},{1.0}};
	int n = 3;
	double precio_base = 100.0;
	costo_minimo(l,n,precio_base);
	return 0;
}
