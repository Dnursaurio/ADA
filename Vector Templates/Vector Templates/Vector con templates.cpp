#include <iostream>

using namespace std;

template<class T>
struct Vector
{
	T* vector = nullptr;
	int nro_elem = 0;
	int limite_max = 0;
	int aumento = 10;
};

template<class T>
void Resize(Vector<T>*& ptrthis)
{
	T* nvector = nullptr;
	nvector = new T[ptrthis->limite_max + ptrthis->aumento];
	for (int i = 0; i < ptrthis->limite_max; i++)
	{
		nvector[i] = ptrthis->vector[i];
	}
	delete[] ptrthis->vector;
	ptrthis->vector = nvector;
	ptrthis->limite_max = ptrthis->limite_max + ptrthis->aumento;
}

template<class T>
void Insert(Vector<T>* ptrvec, int elem)
{
	if (ptrvec->nro_elem == ptrvec->limite_max)
	{
		Resize(ptrvec);
	}
	ptrvec->vector[ptrvec->nro_elem] = elem;
	ptrvec->nro_elem++;
}

int main()
{
	cout << "----------------------------VECTOR CON TEMPLATES----------------------------" << endl;
	Vector<int>* ptrv = new Vector<int>;
	ptrv->vector = new int[10];
	ptrv->limite_max = 10;

	for (int o = 0; o < ptrv->limite_max; o++)
	{
		Insert(ptrv, o);
	}

	for (int i = 0; i < ptrv->nro_elem; i++)
	{
		cout << ptrv->vector[i] << " ";
	}
	cout << endl;

	cout << "Expandiendo vector" << endl;
	Insert(ptrv, 10);
	Insert(ptrv, 21);
	for (int i = 0; i < ptrv->nro_elem; i++)
	{
		cout << ptrv->vector[i] << " ";
	}
	cout << endl;

	cout << "----------------------------------------------------------------------------" << endl;

	return 0;
}
