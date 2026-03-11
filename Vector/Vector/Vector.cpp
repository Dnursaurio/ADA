#include <iostream>

using namespace std;

struct Vector
{
	int* vector = nullptr;
	int nro_elem = 0;
	int limite_max = 0;
	int aumento = 10;
};

void Insert(Vector* ptrvec, int elem)
{
	if (ptrvec->nro_elem == ptrvec->limite_max)
	{
		Resize(ptrvec);
	}
	ptrvec->vector[ptrvec->nro_elem++] = elem;
}

void Resize(Vector* ptrthis)
{
	int* nvector = NULL;
	nvector = new int[ptrthis->limite_max + ptrthis->aumento];
	for (int i = 0; i < ptrthis->limite_max; i++)
	{
		nvector[i] = ptrthis->vector[i];
	}
	ptrthis->limite_max = ptrthis->limite_max + ptrthis->aumento;
	int* borrador = ptrthis->vector;
	ptrthis->vector = nvector;
	delete borrador;
}

int main()
{
	Vector v;
	v.vector = new int[10];
	v.limite_max = 10;
}
