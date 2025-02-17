/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */
#include <bits/stdc++.h>
// @lc code=start
class Solution {
public:
    std::vector<int> sortArrayByParityII(std::vector<int>& nums) {
        //std::cin.tie(0)->sync_with_stdio(0);
        int odd = 1, even = 0;

        while (even < nums.size() && nums[even] % 2 == 0) even += 2;
        while (odd < nums.size() && nums[odd] % 2 == 1) odd += 2;
        
        while (odd < nums.size() && even < nums.size()) {
            std::swap(nums[odd], nums[even]);
            while (even < nums.size() && nums[even] % 2 == 0) even += 2;
            while (odd < nums.size() && nums[odd] % 2 == 1) odd += 2;
        }

        return nums;
    }
};
// @lc code=end

