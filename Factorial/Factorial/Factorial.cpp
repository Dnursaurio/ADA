#include <iostream>

using namespace std;

int factorial(int n)
{
	int nless = n - 1;
	for (n; n > 0; n--)
	{
		if (nless == 1)
		{
			return n;
		}
		n *= nless;
		n = nless;
		nless--;
	}
}

int main()
{
	int n = 3;
	factorial(n);
	return 0;
}