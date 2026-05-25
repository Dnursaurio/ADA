//Cuela Rodríguezx Alonzo Estéfano
//Tacca Chambilla Arnolsmith Anderson

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

template<class T>
struct Puntos
{
	T x,y;
};
template<class T>
bool compararY(const Puntos<T>&a, const Puntos<T>&b)
{
	return a.y < b.y;
}

template<class T>
bool compararX(const Puntos<T>&a, const Puntos<T>&b)
{
	return a.x < b.x;
}

template<class T>
double parcercano(vector<Puntos<T>> &pv, int izq, int der)
{
	if (max(izq, der) - min(izq, der) <= 2)
	{
		double min_3er_punto = 0;

		if (max(izq, der) - min(izq, der) == 2)
		{
			double dist_vertical_1 = max(pv[izq].y, pv[izq + 1].y) - min(pv[izq].y, pv[izq + 1].y);
			double dist_horizontal_1 = max(pv[izq].x, pv[izq + 1].x) - min(pv[izq].x, pv[izq + 1].x);
			double dist_vertical_2 = max(pv[izq + 1].y, pv[der].y) - min(pv[izq + 1].y, pv[der].y);
			double dist_horizontal_2 = max(pv[izq + 1].x, pv[der].x) - min(pv[izq + 1].x, pv[der].x);

			min_3er_punto = min(sqrt(pow(dist_horizontal_1, 2) + pow(dist_vertical_1, 2)), sqrt(pow(dist_horizontal_2, 2) + pow(dist_vertical_2, 2)));
		}
		double dist_vertical_3 = max(pv[izq].y, pv[der].y) - min(pv[izq].y, pv[der].y);
		double dist_horizontal_3 = max(pv[izq].x, pv[der].x) - min(pv[izq].x, pv[der].x);
		return min_3er_punto != 0 ? min(min_3er_punto,sqrt(pow(dist_horizontal_3,2) + pow(dist_vertical_3,2))) : sqrt(pow(dist_horizontal_3, 2) + pow(dist_vertical_3, 2));
	}

	int mitad = (izq + der) / 2;
	double d_izq = parcercano(pv, izq, mitad);
	double d_der = parcercano(pv, mitad + 1, der);
	double d = min(d_izq, d_der);
	int frontera = pv[mitad].x;
	vector<Puntos<T>>franja;
	//limitamos la fonrtera en el eje x
	for (int j = izq; j <= der; j++)
	{
		if (abs(pv[j].x - frontera) < d)
		{
			franja.push_back(pv[j]);
		}
	}
	sort(franja.begin(), franja.end(), compararY<T>);

	//hallamos la menor distancia netre los puntos mas cercanos de dicha frontera
	for (int i = 0; i < franja.size(); i++)
	{
		for (int j = i + 1; j < franja.size() && (franja[j].y - franja[i].y) < d; j++)
		{
			double distancia = sqrt(pow(franja[j].x - franja[i].x, 2) + pow(franja[j].y - franja[i].y, 2));
			if (distancia < d) d = distancia;
		}
	}

	return d;
}

int main() {
	
	//cerando los puntos del caso mas pequeño
	
	vector<Puntos<int>> vector_puntos;

	int i = 0;
	int nro_puntos = 0;
	cout<<"Menor distancia entre n puntos"<<endl;
	cout << "----------------------------------------------------" << endl;
	cout<<"ADVERTENCIA: solo usar numeros enteros"<<endl;
	cout<<"ingrese el numero de puntos que va a usar:"<<endl;
	cin>>nro_puntos;
	cout<<"Usted estara utilizando "<<nro_puntos<<" puntos"<<endl;
	cout<<"Ahora ingrese las coordenandas de los puntos establecidos"<<endl;
	while(i < nro_puntos)
	{
		Puntos<int> puntos;
		cout<<"punto "<< i + 1<<endl;
		cout<<"x: ";
		cin>>puntos.x;
		cout<<"y: ";
		cin>>puntos.y;
		vector_puntos.push_back(puntos);
		i++;
	}
	
	//ordenanmos el vector
	sort(vector_puntos.begin(), vector_puntos.end(), compararX<int>);

	cout << "----------------------------------------------------" << endl;
	cout << "los puntos ordenados se ven asi" << endl;

	for (int i = 0; i < vector_puntos.size(); i++)
	{
		cout << vector_puntos[i].x << ", " << vector_puntos[i].y << " = P"<< i + 1 << endl;
	}

	cout << "----------------------------------------------------" << endl;
	int izq = 0;
	int der = vector_puntos.size() - 1;

	double resultado = parcercano<int>(vector_puntos, izq, der);

	cout << "la menor distancia entre los " << nro_puntos << " puntos es: " << resultado << endl;

	return 0;
}

