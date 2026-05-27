#include <iostream>

using namespace std;

void merge(int arr[], int inicio, int mitad, int final)
{
	int tam = final - inicio +1;
	int* temp = new int[tam];
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
	mergeSort(arr,inicio,mitad);
	mergeSort(arr, mitad + 1, final);
	merge(arr, inicio, mitad, final);
}

int main()
{
	int arr[] = {2,0,2,5,4,3,5,8,1,0,10,9,7};
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr,0, n - 1);
	int j = 0;
	for(int i = 1; i < n; i++)
	{
		if(arr[i] != arr[j])
		{
			j++;
			arr[j] = arr[i];
		}
	}
	
	int n_tam = j + 1;
	
	for( int i = 0; i < n_tam; i++)
	{
		cout<< arr[i] << " ";
	}
	cout<< endl;
	
	return 0;
}
