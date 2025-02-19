/// FileName: G_Skibidus_and_Capping.cpp
/// Date: 2025/02/10
/// Author: ChaomengOrion

#include <bits/stdc++.h>

using i64 = long long;

/*
* 把每个数质因数分解为{A}或{A B} (A <= B)，超过的舍弃
* 配对只有四种情况：
* (1) {A B} - {A B} -> lcm = {A B}
* (2) {A B} - {A} -> lcm = {A B}
* (3) {A B} - {B} -> lcm = {A B}
* (4) {A} - {B} -> lcm = {A B} (特别的，A != B)
? 预处理每一个{X}的数量和每一个{A B}的数量
? 计算(4)可以直接算全部{X}的组合数量
? 计算(1)可以对每一个{A B}的内部组合（包括自己选两个）算数量
? 计算(2)/(3)可以遍历{A B}，然后去{X}里面找{A}/{B}有几个
*/
void solve() {
    int N; std::cin >> N;
    std::map<int, int> cnt1;
    std::map<std::pair<int, int>, int> cnt2;
    for (int t = 0; t < N; t++) {
        int temp; std::cin >> temp;
        std::array<int, 2> primes;
        char cnt = 0;
        for (int i = 2; i * i <= temp; i++) {
            while (temp % i == 0) {
                if (cnt == 2) goto CONT;
                temp /= i;
                primes[cnt++] = i;
            }
        }
        if (temp > 1) {
            if (cnt == 2) continue;
            primes[cnt++] = temp;
        }
        if (cnt == 1) cnt1[primes[0]]++;
        else cnt2[{primes[0], primes[1]}]++;
    CONT:
        continue;
    }
    i64 ans = 0;
    //* 计算(4)
    {
        int sum1 = 0;
        for (auto [k, v] : cnt1) {
            sum1 += v;
        }
        for (auto [k, v] : cnt1) {
            ans += 1LL * (sum1 - v) * v;
        }
        ans /= 2;
    }
    //* 计算(1) + (2)/(3)
    for (auto [k, v] : cnt2) {
        ans += 1LL * v * (v - 1) / 2 + v;
        auto [a, b] = k;
        if (cnt1.contains(a)) {
            ans += 1LL * v * cnt1[a];
        }
        if (b != a && cnt1.contains(b)) {
            ans += 1LL * v * cnt1[b];
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}