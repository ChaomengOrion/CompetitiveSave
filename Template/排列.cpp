#include <bits/stdc++.h>
#define LOGV(vec, size) std::cout << #vec << " = " << '['; for (int i = 0; i < size; i++) { std::cout << vec[i]; if (i != size - 1) std::cout << ", "; } std::cout << ']' << std::endl;

void p(std::vector<int>& source, std::function<void(std::vector<int>&)> callback) {
    std::sort(source.begin(), source.end());
    int n = source.size();
    std::vector<bool> visited(n, false);
    std::vector<int> cur = source;
    auto dfs = [&](auto&& dfs, int s) -> void {
        if (s == n) {
            callback(cur);
            return;
        }
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (i > 0 && source[i] == last) continue;
            if (!visited[i]) {
                visited[i] = true;
                last = cur[s] = source[i];
                dfs(dfs, s + 1);
                visited[i] = false;
            }
        }
    };
    dfs(dfs, 0);
}

int main() {
    std::vector<int> source = {5, 2, 2, 3, 2};
    p(source, [&](std::vector<int>& cur) {
        LOGV(cur, source.size());
    });
}