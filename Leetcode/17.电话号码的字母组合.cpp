/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(n) cout << "DEBUG: " << n << endl;

static const map<char, string> numToStr = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0) return res;
        add("", digits, res);
        return res;
    }

    void add(string pre, string s, vector<string> &res)
    {
        if (s.length() == 0)
        {
            res.emplace_back(pre);
            return;
        }
        char c = s[0];
        s = s.substr(1);
        string my = numToStr.at(c);
        for (short i = 0; i < my.size(); i++)
        {
            add(pre + my[i], s, res);
        }
    }
};
// @lc code=end

