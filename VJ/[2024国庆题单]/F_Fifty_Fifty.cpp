#include <bits/stdc++.h>

void solve()
{
    std::string s;
    std::cin >> s;
    char a = s[0], b = 0, cnt = 1;
    for (int i = 1; i < 4; i++) {
        if (s[i] == a) cnt++;
        else if (s[i] == b) cnt--;
        else if (b == 0) {
            b = s[i];
            cnt--;
        } else {
            std::cout << "No" << std::endl;
            return;
        }
    }
    std::cout << (cnt == 0 ? "Yes" : "No") << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}