#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LCS(vector<int> &v)
{
	int n = v.size(), long_max = 0;
	vector<int>dp(n,1);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(v[i] > v[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		long_max = max(long_max, dp[i]);
	}
	return long_max;
}

int main()
{
	vector<int> V = {11, 17, 5, 8, 6, 4, 7, 12, 3};
	cout << "Longitud maxima: " << LCS(V) << endl;
	return 0;
}
