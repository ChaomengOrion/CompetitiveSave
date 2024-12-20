#include <bits/stdc++.h>

std::map<std::string, int> ts = {
	{"1m",0},
	{"9m",0},
	{"1p",0},
	{"9p",0},
	{"1s",0},
	{"9s",0},
	{"1z",0},
	{"2z",0},
	{"3z",0},
	{"4z",0},
	{"5z",0},
	{"6z",0},
	{"7z",0}
};

void solve() {
	std::string s;
	std::cin >> s;
	std::map<std::string, int> cnt = ts;
	for (int i = 0; i < s.size(); i += 2) {
		std::string cur = s.substr(i, 2);
		if (cnt.find(cur) != cnt.end()) {
			cnt[cur]++;
		}
	}
	bool has2 = false;
	std::vector<std::string> need;
	for (auto [k, v] : cnt) {
		if (v == 0) {
			need.push_back(k);
		}
		if (v >= 2) has2 = true;
	}
	if (need.size() >= 2) {
		std::cout << "NO" << std::endl;
	} else if (need.size() == 1) {
		if (has2) {
			std::cout << "YES" << std::endl;
			std::cout << need[0] << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
	} else {			
		std::cout << "YES" << std::endl;
		for (auto [k, v] : cnt) {
			std::cout << k << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	solve();
}
