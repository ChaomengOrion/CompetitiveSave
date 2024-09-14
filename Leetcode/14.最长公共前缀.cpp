/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(n) cout << "DEBUG: " << n << endl;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() <= 1) return strs[0];
        
        int minLen = strs[0].length();
        for (int i = 1; i < strs.size(); i++)
        {
            int len = strs[i].length();
            if (len < minLen) minLen = len;
        }
        
        for (int pos = 0; pos < minLen; pos++)
        {
            char cur = strs[0][pos];
            for (int i = 1; i < strs.size(); i++)
            {
                if (strs[i][pos] != cur) return strs[0].substr(0, pos);
            }
        }

        return strs[0].substr(0, minLen);
    }
};
// @lc code=end

