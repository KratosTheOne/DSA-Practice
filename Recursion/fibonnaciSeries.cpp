#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 10;
    if(n == 0)
        cout << n;
    else if(n == 1)
        cout << 0 << " " << 1;
    else
    {
        int a = 0;
        int b = 1;
        cout << a << " " << b << " ";
        int c = a + b;
        for(int i = 2; i < n; i++)
        {
            cout << c << " ";
            a = b;
            b = c;
            c = a + b;
        }
    }
    return 0;
}

