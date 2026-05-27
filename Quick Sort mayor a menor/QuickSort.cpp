#include <iostream>

using namespace std;

int particion(int arr[], int inicio, int final)
{
	int pivote = arr[inicio];
	int i = inicio + 1;
	int j = final;
	while(true)
	{
		while(i <= final && arr[i] >= pivote)
		{
			i++;
		}
		while(arr[j] <  pivote)
		{
			j--;
		}
		if(i >= j)
		{
			break;
		}
		swap(arr[i], arr[j]);
	}
	swap(arr[inicio], arr[j]);
	return j;
}

void QuickSort(int arr[], int inicio, int final)
{
	if(inicio < final)
	{
		int pospivote = particion(arr, inicio, final);
		QuickSort(arr, inicio, pospivote - 1);
		QuickSort(arr, pospivote + 1, final);
	}
}

void print(int arr[], int tam)
{
	for(int i = 0; i < tam; i++)
	{
		cout<< arr[i] << " ";
	}
	cout<< endl;
}

int main()
{
	int arr[] = {10,6,15,20,13,8,1};
	int tam = 7;
	print(arr,tam);
	QuickSort(arr, 0, tam - 1);
	print(arr, tam);
	return 0;
}
