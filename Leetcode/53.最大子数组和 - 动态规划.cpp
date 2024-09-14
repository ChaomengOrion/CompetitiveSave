/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size(), pre;
        int maxSum = pre = nums[0];
        for (int i = 1; i < len; i++)
        {
            pre = max(pre + nums[i], nums[i]);
            if (pre > maxSum) maxSum = pre;
        }
        return maxSum;
    }
};
// @lc code=end

