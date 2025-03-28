using i64 = long long;

i64 binpow(i64 a, i64 b) {
    // a %= m;
    i64 res = 1;
    while (b > 0) {
        if (b & 1) res = res * a; // % m;
        a = a * a; // % m;
        b >>= 1;
    }
    return res;
}

i64 f(i64 n, i64 m) {
    // 求的是m个n相乘，这里n是一个正整数
    if (m == 0)
        return 1;
    else if (m == 1)
        return n;
    else if (m % 2 == 0)
        return f(n * n, m / 2); // 偶数时的降幂
    return f(n * n, m / 2) * n; // 奇数时的降幂
}