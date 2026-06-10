#include <iostream>

using namespace std;

const int INF = 999999;

void CostoCanoas(int t[6][6], int n)
{
	int c[6][6];
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			c[i][j] = t[i][j];
		}
	}
	
	for(int l = 1; l < n ; l++)
	{
		for(int i = 1; i <= n - l; i++)
		{
			int j = i + l;
			
			for(int k = i + 1; k < j; k++)
			{
				if(c[i][k] + c[k][j] < c[i][j])
				{
					c[i][j] = c[i][k] + c[k][j];
				}
			}
		}
	}
	
	cout << "\n--- MATRIZ DE COSTOS MINIMOS OPTIMOS ---" << endl;
	cout << "   1   2   3   4   5" << endl; // Encabezado de columnas
	for (int i = 1; i <= n; i++) {
		cout << i << "  "; // Índice de fila
		for (int j = 1; j <= n; j++) {
			if (c[i][j] == INF) {
				cout << "INF ";
			} else {
				// Formateamos un poco el espacio para que la tabla quede alineada
				if (c[i][j] < 10) cout << " " << c[i][j] << "  ";
				else cout << c[i][j] << "  ";
			}
		}
		cout << endl;
	}
}

int main()
{
	int n = 5;
	int t[6][6] = {
	{0,   0,   0,   0,   0,   0},
	{0,   0,  17,   8,  16,  20},
	{0, INF,   0,  12,   6,  15},
	{0, INF, INF,   0,  12,  16},
	{0, INF, INF, INF,   0,  15},
	{0, INF, INF, INF, INF,   0}};
	CostoCanoas(t,n);
	return 0;
}
