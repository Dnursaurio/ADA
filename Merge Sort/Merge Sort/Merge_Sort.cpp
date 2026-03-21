#include <iostream>

using namespace std;

void rearmar(int arr[], int* izq, int* der, int tam_izq, int tam_der)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < tam_izq && j < tam_der)
	{
		if (izq[i] > der[j])
		{
			arr[k] = der[j];
			j++;
			k++;
		}
		else
		{
			arr[k] = izq[i];
			i++;
			k++;
		}
	}

	//Sobra la izquierda caso izq > der
	while (i < tam_izq)
	{
		arr[k] = izq[i];
		i++;
		k++;
	}

	//Sobra la derecha caso izq < der
	while (j < tam_der)
	{
		arr[k] = der[j];
		j++;
		k++;
	}
}

void Merge(int arr[], int tam)
{
	if (tam == 1)
	{
		return;
	}

	int* izq = arr;
	int* der = arr + tam / 2;

	int *arrizq = new int[tam / 2];
	int *arrder = new int[tam - (tam / 2)];

	for (int i = 0; i < tam / 2; i++)
	{
		arrizq[i] = izq[i];
	}
	for (int i = 0,o = 0; i < tam && o < tam - (tam / 2); i++,o++)
	{
		arrder[o] = der[i];
	}

	int tam_izq  = tam / 2;
	int tam_der  = tam - (tam / 2);
	izq = arrizq;
	der = arrder;
	Merge(izq, tam_izq);
	Merge(der, tam_der);

	rearmar(arr, izq, der, tam_izq, tam_der);

	delete []arrizq;
	delete []arrder;
}

void print(int arr[],int tam)
{
	cout << "| ";
	for (int i = 0; i < tam; i++)
	{
		cout << arr[i] << " | ";
	}
	cout << endl;
}

int main()
{
	cout << "----------------MERGE SORT----------------" << endl;
	cout << "Array Original:" << endl;
	int arr[] = { 70,80,30,50,10 };
	int tam = 5;
	print(arr, tam);
	cout << "Array Ordenado:" << endl;
	Merge(arr, tam);
	print(arr, tam);
	cout << "------------------------------------------" << endl;
}