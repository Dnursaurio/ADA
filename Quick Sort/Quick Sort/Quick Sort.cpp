#include <iostream>

using namespace std;

void quick_Sort(int arr[],int tam)
{
	int* pivot = &arr[tam - 1];
	int* i = arr - 1;

	if (tam <= 1)
	{
		return;
	}

	for (int* j = arr; j < arr + tam;j++)
	{
		if (*j < *pivot)
		{
			i++;
			swap(*i, *j);
		}
	}
	i++;
	swap(*i, *pivot);

	int p = i - arr;

	quick_Sort(arr, p);
	quick_Sort(arr + p + 1, tam - p - 1);
}

void print(int arr[],int tam)
{
	for (int i = 0; i < tam; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	cout << "--------------QUICK SORT--------------" << endl;
	cout << "array original" << endl;
	int arr[] = { 10,80,30,90,40 };
	int tam = 5;
	print(arr, tam);
	cout << "array ordenado" << endl;
	quick_Sort(arr, tam);
	print(arr, tam);
	cout << "--------------------------------------" << endl;
}