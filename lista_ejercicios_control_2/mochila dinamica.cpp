#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mochila(int w,vector<int>&pesos, vector<int>&beneficios)
{
	int n = pesos.size();
	vector<int>dp(w + 1,0);
	for(int i = 0; i < n; i++)
	{
		for(int j = w; j >= pesos[i]; j--)
		{
			dp[j] = max(dp[j],dp[j - pesos[i]] + beneficios[i]);
		}
	}
	return dp[w];
}

int main()
{
	cout<<"mochila 1"<<endl;
	int w = 15;
	vector<int>pesos = {3,7,4,2,1,6};
	vector<int>beneficios = {12,3,7,4,3,8};
	int rpta = mochila(w,pesos,beneficios);
	cout<<"el resultado mas optimo es " << rpta << endl;
	return 0;
}
