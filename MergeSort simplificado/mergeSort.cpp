#include <iostream>

using namespace std;

void merge(int arr[], int inicio, int mitad, int final)
{
	int tam = final - inicio + 1;
	int *temp = new int[tam];
	int i = inicio;
	int j = mitad + 1;
	int k = 0;
	
	while(i <= mitad && j <= final)
	{
		if(arr[i] < arr[j])
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
	
	mergeSort(arr, inicio ,mitad);
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
	int arr[] = {10,14,25,12,9,13};
	print(arr,6);
	mergeSort(arr,0,5);
	print(arr,6);
	return 0;
}
