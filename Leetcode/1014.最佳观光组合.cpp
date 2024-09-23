/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 */
#include <bits/stdc++.h>
// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(std::vector<int>& values) {
        std::cin.tie(nullptr)->sync_with_stdio(false);
        unsigned long long len = values.size();
        int max_left_score = values[0], max_score = -1;
        for (int i = 1; i < len; i++) {
            max_left_score--;
            max_score = std::max(max_score, max_left_score + values[i]);
            max_left_score = std::max(max_left_score, values[i]);
        }
        return max_score;
    }
};
// @lc code=end

