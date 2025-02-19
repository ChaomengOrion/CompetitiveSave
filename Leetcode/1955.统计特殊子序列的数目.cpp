/*
 * @lc app=leetcode.cn id=1955 lang=cpp
 *
 * [1955] 统计特殊子序列的数目
 */
#include <bits/stdc++.h>
// @lc code=start
const int MOD = 1E9 + 7;
class Solution {
public:
    int countSpecialSubsequences(std::vector<int>& nums) {
        int A = 0, AB = 0, ABC = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                A += A + 1;
                A %= MOD;
            } else if (nums[i] == 1) {
                AB += (AB + A) % MOD;
                AB %= MOD;
            } else {
                ABC += (ABC + AB) % MOD;
                ABC %= MOD;
            }
        }
        return ABC;
    }
};
// @lc code=end

