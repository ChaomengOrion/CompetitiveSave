#include<bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> map(n);
	for (int i = 0; i < n; i++) {
		std::cin >> map[i];
	}
	std::cout << *max_element(map.begin(), map.end()) - *min_element(map.begin(), map.end()) << std::endl;
}

int main() {
	solve();
	return 0;
} 
