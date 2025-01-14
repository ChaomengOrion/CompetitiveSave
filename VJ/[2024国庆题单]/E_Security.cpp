#include <bits/stdc++.h>

void solve()
{
    std::string s;
    std::cin >> s;
    char pre = s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == pre) {
            std::cout << "Bad" << std::endl;
            return;
        }
        pre = s[i];
    }
    std::cout << "Good" << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}