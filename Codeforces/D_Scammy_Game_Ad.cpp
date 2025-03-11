#include <bits/stdc++.h>

using i64 = long long;

struct gate {
    char type;
    i64 val;

    i64 get_new(i64 x) {
        if (type == '+') {
            return val;
        } else {
            return x * (val - 1);
        }
    }

    friend bool operator==(gate a, gate b) {
        return a.type == b.type && ((a.type == 'x' && a.val == b.val) || (a.type == '+'));
    }
    friend bool operator<(gate a, gate b) {
        if (a.type == b.type) {
            return a.val < b.val;
        }
        return b.type == 'x';
    }
};

//? +x +2x 优先走+2x
//? +1 +x 优先走+x
//? +1 +1 / +x +x / +2x +2x 优先往后找
void solve() {
    int N;
    std::cin >> N;
    std::vector<gate[2]> gates(N);
    for (int i = 0; i < N; i++) {
        std::cin >> gates[i][0].type >> gates[i][0].val;
        std::cin >> gates[i][1].type >> gates[i][1].val;
    }
    std::vector<int> big(N);
    big[N - 1] = gates[N - 1][0] < gates[N - 1][1];
    for (int i = N - 2; i >= 0; i--) {
        if (gates[i][0] == gates[i][1]) {
            big[i] = big[i + 1];
        } else {
            big[i] = gates[i][0] < gates[i][1];
        }
    }

    i64 last[2] = {1, 1};

    for (int i = 0; i < N; i++) {
        i64 add[2] = {0, 0};
        add[0] = gates[i][0].get_new(last[0]);
        add[1] = gates[i][1].get_new(last[1]);
        i64 sum = add[0] + add[1];

        if (i < N - 1) {
            if (big[i + 1] == 0) {
                last[0] += sum;
            } else {
                last[1] += sum;
            }
        } else {
            last[0] += sum;
        }
    }

    std::cout << last[0] + last[1] << '\n';
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; while (t--) solve();
    return 0;
}