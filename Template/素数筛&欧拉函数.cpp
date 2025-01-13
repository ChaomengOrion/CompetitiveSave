#include <bits/stdc++.h>

bool isPrime(int num)
{
    if (num == 1) return 0;
    if (num == 2 || num == 3) return 1;
    if (num % 6 != 1 && num % 6 != 5) return 0;
    int tmp = sqrt(num);
    for (int i = 5; i <= tmp; i += 6)
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    return 1;
}

//* 埃氏筛 O(NloglogN)
void E_sieve(int N) {
    std::vector<bool> isP(N + 1, true);
    for (int i = 2; i <= N; i++) {
        if (!isP[i]) continue;
        for (int j = i * i; j <= N; j += i) {
            isP[j] = false;
        }
    }
    isP[0] = isP[1] = false;
}

//* 线性欧拉筛 O(N)
void euler_sieve(int N) {
    std::vector<int> prime(N + 1); //? 可小于 N，约lnN
    std::vector<bool> vis(N + 1);
    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (!vis[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt; j++) {
            if (i * prime[j] > N) break;
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 0; i < static_cast<int>(prime.size()); i++) {
        if (!prime[i]) {
            prime.resize(i);
            break;
        }
    }
}

//* 预处理求欧拉函数
void euler_pre(int N) {
    std::vector<int> phi(N + 1);
    std::iota(phi.begin() + 1, phi.end(), 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 2 * i; j <= N; j += i) {
            phi[j] -= phi[i];
        }
    }
}

int main() {
    euler_pre(11);
}