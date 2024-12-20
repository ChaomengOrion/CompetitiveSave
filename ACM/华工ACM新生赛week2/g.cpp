#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<set>

using i64 = long long;

bool tryDiv(int m, int n, int t) {
	if (n == 1) {
		return t <= m;
	}
	for (int i = m; i >= 2; i--)
	{
		if (t % i == 0 && tryDiv(m, n - 1, t / i)) return true;
	}
	return false;
}

bool canDiv(int time, int target) {
	if (time == 1 || time == 2) return target == 1;
	time--;
	for (int i = time - 1; i >= 1; i--)
	{
		if (tryDiv(i, time - i, target)) return true;
	}
	return false;
}

bool isDiv(int time, int target) {
	if (canDiv(time, target)) return true;
	else {
		for (int cur = 1; cur <= target - 1; cur++)
		{
			for (int t = 1; t <= time - 1; t++)
			{
				if (canDiv(t, cur) && isDiv(time - t, target - cur)) {
					return true;
				}
			}
		}
	}
	return false;
}

void solve() {
	int N, T;
	std::cin >> N >> T;
	while (N--) {
		int h;
		std::cin >> h;
		
		int ok = isDiv(T, h);
		std::cout << ok << '\n';
	}
}

int main() {
	solve();
	return 0;
}
