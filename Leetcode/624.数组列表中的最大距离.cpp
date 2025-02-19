/*
 * @lc app=leetcode.cn id=624 lang=cpp
 *
 * [624] 数组列表中的最大距离
 */
#include <bits/stdc++.h>
// @lc code=start
class Solution {
public:
    int maxDistance(std::vector<std::vector<int>>& arr) {
        int min = 1e5, max = -1e5, ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            ans = std::max({ans, max - arr[i].front(), arr[i].back() - min});
            min = std::min(min, arr[i].front());
            max = std::max(max, arr[i].back());
        }
        return ans;
    }
};
// @lc code=end

