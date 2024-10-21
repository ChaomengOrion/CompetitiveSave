#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

template<typename T>
class ST_Min {
private:
    std::vector<std::vector<T>> dp;
public:
    ST_Min(const std::vector<T>& inputs) {
        size_t len = inputs.size();
        int exp = log2(len);
        // dp[s][k] 代表从s出发走2^k步内的最值
        dp.resize(len, std::vector<T>(exp + 1, 0));
        for (size_t s = 0; s < len; s++) {
            dp[s][0] = inputs[s];
        }

        for (int k = 1; k <= exp; k++) {
            for (size_t s = 0; s + (1 << k) <= len; s++) {
                dp[s][k] = std::min(dp[s][k - 1], dp[s + (1 << (k - 1))][k - 1]);
            }
        }
    }

    T query(size_t start, size_t end) const {
        if (start > end) throw std::invalid_argument("start should be less than or equal to end");
        int exp = log2(end - start + 1);
        return std::min(dp[start][exp], dp[end - (1 << exp) + 1][exp]);
    }
};

template<typename T>
class ST_Max {
private:
    std::vector<std::vector<T>> dp;
public:
    ST_Max(const std::vector<T>& inputs) {
        size_t len = inputs.size();
        int exp = log2(len);
        // dp[s][k] 代表从s出发走2^k步内的最值
        dp.resize(len, std::vector<T>(exp + 1, 0));
        for (size_t s = 0; s < len; s++) {
            dp[s][0] = inputs[s];
        }

        for (int k = 1; k <= exp; k++) {
            for (size_t s = 0; s + (1 << k) <= len; s++) {
                dp[s][k] = std::max(dp[s][k - 1], dp[s + (1 << (k - 1))][k - 1]);
            }
        }
    }

    T query(size_t start, size_t end) const {
        if (start > end) throw std::invalid_argument("start should be less than or equal to end");
        int exp = log2(end - start + 1);
        return std::max(dp[start][exp], dp[end - (1 << exp) + 1][exp]);
    }
};

void solve()
{
    //std::cout << "===\n";
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> seq(N);
    
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }
    std::string op;
    std::cin >> op;
    
    ST_Min<int> stmin(seq);
    ST_Max<int> stmax(seq);
    //std::cout << stmin.query(0, N - 1) << std::endl;
    //std::cout << stmax.query(0, N - 1) << std::endl;

    auto check = [&](int l, int r) -> bool {
        //LOG("check " << l << ' ' << r)
        int min = stmin.query(l, r);
        if (l + 1 != min) return false;
        int max = stmax.query(l, r);
        if (r + 1 != max) return false;
        return true;
    };

    std::map<int, bool> pairs;
    int badCnt = 0;
    auto find = [&](int start) -> int {
        if (op[start] == 'R') {
            int lastL = -1;
            for (int j = start + 1; j < N; ++j) {
                if (lastL != -1 && op[j] == 'R') break;
                if (op[j] == 'L') {
                    lastL = j; // 更新最后一个 'L' 的位置
                }
            }
            if (lastL != -1) {
                bool bad = check(start, lastL);
                badCnt += !bad;
                pairs.emplace_hint(pairs.end(), start, bad); // 将区间 [start, lastL] 加入集合
            } else {
                throw ("error4");
            }
            return lastL;
        }
        throw ("error1");
        return -1;
    };

    for (int i = 0; i < N; ++i) {
        i = find(i);
    }
    pairs.emplace_hint(pairs.end(), N, true);

    auto modify = [&](int pos) -> void {
        char p = op[pos];
        if (p == 'R') {
            op[pos] = 'L';
            if (op[pos - 1] == 'R' && op[pos + 1] == 'L') {
                return;
            } // RRL -> RLL
            if (op[pos - 1] == 'R' && op[pos + 1] == 'R') {
                auto [it, _] = pairs.emplace(pos + 1, false);
                badCnt += !(it->second = check(pos + 1, next(it)->first - 1));
                if (prev(it)->second == false) badCnt--; // 清空前一个计数
                badCnt += !(prev(it)->second = check(prev(it)->first, pos));
                return;
            } // RRR -> RLR
            if (op[pos - 1] == 'L' && op[pos + 1] == 'L') {
                if (pairs[pos] == false) badCnt--;
                pairs.erase(pos); // 舍弃靠后的
                auto it = pairs.upper_bound(pos);
                if (prev(it)->second == false) badCnt--; // 清空前一个计数
                badCnt += !(prev(it)->second = check(prev(it)->first, it->first - 1)); // 重新检查前一个
                return;
            } // LRL -> LLL
            if (op[pos - 1] == 'L' && op[pos + 1] == 'R') {
                if (pairs[pos] == false) badCnt--;
                pairs.erase(pos); // 舍弃靠后的
                auto [it, _] = pairs.emplace(pos + 1, false); // 更新后一个的位置
                badCnt += !(it->second = check(pos + 1, next(it)->first - 1)); // 重新检查后一个
                if (prev(it)->second == false) badCnt--; // 清空前一个计数
                badCnt += !(prev(it)->second = check(prev(it)->first, pos)); // 重新检查前一个
                return;
            } // LRR -> LLR
            throw("errorR");
        } else {
            op[pos] = 'R';
            if (op[pos - 1] == 'R' && op[pos + 1] == 'L') {
                return;
            } // RLL -> RRL
            if (op[pos - 1] == 'R' && op[pos + 1] == 'R') {
                if (pairs[pos + 1] == false) badCnt--;
                pairs.erase(pos + 1); // 舍弃靠后的
                auto it = pairs.upper_bound(pos);
                if (prev(it)->second == false) badCnt--; // 清空前一个计数
                badCnt += !(prev(it)->second = check(prev(it)->first, it->first - 1)); // 重新检查前一个
                return;
            } // RLR -> RRR
            if (op[pos - 1] == 'L' && op[pos + 1] == 'L') {
                auto [it, _] = pairs.emplace(pos, false);
                badCnt += !(it->second = check(pos, next(it)->first - 1));
                if (prev(it)->second == false) badCnt--; // 清空前一个计数
                badCnt += !(prev(it)->second = check(prev(it)->first, pos - 1));
                return;
            } // LLL -> LRL
            if (op[pos - 1] == 'L' && op[pos + 1] == 'R') {
                if (pairs[pos + 1] == false) badCnt--;
                pairs.erase(pos + 1); // 舍弃靠后的
                auto [it, _] = pairs.emplace(pos, false); // 更新后一个的位置
                badCnt += !(it->second = check(pos, next(it)->first - 1)); // 重新检查后一个
                if (prev(it)->second == false) badCnt--; // 清空前一个计数
                badCnt += !(prev(it)->second = check(prev(it)->first, pos - 1)); // 重新检查前一个
                return;
            } // LLR -> LRR
            throw("errorL");
        }
    };

    //LOG(badCnt)
    while (Q--) {
        int dif;
        std::cin >> dif;
        modify(dif - 1);
        //LOG(badCnt)
        std::cout << (badCnt == 0 ? "YES" : "NO") << std::endl;
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}