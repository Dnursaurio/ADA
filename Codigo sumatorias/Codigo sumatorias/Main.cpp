#include <iostream>
using namespace std;

int main()
{
    cout << "ingrese un limite:" << endl;
    int n = 0;
    cin >> n;

    int temp1 = 0;
    int temp2 = 0;

    int i = 1;
    /*while (i <= n)
    {
        int k = 1;
        temp1++;

        while (k <= 2 * n)
        {
            cout << "el valor de j es: " << k << endl;
            k++;
            temp2++;
        }
        i++;

    }
    cout << temp1 << " y " << temp2 << endl;
    cout << "el valor de i es: " << i << endl;*/

    /*for (i; i <= n; i++)
    {
        int j = 1;
        temp1++;
        while (j <= n)
        {
            cout << j << endl;
            j += 2;
            temp2++;
        }
    }
    cout << temp1 << " y " << temp2 << endl;*/

    /*while (i <= n)
    {
        int k = 1;
        temp1++;
        while (k <= n)
        {
            k++;
            temp2++;
        }
        i *= 2;
    }
    cout << temp1 << " y " << temp2 << endl;*/

    while (i <= n)
    {
        int j = i;
        temp1++;
        while (j <= n)
        {
            j++;
            temp2++;
        }
        i++;
    }
    cout << temp1 << " y " << temp2 << endl;



    return 0;
}