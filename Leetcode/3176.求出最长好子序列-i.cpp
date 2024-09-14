/*
 * @lc app=leetcode.cn id=3176 lang=cpp
 *
 * [3176] 求出最长好子序列 I
 */

// @lc code=start
#include <bits/stdc++.h>

#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;
#define DEBUGV(vec, size) std::cout << '['; for (int i = 0; i < size; i++) { std::cout << vec[i]; if (i != size - 1) std::cout << ", "; } std::cout << ']' << std::endl;

class Solution
{
public:
    int maximumLength(std::vector<int>& nums, int k)
    {
        std::vector dp(nums.size(), std::vector<int>(k+1, 0));
        dp[0].resize(k+1, 1);
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j <= k; j++) {
                
            }
        }
    }
};
// @lc code=end

