#include <bits/stdc++.h>

void solve() {
	std::string s[4];
	std::cin >> s[0] >> s[1] >> s[2] >> s[3];
	int pos[4] = {0, 0, 0, 0};
	int cur = 0;
	while (true) {
		int nxt = s[cur][pos[cur]] - 'a';
		if (pos[cur] >= s[cur].size()) break;
		pos[cur]++;
		cur = nxt;
	}
	std::string names[4] = {"Alice", "Bob", "Charlie", "David"};
	std::cout << names[cur] << std::endl;
}

int main() {
	solve();
}
