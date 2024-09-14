/*
 * @lc app=leetcode.cn id=2398 lang=cpp
 *
 * [2398] 预算内的最多机器人数目
 */

// @lc code=start
#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    int maximumRobots(std::vector<int>& chargeTimes, std::vector<int>& runningCosts, i64 budget) {
        int len = chargeTimes.size();
        std::vector<i64> preRC(len + 1, 0LL);
        for (int i = 0; i < len; i++) preRC[i + 1] = preRC[i] + runningCosts[i];

        std::deque<int> CTdeq;
        int maxCnt = 0, l = 0, r = 0;
        while (r < len) {
            while (!CTdeq.empty() && CTdeq.front() < l) CTdeq.pop_front();
            while (!CTdeq.empty() && chargeTimes[CTdeq.back()] < chargeTimes[r]) CTdeq.pop_back();
            CTdeq.push_back(r);
            i64 cost = (i64)chargeTimes[CTdeq.front()] + 1LL * (r - l + 1) * (preRC[r + 1] - preRC[l]);
            if (cost <= budget) {
                maxCnt = std::max(maxCnt, r - l + 1);
                r++;
            } else {
                l++;
                r = std::max(l, r);
            }
        }
        return maxCnt;    
    }
};
// @lc code=end

