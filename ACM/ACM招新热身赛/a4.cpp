#include <bits/stdc++.h>

void solve() {
	int N, X, Y;
	std::cin >> N >> X >> Y;
	int K = X + Y - (N + 1);
	int best = (K < 0) ? 1 : N - std::max(0, N - X - 1) - std::max(0, N - Y - 1) - (N - X >= 1 && N - Y >= 1);
	int worst = (K < 0) ? X - 1 + Y - 1 + 1 : N;
	std::cout << best << ' ' << worst << std::endl;
}

int main() {
	solve();
}
