#include <iostream>

using i64 = long long;

i64 reverse(i64 n) {
    i64 ans = 0;
    while (n) {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    return ans;
}

void solve() {
    std::string num;
    std::cin >> num;
    size_t pos = num.find('.');
    if (pos == num.npos) pos = num.find('/');
    if (pos != num.npos) {
        std::cout << std::to_string(reverse(std::stoll(num.substr(0, pos)))) + num[pos] +
                         std::to_string(reverse(std::stoll(num.substr(pos + 1))))
                  << std::endl;
        return;
    }
    pos = num.find('%');
    if (pos != num.npos) {
        std::cout << std::to_string(reverse(std::stoll(num.substr(0, pos)))) + "%"
                  << std::endl;
        return;
    }
    std::cout << reverse(std::stoll(num)) << std::endl;
}

int main() {
    solve();
}