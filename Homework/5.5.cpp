#include <bits/stdc++.h>

using i64 = long long;

int main(){
    int n;
    std::cin >> n;
    i64 ans = 1;
    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        ans *= temp;
    }
    std::cout << ans << std::endl;
}