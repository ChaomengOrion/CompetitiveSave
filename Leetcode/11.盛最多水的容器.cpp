/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> toRight, toLeft;
        int max = -1;
        for (int i = 0; i < height.size() - 1; i++)
        {
            if (height[i] > max)
            {
                max = height[i];
                toRight.push_back(i);
            }
        }
        max = -1;
        for (int i = height.size() - 1; i > 0; i--)
        {
            if (height[i] > max)
            {
                max = height[i];
                toLeft.push_back(i);
            }
        }
        max = -1;
        for (int i = 0; i < toRight.size(); i++)
        {
            for (int j = 0; j < toLeft.size(); j++)
            {
                if (toLeft[j] > toRight[i])
                {
                    int size = (toLeft[j] - toRight[i]) * min(height[toRight[i]], height[toLeft[j]]);
                    if (size > max) max = size;
                }
            }
        }
        return max;
    }
};
// @lc code=end

