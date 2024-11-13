#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

std::string add(std::string a, std::string b) {
    short da[101] = {}, db[101] = {};
    for (int i = a.size() - 1; i >= 0; i--) {
        da[a.size() - 1 - i] = a[i] - '0';
    }
    for (int i = b.size() - 1; i >= 0; i--) {
        db[b.size() - 1 - i] = b[i] - '0';
    }
    short ans[101] = {};
    short carry = 0;
    short size = 1;
    for (int i = 0; i < 101; i++) {
        short res = db[i] + da[i] + carry;
        carry = 0;
        if (res > 9) {
            res -= 10;
            carry = 1;
        }
        if (res > 0) size = i + 1;
        ans[i] = res;
    }
    std::string ansstr = "";
    for (int i = size - 1; i >= 0; i--) {
        ansstr += (char)(ans[i] + '0');
    }
    return ansstr;
}

void solve() {
    std::string a, b;
    std::cin >> a >> b;
    std::cout << add(a, b) << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}