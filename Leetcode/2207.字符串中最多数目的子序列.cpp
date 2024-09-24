/*
 * @lc app=leetcode.cn id=2207 lang=cpp
 *
 * [2207] 字符串中最多数目的子序列
 */
#include <bits/stdc++.h>
// @lc code=start
class Solution
{
public:
    long long maximumSubsequenceCount(std::string text, std::string pattern)
    {
        std::cin.tie(0)->sync_with_stdio(0);
        char p0 = pattern[0], p1 = pattern[1];
        unsigned int cnt[2] = {0, 0};
        long long sum = 0;
        for (char c : text) {
            if (c == p0) {
                cnt[0]++;
            } else if (c == p1) {
                sum += cnt[0];
                cnt[1]++;
            }
        }
        return p0 != p1 ? sum + cnt[cnt[0] < cnt[1]] : ((long long)cnt[0] + 1) * cnt[0] / 2;
    }
};
// @lc code=end
