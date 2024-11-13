

#include <iostream>
#include<cmath>
using namespace std;
int digit(int x)
{
    for (int k = 1; ; k++)
    {
        if (x / 10 == 0) return k;
    }
}
bool num( int x )
{
    bool yes = 1;
    int m = digit(x);
    int* arr = new int [m];
    for (int i = 0; i < m; i++)
    {       
        arr[i] = x % 10;
        if(i<=m-2) x /= 10;
    }
    for (int k=0, j = m - 1 - k; k < j; k++)
    {
        if (arr[k] != arr[j])
        {
            yes = 0;
            break;
        }
    }   
    return yes;
}

int main()
{
    int x;
    while (cin >> x)
    {
        if (num(x) == 1) cout << "这是回文数" << endl;
        else cout << "这不是回文数" << endl;
    }
}

