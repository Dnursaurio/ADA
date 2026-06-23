 #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ascendente(int a, int b)
{
	return a < b;
}

//un solo camarero
void menor_tiempo_mayor_salario(vector<int> tiempo)
{
	sort(tiempo.begin(), tiempo.end(), ascendente);
	int tiempo_total = 0;
	float propina_total = 0; 
	int reloj = 0;
	float propina = 0; 
	for(int i = 0; i < tiempo.size(); i++)
	{
		reloj += tiempo[i];
		propina = (float)1/reloj;
		tiempo_total += reloj;
		propina_total += propina;
	}
	cout<< "te has tardado "<< tiempo_total << " en atender a todos, ganaste "<< propina_total << " soles de propina" << endl;
}

//mas de un camarero
void n_camareros(vector<int> tiempo, int n)
{
	sort(tiempo.begin(), tiempo.end(), ascendente);
	int tiempo_total = 0;
	float propina_total = 0;
	vector<int>reloj_camareros (n,0);
	for(int i = 0; i < tiempo.size(); i++)
	{
		int c = i % n;
		reloj_camareros[c] += tiempo[i];
		float propina = (float)1/reloj_camareros[c];
		tiempo_total += reloj_camareros[c];
		propina_total += propina;
	}
	cout<< "los " << n << " camareros se han tardado " << tiempo_total << " juntando un total" << endl;
	cout<< "de " << propina_total << " soles en propinas, y cada uno gana " << propina_total/n << " soles de las propinas" << endl;
}

int main()
{
	cout<<"un solo camarero" << endl;
	vector<int>tiempo = {10,15,20};
	menor_tiempo_mayor_salario(tiempo);
	cout<<"n camareros" << endl;
	vector<int> tiempo_n = {10,15,20,25,30,35};
	int n = 5;
	n_camareros(tiempo_n, n);
	return 0;
}
