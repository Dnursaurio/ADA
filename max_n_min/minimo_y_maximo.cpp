#include <iostream>

using namespace std ;
void imprimir ( int A [] , int n) {
	for (int i = 0; i < n; i ++) {
		cout << A [i] << " ";
	}
	cout << endl ;
}

void maximo_y_minimo(int arr[], int tam)
{
	cout<< "maximo: "<<arr[tam-1]<<" minimo: "<<arr[0]<<endl;
}

int particion ( int A [] , int inicio , int fin ) 
{
	int pivote = A[ inicio ];
	int i = inicio + 1;
	int j = fin ;
	while ( true ) {
		while (i <= fin && A[ i] <= pivote ) {
			i ++;
		}
		while (A [j] > pivote ) {
			j--;
		}
		if (i >= j) {
			break ;
		}
		swap (A[i], A[j]) ;
	}
	swap (A[ inicio ], A[j ]) ;
	return j;
}

void quicksort ( int A [] , int inicio , int fin ) {
	if ( inicio < fin ) {
		int posPivote = particion (A , inicio , fin ) ;
		quicksort (A , inicio , posPivote - 1) ;
		quicksort (A , posPivote + 1, fin ) ;
	}
}

int main()
{
	int arr[7]={12, 4, 7, 20, 1, 15, 9};
	quicksort(arr,0,7);
	imprimir(arr,7);
	maximo_y_minimo(arr,7);
	return 0;
}
