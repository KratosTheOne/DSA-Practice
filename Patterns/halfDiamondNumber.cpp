#include<iostream>
using namespace std;
int main()
{
    int n = 5;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << n - j;
        }
        cout << "\n";
    }
    for(int i = 0; i <= n; i++)
    {
        for(int k = n; k >= i; k--)
        {
            cout << k;
        }
        cout << "\n";
    }
    return 0;
}

