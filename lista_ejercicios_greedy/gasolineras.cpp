#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void paradas_gasolina(vector<int>gasolineras, int gasolina_en_tanque, int destino)
{
	int paradas = 0;
	int posicion = 0;
	int i = 0;
	while(posicion + gasolina_en_tanque < destino)
	{
		int ultima_estacion = posicion;
		while(i < gasolineras.size() && gasolineras[i] <= posicion + gasolina_en_tanque)
		{
			ultima_estacion = gasolineras[i];
			i++;
		}
		if(ultima_estacion == posicion)
		{
			cout<<"Error en la ruta"<<endl;
			return;
		}
		else
		{
			posicion = ultima_estacion;
			paradas++;
			cout<< "te detuviste en el KM "<< posicion << endl;
		}
	}
}

int main()
{
	vector<int> gasolineras = {10,20,50,80,100,120,150,200};
	int gasolina_en_tanque = 100;
	int destino = 150;
	paradas_gasolina(gasolineras,gasolina_en_tanque,destino);
	return 0;
}
