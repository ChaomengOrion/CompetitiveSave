#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

const int MOD = 998244353;

template<typename T>
class TreeArray
{
private:
    int size;
    std::vector<T> arr;

public:
    TreeArray(int len) : size(len), arr(len + 1, 0) { }

    inline static int lowbit(int x) { return x & -x; }

    void add(int pos, T value)
    {
        if (pos < 1) return;
        value += MOD; value %= MOD;
        while (pos <= size) {
            arr[pos] += value;
            arr[pos] %= MOD;
            pos += lowbit(pos);
        }
    }

    i64 query(int pos)
    {
        i64 sum = 0;
        while (pos >= 1) {
            sum += arr[pos];
            sum %= MOD;
            pos -= lowbit(pos);
        }
        return sum;
    }

    i64 query(int l, int r) { return (query(r) - query(l - 1) + MOD) % MOD; }

    [[maybe_unused]] void debug() {
        std::cerr << "BIT: [";
        for (int i = 1; i <= size; i++) {
            std::cerr << query(i, i) << ", ";
        }
        std::cerr << "]\n";
    }
};

/*
开始看错题了。。看成子数组，前缀和作差整理公式即可

!从线性dp角度
? 动态规划
* cnt[i][0] / sum[i][0]是 —— 前i个中以0结尾的子序列的 数量/f和
* cnt[i][1] / sum[i][1]是 —— 前i个中以1结尾的子序列的 数量/f和
? 状态转移：

* 如果S[i]==0:
* sum[i][0] = sum[i-1][0]                xxxx0
*           + sum[i-1][0]                xxxx0 + 0
*           + 1                          只包括当前一个0
*           + cnt[i-1][1] + sum[i-1][1]  xxxx1 + 0
* cnt[i][0] = cnt[i-1][0]                xxxx0
*           + cnt[i-1][0]                xxxx0 + 0
*           + 1                          只包括当前一个0
*           + cnt[i-1][1]                xxxx1 + 0

* 如果S[i]==1:
* sum[i][0] = sum[i-1][0]
* cnt[i][0] = cnt[i-1][0]

* 1 同理
? 考虑修改
* 反转S[x]导致dp[x..]要重新计算，dp[..x]不受影响，一个一个算肯定超时，不会了

!从贡献角度
? 首先每个子序列固定产生1的贡献, ans += 2^N - 1
? 对于每一对S[i]!=S[j]的(i,j)，每有一个子序列包含了(i,j)且(i,j)在子序列中连续，那么ans += 1
* 固定(i,j)后，只需要确定xx->(i,j)<-xx有多少个，xx的数量可以直接组合数计算得到（就是子集数量2^(i-1)*2^(N-j)）
* 考虑枚举j，那么只需要找前面不一样的i，加上2^(i-1)，最后一起乘以2^(N-j)
* 但是这样复杂度还是O(N^2)的
* 再次注意到是二进制字符串，只需要考虑01就行了，那么可以只枚举一个维度j，同时记录j前面0/1的贡献和
* 当前S[j]是0，就找前面1的贡献（前面每一个1的2^(i-1)的和）。动态规划，可以O(N)计算出结果
? 考虑修改
* 每次修改位置x，考虑x作为i位置和x作为j位置
* 如果S[j]是0
* 作为j位置时，原来的贡献是x前面所有1的2^(i-1)的和乘以2^(N-j)，新的贡献是0的对应和乘以2^(N-j)
* 作为i位置时，原来的贡献是x后面所有1的2^(N-j)的和乘以2^(i-1)，新的贡献是0的对应和乘以2^(i-1)
* 维护四个树状数组，记录某位置前/后的0/1的这个贡献，方便查询贡献和以及单点修改
* 复杂度 O(N + Q * log(N))
*/

std::vector<int> pw2(2E5 + 1);

void pre() {
    pw2[0] = 1;
    for (int i = 1; i < (int)pw2.size(); i++) {
        pw2[i] = pw2[i - 1] * 2 % MOD;
    }
}

void solve() {
    std::string S;
    std::cin >> S;
    int N = S.size();
    S = '#' + S;
    
    TreeArray<i64> L0(N), L1(N), R0(N), R1(N);

    for (int i = 1; i <= N; i++) {
        if (S[i] == '0') {
            L0.add(i, pw2[i - 1]);
            R0.add(i, pw2[N - i]);
        } else {
            L1.add(i, pw2[i - 1]);
            R1.add(i, pw2[N - i]);
        }
    }

    i64 ans = pw2[N] - 1;

    for (int i = 1; i <= N; i++) {
        if (S[i] == '0') {
            ans += L1.query(i - 1) * pw2[N - i] % MOD;
        } else {
            ans += L0.query(i - 1) * pw2[N - i] % MOD;
        }
        ans %= MOD;
    }

    auto modify = [&](int x) -> void {
        auto [l0, r0, l1, r1] = 
            S[x] == '0' ?
            std::tie(L0, R0, L1, R1)
            :
            std::tie(L1, R1, L0, R0);

        S[x] ^= 1;
        ans += MOD; 
        ans -= l1.query(x - 1) * pw2[N - x] % MOD;
        ans %= MOD;
        ans += l0.query(x - 1) * pw2[N - x] % MOD;
        ans %= MOD;
        
        ans += MOD;
        ans -= pw2[x - 1] * r1.query(x + 1, N) % MOD;
        ans %= MOD;
        ans += pw2[x - 1] * r0.query(x + 1, N) % MOD;
        ans %= MOD;
        l0.add(x, -pw2[x - 1]);
        l1.add(x, pw2[x - 1]);
        r0.add(x, -pw2[N - x]);
        r1.add(x, pw2[N - x]);
    }; 

    int Q;
    std::cin >> Q;
    while (Q--) {
        int x;
        std::cin >> x;
        modify(x);
        std::cout << ans << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    pre();
    int t; std::cin >> t; while (t--) solve();
    return 0;
}