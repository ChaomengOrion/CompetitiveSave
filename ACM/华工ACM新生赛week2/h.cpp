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
	int n;
	std::cin >> n;
	std::vector<std::set<int>> to(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		std::cin >> u >> v;
		to[u].insert(v);
		to[v].insert(u);
	}
	bool ok = false;
	for (int i = 1; i <= n; i++) {
		if (to[i].size() < n / 2) continue;
		//std::cout << "In i:" << i << '\n';

		std::multiset<int> deg;
		for (int edge : to[i]) {
			deg.insert(to[edge].size());
		}
		int cnt = 1;
		while (!deg.empty()) {
			deg.erase(prev(deg.end()));
			if (deg.empty()) break;
			cnt++;
			auto last = prev(deg.end());
			int la = *last;
			deg.erase(last);
			if (la > 1) {
				deg.insert(la - 1);
			}
		}
		//std::cout << "CNT:" << cnt << '\n';
		if (cnt >= n / 2) {
			ok = true;
			break;
		}
	}
	std::cout << (ok ? "Alice" : "Bob") << std::endl;
}

int main() {
	int t;
	std::cin >> t;
	while (t--) solve();
	return 0;
}
