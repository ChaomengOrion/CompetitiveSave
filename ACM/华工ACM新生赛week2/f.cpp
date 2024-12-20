#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<set>

using i64 = long long;

int expand(const std::string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }
    return (right - left - 2) / 2;
}

int cal(std::string s) {
    int sizes = s.size();
    s;
    int start = 0, end = -1;
    std::string t = "";
    for (char c : s) {
        t += c;
        t += '#';
    }
    s = "";
    t = '#' + t + t + t + '#';

    std::vector<int> arm_len;
    int right = -1, j = -1;
    for (int i = 0; i < t.size(); ++i) {
        int cur_arm_len;
        if (right >= i) {
            int i_sym = j * 2 - i;
            int min_arm_len = std::min(arm_len[i_sym], right - i);
            cur_arm_len = expand(t, i - min_arm_len, i + min_arm_len);
        }
        else {
            cur_arm_len = expand(t, i, i);
        }
        arm_len.push_back(cur_arm_len);
        if (i + cur_arm_len > right) {
            j = i;
            right = i + cur_arm_len;
        }
        cur_arm_len = std::min(cur_arm_len, sizes - 1);
        if (cur_arm_len * 2 + 1 > end - start) {
            start = i - cur_arm_len;
            end = i + cur_arm_len;
        }
    }

    //std::string ans;
    //std::cout << start << " | " << end << std::endl;
    //std::cout << (end - start) / 2 + 1 << std::endl;
    //std::cout << sizes << std::endl;
    int cnt = 0;
    for (int i = start; i <= end; ++i) {
        if (t[i] != '#') {
            cnt++;
        }
    }
    return cnt;
}

void solve() {
	std::string s;
	std::cin >> s;
    std::cout << cal(s);
}

int main() {
	solve();
	return 0;
}
