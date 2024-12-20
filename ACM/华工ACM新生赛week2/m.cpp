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
		seq[i]--;
	}
	int opcnt = 0;
	for (int i = 1; i < n; i++)
	{
		int last = (seq[i - 1] + opcnt) % 4;
		int cur = (seq[i] + opcnt) % 4;
		opcnt += (last + 4 - cur) % 4;
	}
	std::cout << opcnt << '\n';
}

int main() {
	solve();
	return 0;
}
