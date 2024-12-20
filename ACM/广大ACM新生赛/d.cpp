#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) //std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

void solve() {
    i64 s, k, t1, t2;
    std::cin >> s >> k >> t1 >> t2;
    i64 m;// = (2LL + k*t2 - 1LL) / (k*t2);

    {
        i64 l = 0, r = 2e9;
        while (l < r) {
            i64 mid = (l + r + 1) >> 1;
            i64 left = t1 / t2;
            i64 right = (mid - 1) / 2 * t1 * k;
            LOG(left << " = " << right)
            if (left > right) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        m = l;
    }

    LOG(m)

    auto check = [&](i64 time) -> bool {
        LOG("----time = " << time)
        if (time < t1) return false;
        time -= t1;
        LOG("rtime = " << time)
        i64 need = s - time * k;
        LOG("need = " << need)
        if (need <= 0) return true;
        i64 tm = t1 * m;

        LOG("tm = " << tm)
        
        if (time < tm + t1) {
            LOG("All kill times:" << time / t2)
            return time / t2 >= need;
        } else {
            i64 build = (time - tm) / t1;
            i64 rtime = time - build * t1;
            need -= (build - 1) * build / 2 * t1 * k + build * rtime * k;
            LOG("Builds: " << build << "All kill times:" << rtime / t2)
            return rtime / t2 >= need;
        }
    };

    i64 l = 0, r = 2e9;
    while (l < r)
    {
        i64 mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    std::cout << l << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}