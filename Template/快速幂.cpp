using i64 = long long;
i64 binpow(i64 a, i64 b)
{
    // a %= m;
    i64 res = 1;
    while (b > 0) {
        if (b & 1) res = res * a; // % m;
        a = a * a; // % m;
        b >>= 1;
    }
    return res;
}