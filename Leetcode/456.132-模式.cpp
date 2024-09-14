/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */

// @lc code=start
#include <bits/stdc++.h>

class Solution
{
public:
    bool find132pattern(std::vector<int>& nums)
    {
        int k = INT_MIN;
        std::stack<int> st;
        int n = nums.size();
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] >= k) {
                while (!st.empty() && nums[st.top()] < nums[i]) {
                    k = nums[st.top()];
                    st.pop();
                }
                st.push(i);
            } else return true;
        }
        return false;
    }
};
// @lc code=end
