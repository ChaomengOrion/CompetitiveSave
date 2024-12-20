#include<bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::string> map(n);
	for (int i = 0; i < n; i++) {
		std::cin >> map[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < map[i].size(); j++) {
			std::cout << (map[i][j] == 'x' ? '_' : 'x');
		}
		std::cout << '\n';
	}	
}

int main() {
	solve();
	return 0;
} 
