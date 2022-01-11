#include<iostream>
using namespace std;
int main()
{
    int n = 5, num = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            cout << ' ';
        }
        for(int k = 1; k <= 2 * i - 1; k++)
        {
            if(k == 1 || k == 2 * i - 1)
                cout << num;
            else
                cout << ' ';
        }
        num++;
        cout << "\n";
    }
    num = n-1;
    for(int i = n-1; i >= 1; i--)
    {
        for(int j = n; j >= i; j--)
        {
            cout << ' ';
        }
        for(int k = 1; k <= 2 * i - 1; k++)
        {
            if(k == 1 || k == 2 * i - 1)
                cout << num;
            else
                cout << ' ';
        }
        num--;
        cout << "\n";
    }
    return 0;
}

