#include <iostream>

using namespace std;

void Insertion_Sort(int arr[], int tam)
{
	for (int i = 1; i < tam; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
}

void print(int arr[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	cout << "---------------INSERTION SORT---------------" << endl;
	cout << "array original" << endl;
	int arr[] = { 23,1,10,5,2 };
	print(arr, 5);
	cout << "array ordenado" << endl;
	Insertion_Sort(arr, 5);
	print(arr, 5);
	cout << "--------------------------------------------" << endl;

	return 0;
}