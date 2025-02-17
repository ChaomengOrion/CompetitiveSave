#include <bits/stdc++.h>
using i64 = long long;

static const i64 INF = 1e15;

// 对单个数字做 BFS，返回 (cost -> minimalValue) 的所有可能状态
std::vector<std::pair<int, i64>> getStates(i64 x, const std::vector<i64> &b, int k) {
    // key: 值 -> val: 最小花费
    std::unordered_map<i64,int> visited;
    std::queue<std::pair<i64,int>> q;
    q.push({x,0});
    visited[x] = 0;

    // (cost, minimalValue)
    std::vector<std::pair<int,i64>> result;
    result.push_back({0, x});

    while(!q.empty()){
        auto [val, cost] = q.front();
        q.pop();
        if(cost == k) continue;
        for(auto &magic : b){
            i64 nval = val & magic;
            int ncost = cost + 1;
            if(!visited.count(nval) || visited[nval] > ncost){
                visited[nval] = ncost;
                q.push({nval,ncost});
                result.push_back({ncost, nval});
            }
        }
    }

    // 按 cost 升序，再按 val 升序
    std::sort(result.begin(), result.end(), [](auto &p1, auto &p2){
        if(p1.first != p2.first) return p1.first < p2.first;
        return p1.second < p2.second;
    });

    // 压紧：对同一 cost 仅保留最小 val
    std::vector<std::pair<int,i64>> compressed;
    int prevC = -1;
    i64 bestV = INF;
    for(auto &rr : result){
        if(rr.first != prevC){
            if(prevC != -1) compressed.push_back({prevC,bestV});
            prevC = rr.first;
            bestV = rr.second;
        } else {
            bestV = std::min(bestV, rr.second);
        }
    }
    if(prevC != -1) compressed.push_back({prevC,bestV});
    return compressed;
}

void solve(){
    int n,m; 
    i64 k;
    std::cin >> n >> m >> k;
    std::vector<i64> a(n), b(m);
    for(auto &x : a) std::cin >> x;
    for(auto &x : b) std::cin >> x;

    i64 baseSum = 0;
    for(auto x : a) baseSum += x;

    std::vector<std::vector<std::pair<int,i64>>> states(n);
    for(int i=0;i<n;i++){
        states[i] = getStates(a[i], b, (int)k);
    }

    std::vector<i64> dp(k+1, -1);
    dp[0] = 0;
    for(int i=0;i<n;i++){
        std::vector<i64> tmp(dp);
        i64 origVal = a[i];
        for(auto &p : states[i]){
            int subCost = p.first;
            i64 newVal = p.second;
            i64 delta = origVal - newVal;
            for(int c=0; c+subCost <= k; c++){
                if(dp[c] != -1){
                    i64 &t = tmp[c + subCost];
                    if(t < dp[c] + delta) t = dp[c] + delta;
                }
            }
        }
        dp.swap(tmp);
    }

    i64 bestDec = 0;
    for(int c=0;c<=k;c++){
        bestDec = std::max(bestDec, dp[c]);
    }
    std::cout << (baseSum - bestDec) << "\n";
}

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t; std::cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}