#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LCS(vector<int>x, vector<int>y)
{
	int m = x.size();
	int n = y.size();
	
	vector<vector<int>>c(m + 1, vector<int>(n + 1, 0));
	
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else
			{
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
			}
		}
	}
	
	int i = m, j = n;
	vector<int> seleccionados;
	
	while(i > 0 && j > 0)
	{
		if(x[i - 1] == y[j - 1])
		{
			seleccionados.push_back(x[i - 1]);
			i--;
			j--;
		}
		else if(c[i - 1][j] >= c[i][j - 1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	
	cout<<"los elementos seleccionados son: ";
	for(int k = seleccionados.size() - 1; k > 0; k--)
	{
		cout<<seleccionados[k]<<" ";
	}
	cout<<endl;
	
	return c[m][n];
}

int main()
{
	vector<int> a = {11, 17, 5, 8, 6, 4, 7, 12, 3};
	vector<int> b = {5, 6, 7, 12};
	int l = LCS(a,b);
	cout << "la cadena de mayor longitud es de: "<<l<<endl;
	return 0;
}
