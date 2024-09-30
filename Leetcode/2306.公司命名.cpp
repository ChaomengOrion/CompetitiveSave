/*
 * @lc app=leetcode.cn id=2306 lang=cpp
 *
 * [2306] 公司命名
 */
#include <bits/stdc++.h>
// @lc code=start
using i64 = long long;
unsigned int hashs(std::string s) {
    const unsigned int P = 133;
    unsigned int ans = 0;
    for (char c : s) {
        ans = ans * P + c;
    }
    return ans;
}
class Solution {
public:
    long long distinctNames(std::vector<std::string>& ideas) {
        std::vector map(26, std::unordered_set<unsigned int>());
        //std::set<i64> ansSet;
        for (std::string idea : ideas) {
            map[idea[0] - 'a'].insert(hashs(idea.substr(1)));
        }

        auto get_intersect_size = [](const std::unordered_set<unsigned int>& a, const std::unordered_set<unsigned int>& b) -> int {
            int ans = 0;
            for (auto& s: a) {
                if (b.contains(s)) {
                    ++ans;
                }
            }
            return ans;
        };

        i64 sum = 0;
        for (int i = 0; i < 25; i++) {
            auto set1 = map[i];
            for (int j = i + 1; j < 26; j++) {
                auto set2 = map[j];
                int ans = get_intersect_size(set1, set2);
                sum += (set1.size() - ans) * (set2.size() - ans) * 2;
            }
        }
        return sum;
    }
};
// @lc code=end

