#include <bits/stdc++.h>

using i64 = long long;

bool ask(int a, int b)
{ // 包括0
    std::cout << "? " << a << ' ' << b << std::endl;
    std::cout.flush();
    int res;
    std::cin >> res;
    assert(res != -1);
    return res;
}

void solve()
{
    int N;
    std::cin >> N;
    std::vector<int> parents(N);
    parents[1] = 0;
    int i = 2;
    std::vector<int> roots;
    roots.push_back(1);
    for (; i < N; i++) {
        parents[i] = !ask(1, i);
        if (parents[i] == 1) {
            roots[0] = i;
            i++;
            break;
        } else {
            roots.push_back(i);
        }
    }
    int maxp = 1, rtSize = roots.size(), lastR = 0;
    for (; i < N; i++) {
        bool find = false;
        for (int r = lastR + 1; r != lastR; r++) {
            if (r == rtSize) {
                r = -1;
                continue;
            }
            int rt = roots[r];
            if (rt < maxp) continue;
            if (!ask(rt, i)) {
                parents[i] = rt;
                maxp = parents[i];
                roots[r] = i;
                lastR = r;
                find = true;
                break;
            }
        }

        if (!find) {
            parents[i] = roots[lastR];
            maxp = parents[i];
            roots[lastR] = i;
        }
    }

    std::cout << "! ";
    for (int i = 1; i < N; i++) {
        std::cout << parents[i] << ' ';
    }
    std::cout << std::endl;
    std::cout.flush();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}