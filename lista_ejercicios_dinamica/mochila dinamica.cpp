#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>>	mochiladinamica(int cap_max, int mochila[6][2], int n)
{
	vector<vector<int>> B(n + 1,vector<int>(cap_max + 1,0));
	for(int k = 0; k < n; k++)
	{
		int peso = mochila[k][0];
		int beneficio = mochila[k][1];
		for(int p = 0; p <= cap_max; p++)
		{
			if(p < peso)
			{
				B[k + 1][p] = B[k][p];
			}
			else
			{
				B[k + 1][p] = max(B[k][p - peso]+beneficio,B[k][p]);
			}
		}
	}
	return B;
}

int main()
{
	cout<<"mochila 1"<<endl;
	int cap_max = 15;
	int mochila[6][2] = {
		{3,12},
		{7,3},
		{4,7},
		{2,4},
		{1,3},
		{6,8}
	};
	int n = 6;
	vector<vector<int>> rpta = mochiladinamica(cap_max,mochila,n);
	cout<<"el resultado mas optimo es " << rpta[n][cap_max] << endl;
	return 0;
}
