#include <iostream>
#include <vector>

using namespace std;

double probPOff(int n, double p)
{
	vector<vector<double>>P(n + 1, vector<double>(n + 1,0.0));
	for(int j = 1; j <= n; j++)
	{
		P[0][j] = 1.0;
	}
	for(int i = 1; i <= n; i++)
	{
		P[i][0] = 0.0;
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			P[i][j] = p * P[i - 1][j] + (1 - p) * P[i][j - 1];
		}
	}
	return P[n][n];
}

int main()
{
	cout<<"probabilidad de campeonar el playoff"<<endl;
	int n = 4;
	double p = 0.666;
	double rpta = probPOff(n,p);
	cout << "La probabilidad de ganar el torneo es: " << rpta * 100 << "%" << endl;
	return 0;
}
