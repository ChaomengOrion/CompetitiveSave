#include <bits/stdc++.h>
#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;


void solve()
{
    std::unordered_map<std::string, bool> map;
    auto ask = [&](const std::string& s) -> bool
    {
        if (map.contains(s)) return map.at(s);
        std::cout << "? " << s << '\n';
        std::cout.flush();
        int response;
        std::cin >> response;
        map.insert({s, response == 1});
        return response == 1;
    };
    auto get = [](char last) -> char
    {
        return last == '0' ? '1' : '0';
    };

    int n;
    std::cin >> n;
    std::string cur = "";
    bool rightFinshed = false;
    while ((int)cur.length() < n) {
        if (!rightFinshed) {
            std::string pre = cur;
            // 末尾测试
            char add = get(cur.back());
            cur += add;
            if (ask(cur)) continue;
            cur[cur.size() - 1] = get(add);
            if (ask(cur)) continue;
            else {
                rightFinshed = true;
                cur = pre;
            }
        }
        if (n == (int)cur.length()) break;
        if (rightFinshed) {
            char add = get(cur.front());
            cur = get(cur.front()) + cur;
            if (ask(cur)) continue;
            cur[0] = get(add);
            if (ask(cur)) continue;
            else {
                throw std::runtime_error("Impossible");
            }
        }
    }

    std::cout << "! " << cur << '\n';
    std::cout.flush();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
#ifdef CFMode
    int t; std::cin >> t; while (t--) solve();
#else
    solve();
#endif
    return 0;
}