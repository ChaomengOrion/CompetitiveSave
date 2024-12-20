#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "DEBUG: " << __VA_ARGS__ << std::endl;

/*①打击：对敌人造成 6 点伤害；
②强化：接下来的 2 回合，如果有打击操作，打击的伤害变为 9 ；
③闪电：生成一个闪电球，每回合对敌人造成伤害（包括这回合），伤害为当前闪电球的基础伤害值
（闪电球最初的伤害值为 3 ）；
④集中：闪电球的基础伤害 +2（包括后面还未生成的闪电球）；
（注：机器人初始没有闪电球，闪电球生成后会一直存在，且闪电球可以叠加）。
求n次操作后机器人对敌人造成的伤害是多少。*/

void solve() {
    int N;
    std::cin >> N;
    
    i64 ans = 0;
    bool isBoost = false;
    int lastBoost = -1;
    int bollD = 3;
    int bollCnt = 0;
    for(int i = 0; i < N; i++) {
        if (i - lastBoost > 2) isBoost = false;
        int op;
        std::cin >> op;
        if (op == 1) {
            ans += isBoost ? 9 : 6;
        } else if (op == 2) {
            isBoost = true;
            lastBoost = i;
        } else if (op == 3) {
            bollCnt++;
        } else {
            bollD += 2;
        }

        ans += bollCnt * bollD;
    }
    
    std::cout << ans << std::endl;
    
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}