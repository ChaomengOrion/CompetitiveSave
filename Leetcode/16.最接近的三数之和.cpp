/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(n) cout << "DEBUG: " << n << endl;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min = 1E9, ans = -1;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 2; i++)
        {
            int cur = nums[i];
            if (i > 0 and cur == nums[i - 1]) continue;
            if (int sum = cur + nums[len-2] + nums[len-1]; sum < target)
            {
                if (int delta = abs(sum - target); delta < min)
                {
                    min = delta;
                    ans = sum;
                }
                continue;
            }
            int l = i + 1, r = len - 1;
            while (l < r)
            {
                int left = nums[l], right = nums[r];
                int sum = left + cur + right;
                if (sum == target) return sum;
                int delta = abs(sum - target);
                if (delta < min)
                {
                    min = delta;
                    ans = sum;
                }
                if (sum < target) while(++l < r and nums[l] == nums[l-1]);
                else while(l < --r and nums[r] == nums[r+1]);
            }
            if (cur + nums[i+1] + nums[i+2] > target) break;
        }
        return ans;
    }
};
// @lc code=end

