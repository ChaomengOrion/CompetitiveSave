#include <bits/stdc++.h>

void solve() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    
    std::map<int, int> cnt;
    std::set<int> ones;

    for (int i = 0; i < K; i++) {
        cnt[arr[i]]++;
        if (cnt[arr[i]] == 1) ones.insert(arr[i]);
        else if (cnt[arr[i]] == 2) ones.erase(arr[i]);
    }
    if (!ones.empty()) std::cout << *prev(ones.end()) << ' ';
    else std::cout << -1 << std::endl;
    for (int i = K; i < N; i++) {
        int f = i - K;
        cnt[arr[f]]--;
        if (cnt[arr[f]] == 1) ones.insert(arr[f]);
        else if (cnt[arr[f]] == 0) ones.erase(arr[f]);
        cnt[arr[i]]++;
        if (cnt[arr[i]] == 1) ones.insert(arr[i]);
        else if (cnt[arr[i]] == 2) ones.erase(arr[i]);
        if (!ones.empty()) std::cout << *prev(ones.end()) << ' ';
        else std::cout << -1 << std::endl;
    }
}

int main() {
    solve();
}