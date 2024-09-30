#include <bits/stdc++.h>
#define CFMode

using i64 = long long;

#define TRACE(x) std::cout << "TRACE: " << #x << " = " << (x) << std::endl;
#define DEBUG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define DEBUGV(vec, size) std::cerr << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cerr << vec[i]; if (i != size - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    unsigned long long a, b;
    std::cin >> a >> b;
    // 判断，是否存在两个非负整数 x, y，使得 x + y = a，x & y = b
    // 由于 x & y = b，所以 x 和 y 的二进制表示中，b 的二进制表示中的 1 的位置是相同的
    // 由于 x + y = a，所以 x 和 y 的二进制表示中，a 的二进制表示中的 1 的位置是不同的
    // 所以，只要找到 b 的二进制表示中的 1 的位置，然后将 a 的二进制表示中的 1 的位置分成两组，一组是 b 的二进制表示中的 1 的位置，另一组是不是 b 的二进制表示中的 1 的位置
    // 这样，就可以找到 x 和 y
    std::vector<char> a_bits(64, 0), b_bits(64, 0);
    std::vector<char> x_bits(64, 0), y_bits(64, 0);
    int max = 0;
    for (int i = 0; i < 64; i++) {
        a_bits[i] = (a >> i) & 1;
        b_bits[i] = (b >> i) & 1;
        if (a_bits[i] | b_bits[i]) max = i;
    }
    char carry = 0;
    for (int i = 0; i <= max; i++) {
        if (b_bits[i]) {
            if (a_bits[i] != carry || i == max) {
                std::cout << "NO" << std::endl;
                return;
            }
            x_bits[i] = y_bits[i] = 1;
            carry = 1;
        } else {
            if (a_bits[i] == carry) {
                carry = 0;
                x_bits[i] = y_bits[i] = 0;
                continue;
            } else {
                x_bits[i] = 1, y_bits[i] = 0;
                continue;
            }
        }
    }
    unsigned long long x = 0, y = 0;
    for (int i = 0; i <= max; i++) {
        x |= ((unsigned long long)x_bits[i] << i);
        y |= ((unsigned long long)y_bits[i] << i);
    }
    std::cout << "YES " << std::endl;
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