#include<iostream>
using namespace std;
int main()
{
    int n = 5;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cout << ' ';
        }
        for(int j = n - i - 1; j >= 0; j--)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}

