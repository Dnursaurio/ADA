#include <iostream>
#include <vector>

using namespace std;

bool evaluarprecedencia(vector<vector<int>> &m, char u, char v, int n)
{
	int f = u - 'a';
	int c = v - 'a';
	
	vector<vector<int>> M = m;
	
	for(int k = 1; k < n; k++)
	{
		for(int i = 1; i < n; i++)
		{
			for(int j = 1; j < n; j++)
			{
				M[i][j] = M[i][j] || (M[i][k] && M[k][j]);
			}
		}
	}
	
	return M[f][c];
}

int main()
{
	cout<<"precedencia del alfabeto"<<endl;
	int n = 4;
	vector<vector<int>>m={
		//a,b,c,d
		{{0,1,0,0}},//a
		{{0,0,1,0}},//b
		{{0,0,0,1}},//c
		{{0,0,0,0}}	//d
	};
	
	char origen = 'a';
	char destino = 'c';
	if(evaluarprecedencia(m,origen,destino,n))
	{
		cout << "Resultado: " << origen << " SI precede a " << destino << " por transitividad!" << endl;
	}
	else
	{
		cout << "Resultado: " << origen << " NO precede a " << destino << " por transitividad!" << endl;
	}
	return 0;
}
