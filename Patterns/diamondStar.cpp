#include<iostream>
using namespace std;
int main()
{
    int n = 6;
    for(int i = 0; i < 2 * n ; i++)
    {
        int totalCol = i > n ? 2 * n - i : i;
        int spaces = n - totalCol;
        for(int j = 0; j < spaces; j++)
        {
            cout << ' ';
        }
        for(int j = 0; j < totalCol; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
    return 0;
}

