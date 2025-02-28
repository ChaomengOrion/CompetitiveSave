#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "[debug]util.hpp"
#define LOG(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGI(info, ...) std::cerr << "[" << __LINE__ << "]: <" << info << "> - [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define LOGA(...) std::cerr << "[" << __LINE__ << "]: [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define LOG(...)
#define LOGI(...)
#define LOGA(...)
#endif

using i64 = long long;

void solve() {
    std::string S;
    std::cin >> S;
    std::stack<char> left;
    for (char i : S) {
        switch (i) {
            case '(':
                left.push('(');
                break;
            case '[':
                left.push('[');
                break;
            case '<':
                left.push('<');
                break;
            case ')':
                if (left.empty() || left.top() != '(') {
                    std::cout << "No" << std::endl;
                    return;
                }
                left.pop();
                break;
            case ']':
                if (left.empty() || left.top() != '[') {
                    std::cout << "No" << std::endl;
                    return;
                }
                left.pop();
                break;
            case '>':
                if (left.empty() || left.top() != '<') {
                    std::cout << "No" << std::endl;
                    return;
                }
                left.pop();
                break;
        }
    }
    if (!left.empty()) {
        std::cout << "No" << std::endl;
        return;
    }
    std::cout << "Yes" << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}