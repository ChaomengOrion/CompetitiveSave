/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 区间加法 II
 */
#include <bits/stdc++.h>
// @lc code=start
class Solution {
public:
    int maxCount(int m, int n, std::vector<std::vector<int>>& ops) {
        for (int i = 0; i < ops.size(); i++) {
            n = std::min(n, ops[i][1]);
            m = std::min(m, ops[i][0]);
        }
        return m * n;
    }
};
// @lc code=end

