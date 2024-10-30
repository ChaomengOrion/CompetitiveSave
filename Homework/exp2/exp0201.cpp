#include <bits/stdc++.h>

using i64 = long long;

i64 binpow(i64 a, i64 b)
{
    if (b == 0) return 1;
    i64 res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

int main(){
    int T;
    std::cin >> T;
    while (T--) {
        i64 n;
        std::cin >> n;
        i64 temp = n;
        i64 sum = 0;
        int digit = 0;
        while (temp > 0) {
            temp /= 10;
            digit++;
        }
        temp = n;
        while (temp > 0) {
            short cur = temp % 10;
            temp /= 10;
            sum += binpow(cur, digit);
        }
        std::cout << ((n == sum) ? 'T' : 'F') << std::endl;
    }
}