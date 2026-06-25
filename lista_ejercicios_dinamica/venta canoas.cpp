#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int n = 5;

vector<vector<int>> C = {
	//0, 1, 2, 3, 4, 5
	{0, 0, 0, 0, 0, 0},//0
	{0, 0, 17, 8, 16, 20},//1
	{0,INF, 0, 12, 6, 15},//2
	{0,INF,INF, 0, 12, 16},//3
	{0,INF,INF,INF, 0, 15},//4
	{0,INF,INF,INF,INF, 0} //5
};

int dp[100][100];

int costo_min(int i, int j)
{
	if(i == j)
	{
		return 0;
	}
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	int res = C[i][j];
	for(int k = i + 1; k < j; k++)
	{
		res = min(res, costo_min(i,k) + costo_min(k, j));
	}
	return dp[i][j] = res;
}

int main()
{
	for(int i = 1; i <=n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			dp[i][j] = -1;
		}
	}
	cout<<"elcosto minimo es: " <<costo_min(1,5)<<endl;
	return 0;
}
