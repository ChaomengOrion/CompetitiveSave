#include<vector>
#include<string>
#include<iostream>

using i64 = long long;

void solve() {
	i64 n, x, y, a, b;
	std::cin >> n >> x >> y >> a >> b;
	// 8 2 3 1 5
	if (((n % x == 0 && (n + a) % y == 0) || (n % y == 0 && (n + b) % x == 0)) 
		&& (
			((a + b) % x == 0 && (a + b) % y == 0) || a % x == 0 || b % y == 0 
		)) {
		std::cout << "baka" << std::endl;
		return;
	}

	if ((n % x == 0 && a % x == 0) || (n % y == 0 && b % y == 0)) {
		std::cout << "baka" << std::endl;
		return;
	}

	i64 max = 0;
	bool baka = false;
	auto dfs = [&](auto&& dfs, i64 num) -> void {
		max = std::max(max, num);
		if (num % x == 0) {
			dfs(dfs, num + a);
		}
		if (num % y == 0) {
			dfs(dfs, num + b);
		}
	};
	dfs(dfs, n);
	std::cout << max << std::endl;
}

int main() {
	int t;
	std::cin >> t;
	while(t--) solve();
	return 0;
}
