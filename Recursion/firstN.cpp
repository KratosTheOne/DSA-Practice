#include<iostream>
using namespace std;
int firstN(int n)
{
    if(n == 0 || n == 1)
        cout << n << " ";
    else
    {
        firstN(n - 1);
        cout << n << " ";
    }
}
int main()
{
    int n = 10;
    firstN(n);
    return 0;
}
