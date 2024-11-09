#include <bits/stdc++.h>

bool isPrime(long long num) {
	if (num == 1) return 0;
	if (num == 2 || num == 3) return 1;
	if (num % 6 != 1 && num % 6 != 5) return 0;
	int tmp = sqrt(num);
	for (int i = 5; i <= tmp; i += 6) {
		if (num % i == 0 || num % (i + 2) == 0) return 0;
	}
	return 1;
}

void solve() {
	long long N;
	std::cin >> N;
	long long cur = 3;
	long long a = -1, b = -1;
	while(true) {
		if (!isPrime(cur)) {
			cur++;
			continue;
		}
		a = cur;
		b = cur ^ N;
		if (a > 1 && b > 1 && !isPrime(b)) {
			break;
		}
		cur++;
	}
	
	std::cout << a << ' ' << b << std::endl;
}

int main() {
	int t;
	std::cin >> t;
	while(t--) solve();
}
