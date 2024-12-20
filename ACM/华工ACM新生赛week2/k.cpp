#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<set>

using i64 = long long;

void solve() {
	int N, C;
	std::cin >> N >> C;
	std::map<int, int> times;
	for (int i = 0; i < N; i++)
	{
		int s, h, d;
		std::cin >> s >> h >> d;
		int p = s + h / d - 1;
		times[p]++;
	}
	//int max = 0;
	/*auto dfs = [&](auto&& dfs, int cur, int pre_cnt) -> void {
		auto it = times.lower_bound(cur);
		if (it == times.end()) {
			max = std::max(max, pre_cnt);
			return;
		}
		auto [t, cnt] = *it;
		dfs(dfs, t + 1, pre_cnt);
		if (C > 1) dfs(dfs, t + C, pre_cnt + cnt);
	};
	dfs(dfs, 1, 0);*/
	int max = 0;
	std::map<int, int> dp = times;
	for (auto [t, cnt] : times) {
		cnt = 1;
		auto itl = dp.upper_bound(t - C);
		auto itc = dp.find(t);
		if (itl != dp.begin() && itc != dp.begin()) {
			auto [lt, lmax] = *prev(itl);
			auto [rt, rmax] = *prev(itc);
			dp[t] = std::max(rmax, lmax + cnt);
		}
		else if (itc != dp.begin()) {
			auto [rt, rmax] = *prev(itc);
			dp[t] = std::max(rmax, cnt);
		} else {
			dp[t] = cnt;
		}
		max = std::max(max, dp[t]);
	}
	std::cout << max << '\n';
}

int main() {
	solve();
	return 0;
}
