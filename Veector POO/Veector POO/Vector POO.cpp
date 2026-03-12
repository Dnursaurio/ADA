#include <iostream>

using namespace std;

class Vector
{
public:

	Vector(int tam)
	{
		vector = new int[tam];
		limite_max = tam;
	}


	void Insert(int elem)
	{
		if (nro_elem == limite_max)
		{
			Resize();
		}
		vector[nro_elem] = elem;
		nro_elem++;
	}

	void print()
	{
		for (int i = 0; i < nro_elem; i++)
		{
			cout << vector[i] << " ";
		}
		cout << endl;
	}

private:
	int* vector = nullptr;
	int nro_elem = 0;
	int limite_max;
	int aumento = 10;
	void Resize()
	{
		int* nvector = nullptr;
		nvector = new int[limite_max + aumento];
		for (int i = 0; i < limite_max; i++)
		{
			nvector[i] = vector[i];
		}
		delete[] vector;
		vector = nvector;
		limite_max = limite_max + aumento;
	}
};

int main()
{
	cout << "----------------------------VECTOR ORIENTADO A OBJETOS----------------------------" << endl;
	Vector ptrv(10);

	for (int i = 0; i < 10; i++)
	{
		ptrv.Insert(i);
	}
	ptrv.print();

	cout << "Expandiendo vector" << endl;
	
	ptrv.Insert(14);
	ptrv.print();

	cout << "---------------------------------------------------------------------------------" << endl;

	return 0;
}
