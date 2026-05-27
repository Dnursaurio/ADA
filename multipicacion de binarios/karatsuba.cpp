#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

long long karatsuba(long long a, long long b, int n)
{
	if(n == 1)
	{
		return a * b;
	}
	int mitad = n / 2;
	
	long long a1 = a >> mitad;
	long long a0 = a & ((1LL << mitad) - 1);
	long long b1 = b >> mitad;
	long long b0 = b & ((1LL << mitad) - 1);
	
	long long x = karatsuba(a1,b1,mitad);
	long long y = karatsuba(a0,b0,mitad);
	long long z = karatsuba(a1 + a0, b1 + b0, mitad);
	
	return (x << (2 * mitad)) + ((z - x - y) << mitad) + y;
}

int main()
{
	long long a = 0b10;
	long long b = 0b11;
	
	long long mayor = (a > b)? a : b;
	int bits_reales = log2(mayor) + 1;
	
	int n = pow(2,ceil(log2(bits_reales)));
	
	long long rpta = karatsuba(a, b, n);
	cout<<"el resultado de multiiplicar " << bitset<8>(a) << " (" << a << ") x " << bitset<8>(b) << " (" << b << ") es " << bitset<16>(rpta) << " (" << rpta << ")" << endl;
	return 0;
}
