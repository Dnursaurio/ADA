#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
vector<int>p = {5,2,4,7};
int dp[100][100];

int resolver(int i, int j)
{
	if(i == j)
	{
		return 0;
	}
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	int costo_min = INF;
	for(int k = i; k < j; k++)
	{
		int costo_union = p[i] + p[k] + p[k + 1] + p[j];
		int costo_total = resolver(i,k) + resolver(k+1,j) + costo_union;
		costo_min = min(costo_min, costo_total);
	}
	return dp[i][j] = costo_min;
}

int main()
{
	int n = p.size();
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			dp[i][j] = -1;
		}
	}
	cout<<"el costo minimo es: "<< resolver(0,n - 1)<<endl;
	return 0;
}
