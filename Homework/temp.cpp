#include <iostream>
using namespace std;
bool prime(int a)
{
    bool yes = true;
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            yes = false;
            break;
        }
    }
    return yes;
}

int main()
{
    int m;
    int a[10];
    while (1)
    {
        if (!(cin >> m)) break;       
        a[0] = m;
        for (int i = 1; i <= 9; i++)
        {

            cin >> m;
            *(a + i) = m;
        }
        for (int k = 0; k <= 9; k++)
        {
            if (prime(*(a + k)) != 0) cout << *(a + k) << " ";
        }
        cout << endl;
    }
}
