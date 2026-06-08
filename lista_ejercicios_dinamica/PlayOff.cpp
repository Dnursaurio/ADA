#include <iostream>
#include <vector>

using namespace std;

double probGanar(int n, double p)
{
	vector<vector<double>> M(n + 1, vector<double>(n + 1, 0.0));
	
	for(int j = 1; j <= n; j++)
	{
		M[0][j] = 1.0;
	}
	
	for(int i = 1; i <= n; i++)
	{
		M[i][0] = 0.0;
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			M[i][j] = p * M[i - 1][j] + (1.0 - p) * M[i][j - 1];
		}
	}
	
	return M[n][n];
}

int main()
{
	cout<<"probabilidad de campeonar el playoff"<<endl;
	int n = 4;
	double p = 0.666;
	double rpta = probGanar(n,p);
	cout << "La probabilidad de ganar el torneo es: " << rpta * 100 << "%" << endl;
	return 0;
}
