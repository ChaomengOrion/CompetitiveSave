#include <bits/stdc++.h>

using i64 = long long;

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        std::cin >> seq[i];
    }
    std::string s;
    std::cin >> s;

    int id = 0;
    std::unordered_map<int, int> k2id;
    std::unordered_map<int, int> id2black;
    auto deal = [&](auto deal, int endk, int k) {
        //std::cout << "endK:" << endk << ", K:" << k << std::endl;
        if (k == endk) return;
        k2id[k] = id;
        int nextK = seq[k-1];
        deal(deal, endk, nextK);
    };
    for (int k = 1; k <= n; k++) {
        if (k2id.contains(k)) continue;
        if (seq[k-1] == k) {
            k2id[k] = id;
            id++;
        }
        else {
            k2id[k] = id;
            deal(deal, k, seq[k-1]);
            id++;
        }
    }
    for (int k = 1; k <= n; k++) {
        if (s[k-1] == '0')
        {
            id2black[k2id[k]]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        std::cout << id2black[k2id[i]] << ' ';
    }
    std::cout << std::endl;
    /*for (auto [k, id] : k2id) {
        DEBUGI(k, id)
    }
    std::cout << "====" << std::endl;
    
    for (auto [id, black] : id2black) {
        DEBUGI(id, black)
    }*/
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) solve();

    return 0;
}