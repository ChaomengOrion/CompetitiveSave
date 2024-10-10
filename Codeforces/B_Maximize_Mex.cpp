#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(vec, size)                       \
    std::cerr << #vec << " = " << '[';        \
    for (int i = 0; i < size; i++) {          \
        std::cerr << vec[i];                  \
        if (i != size - 1) std::cerr << ", "; \
    }                                         \
    std::cerr << ']' << std::endl;
using namespace std;

int max_mex(vector<int>& a, int x) {
    unordered_map<int, multiset<int>> count;  // 记录每个模 x 的同余类中可用的数的个数
    
    for (int num : a) {
        count[num % x].insert(num);
    }
    
    int mex = 0;
    
    while (true) {
        int mod = mex % x;
        if (count[mod].size() > 0) {
            // 如果该模 x 余数有可用的数，使用一个并减少计数
            auto it = count[mod].begin();
            if (*it <= mex) {
                count[mod].erase(it);
                mex++;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    
    return mex;
}


void solve()
{
    int N, K;
    std::cin >> N >> K;
    std::vector<int> s(N);
    for (int i = 0; i < N; i++) {
        std::cin >> s[i];
    }
    std::cout << max_mex(s, K) << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}