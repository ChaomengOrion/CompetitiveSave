#include <bits/stdc++.h>

struct range {
    int l, r;
    bool enable;

    int size() const {
        return enable ? r - l + 1 : 0;
    }
};

void solve() {
    int N, M, Q; //* N, M - 1e9 | Q - 2e5
    std::cin >> N >> M >> Q;
    
    range rL = {1, 0, false}, rMid = {M, M, true}, rR = {N + 1, N, false};
    while (Q--) {
        int X; std::cin >> X;

        if (rL.enable && X <= rL.r) {
            if (rMid.enable) rMid.l--;
            if (rR.enable) rR.l--;
        } else if (rR.enable && rR.l <= X) {
            if (rMid.enable) rMid.r++;
            if (rL.enable) rL.r++;
        } else if (rMid.enable && rMid.l <= X && X <= rMid.r) {
            rR.l--;
            rL.r++;
            rL.enable = rR.enable = true;
            if (rMid.size() == 1) rMid.enable = false;
        } else if (!rMid.enable) {
            if (rR.enable) rR.l--;
            if (rL.enable) rL.r++;
        } else if (rL.r < X && X < rMid.l) {
            if (rMid.enable) rMid.l--;
            if (rR.enable) rR.l--;
            if (rL.enable) rL.r++;
        } else {
            if (rMid.enable) rMid.r++;
            if (rR.enable) rR.l--;
            if (rL.enable) rL.r++;
        }

        if (rMid.enable && rL.r >= rMid.l) {
            rMid.enable = false;
            rL.r = rMid.r;
        }

        if (rMid.enable && rR.l <= rMid.r) {
            rMid.enable = false;
            rR.l = rMid.l;
        }

        if (rR.enable && rL.r >= rR.l) {
            rR.enable = false;
            rL.r = N;
        }

        std::cout << rL.size() + rMid.size() + rR.size() << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}