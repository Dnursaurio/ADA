#include <iostream>

using namespace std;

void merge(int arr[], int inicio, int mitad, int final)
{
	int tam = final - inicio + 1;
	int* temp = new int[tam];
	int i = inicio;
	int j = mitad + 1;
	int k = 0;
	while(i <= mitad && j <= final)
	{
		if(arr[i] > arr[j])
		{
			temp[k] = arr[i];
			i++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	while(i <= mitad)
	{
		temp[k] = arr[i];
		i++;
		k++;
	}
	while(j <= final)
	{
		temp[k] = arr[j];
		j++;
		k++;
	}
	
	for(int i = 0; i < tam; i++)
	{
		arr[inicio + i] = temp[i];
	}
	delete[] temp;
}

void mergeSort(int arr[], int inicio, int final)
{	
	if(inicio >= final)
	{
		return;
	}
	
	int mitad = inicio + (final - inicio) / 2;
	
	mergeSort(arr, inicio, mitad);
	mergeSort(arr, mitad + 1, final);
	
	merge(arr, inicio, mitad, final);
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
	int arr[] = {1,0,20,14,10,35,6,9};
	int tam = 8;
	print(arr,tam);
	mergeSort(arr,0,tam - 1);
	print(arr,tam);
	return 0;
}
