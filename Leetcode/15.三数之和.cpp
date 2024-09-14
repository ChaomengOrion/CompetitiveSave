/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(n) cout << "DEBUG: " << n << endl;
// -4 -1 -1 0 1 2
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 1; i++)
        {
            int cur = nums[i];
            if (cur > 0) break;
            if (i > 0 and cur == nums[i - 1]) continue;
            if (cur + nums[len-2] + nums[len-1] < 0) continue;
            int l = i + 1, r = len - 1;
            while (l < r)
            {
                int left = nums[l], right = nums[r];
                int sum = left + cur + right;
                if (sum == 0) res.push_back({ left, cur, right });
                if (sum <= 0) while(++l < r and nums[l] == nums[l-1]);
                else while(l < --r and nums[r] == nums[r+1]);
            }
        }
        return res;
    }
};
// @lc code=end