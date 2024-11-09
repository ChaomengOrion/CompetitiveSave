#include <bits/stdc++.h>

using i64 = long long;

i64 sum(std::string& s, i64 mask, i64 n) {
	i64 add = 0;
	i64 last = 0;
	for (i64 pos = 0; pos < n - 1; pos++) {
		if ((mask & (1 << pos)) != 0) {
			add += std::stoll(s.substr(last, pos - last + 1));
			last = pos + 1;
		}                          
	}
	add += std::stoll(s.substr(last));
	return add;
}

void solve() {
	std::string s;
	std::cin >> s;
	i64 m = (1 << (s.size() - 1)) - 1;
	i64 add = 0;
	for (int i = m; i >= 0; i--) {
		add += sum(s, i, s.size());
	}
	std::cout << add << std::endl;
}

int main() {
	solve();
}
