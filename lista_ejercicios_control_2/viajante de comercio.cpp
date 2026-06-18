#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int N  = 4;
vector<vector<int>>dist ={
	{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}
};
int viajante(int i, set<int> S)
{
	if(S.empty())
	{
		return  dist[i][0];
	}
	int costo_min = INF;
	for(int j:S)
	{
		set<int>prox_S = S;
		prox_S.erase(j);
		int costo_actual = dist[i][j] + viajante(j,prox_S);
		costo_min = min(costo_min, costo_actual);
	}
	return costo_min;
}

int main()
{
	set<int> S;
	for (int i = 1; i < N; i++) S.insert(i);
	cout << "Costo minimo: " << viajante(0, S) << endl;
	return 0;
}
