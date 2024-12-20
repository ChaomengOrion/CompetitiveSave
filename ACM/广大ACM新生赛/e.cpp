#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) //std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

const int ESP = 100000;

void solve() {
    int L, v, K;
    std::cin >> L >> v >> K;
    int xa, xb;
    int ta, tb;
    std::cin >> xa >> ta >> xb >> tb;
    //xa *= 2000;
    //xb *= 2000;
    //L *= 2000;
    xa *= 2 * ESP;
    xb *= 2 * ESP;
    L *= 2 * ESP;
    LOG(xa << " " << xb)
    for(int t = 1; t <= K * 2 * ESP; t += 1) {
        i64 temp1 = 1LL * xa - xb;
        xa += ta * v;
        xb += tb * v;
        i64 temp2 = 1LL * xa - xb;
        if (temp1 * temp2 <= 0) {
            xa -= ta * v;
            xb -= tb * v;
            ta = -ta;
            tb = -tb;
            t+=1;
            continue;
        }
        if (xa <= 0) {
            ta = -ta;
            xa = -xa;
        }
        
        if (xb <= 0) {
            tb = -tb;
            xb = -xb;
        }
        
        if (xa >= L) {
            xa = L - (xa - L);
            ta = -ta;
        }

        if (xb >= L) {
            xb = L - (xb - L);
            tb = -tb;
        }

        LOG(xa << " " << xb)
    }
    std::cout << (int)roundl(xa / 2.0L / ESP) << " " <<  (int)roundl(xb / 2.0L / ESP) << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}