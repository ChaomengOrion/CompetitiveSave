#include <bits/stdc++.h>
const int N = 5;
int main()
{
    std::cout << "N\t10*N\t100*N\t1000*N\n\n";
    for (int i = 1; i <= N; i++) {
        std::cout << i << '\t' << 10 * i << '\t' << 100 * i << '\t' << 1000 * i << '\n';
    }
}