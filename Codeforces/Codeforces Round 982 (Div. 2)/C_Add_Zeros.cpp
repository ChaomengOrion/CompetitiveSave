#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

void solve()
{
    int N;
    std::cin >> N;
    std::vector<i64> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    std::vector<i64> need(N);
    for (int i = 0; i < N; i++) {
        need[i] = arr[i] - (N - i);
    }

    std::priority_queue<std::pair<i64, int>> sum;
    std::map<i64, std::vector<int>> sum2indexs;
    for (int i = 0; i < N; i++) {
        if (need[i] + i > 0) {
            sum2indexs[need[i] + i].emplace_back(i);
            sum.emplace(need[i] + i, i);
        }
    }

    std::vector<int> checked(N);
    checked[0] = -1;
    auto check = [&](auto&& check, int pos) -> void {
        //LOG(pos)
        if (pos == 0) return;
        if (checked[pos] != 0) return;
        i64 nd = need[pos];
        //LOG("nd = " << nd)
        if (nd == 0) {
            checked[pos] = 1;
            return;
        }
        auto it = sum2indexs.find(nd);
        if (it == sum2indexs.end()) {
            checked[pos] = -1;
            return;
        }
        else {
            for (int t : it->second) {
                if (t == 0) continue;
                check(check, t);
                if (checked[t] == 1) {
                    checked[pos] = 1;
                    return;
                }
            }
            checked[pos] = -1;
            return;
        }
    };

    i64 max = 0;
    while (!sum.empty()) {
        auto [v, i] = sum.top();
        sum.pop();
        //LOG("Try " << i)
        if (v <= 0) break;
        check(check, i);
        if (checked[i] == 1) {
            max = v;
            break;
        }
    }

    //LOGV(checked, N)

    std::cout << N + max << std::endl;
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}