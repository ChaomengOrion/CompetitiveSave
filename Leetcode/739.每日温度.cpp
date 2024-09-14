/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> ans(temperatures.size());
        stack<int> dq; // 单调栈 从大到小
        for (int i = 0; i < temperatures.size(); i++) {
            while (!dq.empty() && temperatures[dq.top()] < temperatures[i]) {
                ans[dq.top()] = i - dq.top();
                dq.pop();
            }
            dq.push(i);
        }
        return ans;
    }
};
// @lc code=end
