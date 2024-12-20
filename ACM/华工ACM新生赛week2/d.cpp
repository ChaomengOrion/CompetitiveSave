#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> seq(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> seq[i];
	}
	std::set<int> need;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int cur = seq[i];
		auto it = need.find(cur);
		if (it != need.end()) {
			need.erase(it);
		}
		else {
			need.insert(cur);
		}
		if (need.size() == 0) {
			cnt++;
		}
	}
	std::cout << cnt << '\n';
}

int main() {
	solve();
	return 0;
}
