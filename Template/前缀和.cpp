#include <bits/stdc++.h>

void sum()
{
    std::vector<int> n(100);
    n[0] = 0;
    for (int i = 1; i < n.size(); i++)
    {
        n[i] = n[i] + n[i - 1];
    }
}

int main()
{
    sum();
    return 0;
}