/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define DEBUG(n) cout << "DEBUG: " << n << endl;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0, last = -2.1E9;
        vector<int> nnums;
        for (int i = 0; i < len; i++) {
            if (nums[i] != last) {
                last = nums[i];
                cnt = 0;
            }
            cnt++;
            if (cnt > 4) continue;
            else {
                nnums.push_back(nums[i]);
                //cout << nums[i] << ", ";
            }
        }
        //cout << endl;
        nums = nnums;
        len = nums.size();
        vector twoSums(len * (len - 1) / 2, std::array<int, 3>());
        cnt = 0;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                twoSums[cnt++] = {nums[i] + nums[j], i, j};
            }
        }
        sort(twoSums.begin(), twoSums.end(), [](auto a, auto b) { return a[0] < b[0]; });
        last = -2.1E9;
        vector<pair<int, vector<pair<int, int>>>> map;
        for (int i = 0; i < len * (len - 1) / 2; i++) {
            //std::cout << twoSums[i][1] << ", " << twoSums[i][2] << std::endl;
            if (twoSums[i][0] == last) {
                map.back().second.push_back({twoSums[i][1], twoSums[i][2]});
            } else {
                last = twoSums[i][0];
                map.push_back({last, {{twoSums[i][1], twoSums[i][2]}}});
            }
        }
        int l = 0, r = map.size() - 1;
        set<vector<int>> ans;
        while (l <= r) {
            i64 sum = 0LL + map[l].first + map[r].first;
            //std::cout << map[l].first << ", " << map[r].first << std::endl;
            if (sum == target) {
                if (l < r) {
                    for (int i = 0; i < map[l].second.size(); i++) {
                        for (int j = 0; j < map[r].second.size(); j++) {
                            int l1 = map[l].second[i].first, l2 = map[l].second[i].second, r1 = map[r].second[j].first, r2 = map[r].second[j].second;
                            //std::cout << l1 << ", " << l2 << ", " << r1 << ", " << r2 << " | " << nums[l1] << ", " << nums[l2] << ", " << nums[r1] << ", " << nums[r2] <<  std::endl;
                            if (l1 != r1 && l1 != r2 && l2 != r1 && l2 != r2) {
                                vector<int> a = {nums[l1], nums[l2], nums[r1], nums[r2]};
                                sort(a.begin(), a.end());
                                ans.insert(a);
                            }
                        }
                    }
                } else {
                    for (int i = 0; i < map[l].second.size() - 1; i++) {
                        for (int j = i; j < map[r].second.size(); j++) {
                            int l1 = map[l].second[i].first, l2 = map[l].second[i].second, r1 = map[r].second[j].first, r2 = map[r].second[j].second;
                            if (l1 != r1 && l1 != r2 && l2 != r1 && l2 != r2) {
                                vector<int> a = {nums[l1], nums[l2], nums[r1], nums[r2]};
                                sort(a.begin(), a.end());
                                ans.insert(a);
                            }
                        }
                    }
                }
            }
            if (sum > target)
                r--;
            else
                l++;
        }
        vector<vector<int>> ans2;
        ans2.assign(ans.begin(), ans.end());
        return ans2;
    }
};
// @lc code=end
