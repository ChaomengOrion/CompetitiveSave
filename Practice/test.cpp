#include <bits/stdc++.h>

int main()
{
    int* b;
    {
        int* a = new int[] {1, 2, 3};
        b = a;
    }
    std::cout << b[0] << std::endl;
}