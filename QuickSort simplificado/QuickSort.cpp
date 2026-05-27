#include <iostream>
#include <algorithm>

using namespace std;

int particion(int arr[], int inicio, int final)
{
	int pivote = arr[inicio];
	int i = inicio + 1;
	int j = final;
	
	while(true)
	{
		while(i <= final && arr[i] <= pivote)
		{
			i++;
		}
		
		while(arr[j] > pivote)
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

void quickSort(int arr[], int inicio, int final)
{
	if(inicio < final)
	{
		int pos_pivote = particion(arr, inicio, final);
		
		quickSort(arr, inicio, pos_pivote - 1);
		quickSort(arr, pos_pivote + 1, final);
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
	int arr[] = {9,1,3,5,0,4,2,6,8,7};
	int tam = 10;
	print(arr, tam);
	quickSort(arr, 0, tam - 1);
	print(arr, tam);
	return 0;
}
