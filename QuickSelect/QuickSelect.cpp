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
		while(i<=final && arr[i] <= pivote)
		{
			i++;
		}
		while(arr[j] > pivote)
		{
			j--;
		}
		if(i>=j)
		{
			break;
		}
		swap(arr[i], arr[j]);
	}
	swap(arr[inicio],arr[j]);
	return j;
}

int QuickSelect(int arr[], int inicio, int final, int k)
{
	if(inicio == final)
	{
		return arr[inicio];
	}
	int pospivote = particion(arr, inicio, final);
	
	if(pospivote == k)
	{
		return arr[pospivote];
	}
	else if(pospivote > k)
	{
		return QuickSelect(arr, inicio, pospivote - 1, k);
	}
	else
	{
		return QuickSelect(arr, pospivote + 1, final, k);
	}
}

int mediana(int arr[], int n)
{
	int k = n/2;
	return QuickSelect(arr, 0 , n - 1, k);
}

int main()
{
	int arr[] = {2,5,9,14,1,19,50,30,8};
	int n = sizeof(arr) / sizeof(arr[0]);
	int mediana_x = mediana(arr, n);
	cout<<"la mediana es " << mediana_x << endl;
	return 0;
}
