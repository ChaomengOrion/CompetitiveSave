#include <bits/stdc++.h>
//#define CFMode

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;
#define DEBUGV(vec, size) std::cout << '['; for (int i = 0; i < size; i++) { std::cout << vec[i]; if (i != size - 1) std::cout << ", "; } std::cout << ']' << std::endl;

void solve()
{
    std::string isbn;
    std::cin >> isbn;
    int sum = 0;
    for (int i = 0, cnt = 1; i < isbn.size(); i++) {
        if (isbn[i] == '-') continue;
        if (cnt < 10) sum += (isbn[i] - '0') * cnt++;
        else {
            char id = sum % 11;
            if (id == 10) id = 'X';
            else id += '0';
            if (isbn[i] == id) {
                std::cout << "Right" << std::endl;
            } else {
                std::cout << isbn.substr(0, i) + id << std::endl;
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#ifdef CFMode
    int t; std::cin >> t; while (t--) solve();
#else
    solve();
#endif
    return 0;
}