#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

void solve() {
    int N;
    std::cin >> N;
    std::map<std::string, int> pental;
    std::map<std::string, std::map<std::string, int>> pentalR;
    std::map<std::string, std::set<std::string>> passed;
    for(int i = 0; i < N; i++) {
        std::string name, id;
        int pass, time;
        std::cin >> name >> id >> pass >> time;
        if (pass && !passed[name].count(id)) {
            passed[name].emplace(id);
            pental[name] += time + pentalR[name][id];
        } else {
            pentalR[name][id] += 20;
        }
    }

    int maxCnt = -1;
    for (auto [k, v] : passed) {
        maxCnt = std::max((int)v.size(), maxCnt);
    }
    int minPental = INT_MAX;
    std::string min_name;
    for (auto [k, v] : passed) {
        if ((int)v.size() == maxCnt) {
            int pe = pental[k];
            if (pe < minPental) {
                minPental = pe;
                min_name = k;
            }
        }
    } 

    std::cout << min_name << " " << passed[min_name].size() << " " << pental[min_name] << std::endl;
    
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}