#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> lim(N);
    for (int i = 0; i < N; i++) {
        std::cin >> lim[i];
    }
    std::vector<i64> fromLeft(N), fromRight(N);
    
    {
        std::deque<int> dq;
        for (int i = 0; i < N; i++) {
            while (!dq.empty() && lim[dq.back()] >= lim[i]) {
                dq.pop_back();
            }
            if (!dq.empty()) {
                fromLeft[i] = fromLeft[dq.back()] + 1LL * (i - dq.back()) * lim[i];
            } else {
                fromLeft[i] = 1LL * (i + 1) * lim[i];
            }
            dq.push_back(i);
        }
    }
    {
        std::deque<int> dq;
        for (int i = N - 1; i >= 0; i--) {
            while (!dq.empty() && lim[dq.back()] >= lim[i]) {
                dq.pop_back();
            }
            if (!dq.empty()) {
                fromRight[i] = fromRight[dq.back()] + 1LL * (dq.back() - i) * lim[i];
            } else {
                fromRight[i] = 1LL * (N - i) * lim[i];
            }
            dq.push_back(i);
        }
    }
    i64 max = 0; int index = -1;
    for (int i = 0; i < N; i++) {
        i64 height = fromLeft[i] + fromRight[i] - lim[i];
        if (height > max) {
            max = height;
            index = i;
        }
    }

    std::vector<int> ans(N);
    int upper = lim[index];
    ans[index] = upper;
    for (int i = index + 1; i < N; i++) {
        upper = std::min(upper, lim[i]);
        ans[i] = upper;
    }
    upper = lim[index];
    for (int i = index - 1; i >= 0; i--) {
        upper = std::min(upper, lim[i]);
        ans[i] = upper;
    }

    std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, " "));
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}