#include <iostream>
#include <set>
#include <string>

using namespace std;

int tabla[3][3] = {
	//a,b,c
	{1,1,0},//a
	{2,1,0},//b
	{0,2,2}//c
};

set<int>dp[100][100];

set<int>resolver(int i, int j, string &x)
{
	if(i == j) return {x[i] - 'a'};
	if(!dp[i][j].empty()) return dp[i][j];
	set<int>resultados;
	for(int k = i; k < j; k++)
	{
		set<int>izq = resolver(i,k,x);
		set<int>der = resolver(k + 1,j,x);
		for(int s1:izq)
		{
			for(int s2:der)
			{
				resultados.insert(tabla[s1][s2]);
			}
		}
	}
	return dp[i][j] = resultados;
}

int main()
{
	string x = "ac";
	set<int>pos_fin = resolver(0,x.size() - 1,x);
	if(pos_fin.count(0))
	{
		cout<<"Si es posible obtener 'a'"<<endl;
	}
	else
	{
		cout<<"NO es posible"<<endl;
	}
	return 0;
}
