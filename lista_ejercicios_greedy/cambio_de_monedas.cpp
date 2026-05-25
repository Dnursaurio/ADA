#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void monedas(vector<int>monedero, int monto)
{
	sort(monedero.rbegin(), monedero.rend());
	int total = 0;
	cout<< "Monto a devolver: " << monto << endl;
	cout<< "monedas utilizadas: " << endl;
	for(int moneda : monedero)
	{
		int cantidad = monto / moneda;
		if(cantidad > 0)
		{
			cout<< "se utilizaron: " << cantidad << " de " << moneda << " euros" << endl;
			total += cantidad;
			monto %= moneda;
		}
	}
	cout << "el total de monedas utilizado es: " << total << endl;
}

int main()
{
	vector<int> monedero = {100,50,20,10,5,2,1};
	int monto = 0;
	cout<<"Ingrese un monto: ";
	cin>> monto;
	cout<< endl;
	monedas(monedero, monto);
	return 0;
}
