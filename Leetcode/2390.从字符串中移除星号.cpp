/*
 * @lc app=leetcode.cn id=2390 lang=cpp
 *
 * [2390] 从字符串中移除星号
 */
#include <bits/stdc++.h>
// @lc code=start
class Solution {
public:
    std::string removeStars(std::string s) {
        std::cin.tie(nullptr)->sync_with_stdio(false);
        int len = s.size();
        int cnt = 0;
        std::stack<char> temp;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == '*') cnt++;
            else {
                if (cnt == 0) temp.push(s[i]);
                else cnt--;
            }
        }
        std::string ans;
        while (!temp.empty()) {
            ans += temp.top();
            temp.pop();
        }
        return ans;
    }
};
// @lc code=end

