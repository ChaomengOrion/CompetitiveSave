#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size)                         \
    std::cerr << #_vec << " = " << '[';           \
    for (int _i = 0; _i < (_size); _i++) {        \
        std::cerr << (_vec)[_i];                  \
        if (_i != (_size) - 1) std::cerr << ", "; \
    }                                             \
    std::cerr << ']' << std::endl;

using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;
    int a[10005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<int> s;
    int k = 0;
    int count = 0;
    int pos = 0;
    while (count + s.size() < n) {
        int min = INT_MAX;
        for (int i = k; i < k + c - s.size() && i < n; i++) {
            if (a[i] < min) {
                min = a[i];
                pos = i;
            }
        }
        if (s.empty() || min < s.top()) {
            for (int i = k; i <= pos; i++) {
                s.push(a[i]);
            }
            k = pos + 1;
        }
        cout << s.top() << " ";
        s.pop();
        count++;
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}