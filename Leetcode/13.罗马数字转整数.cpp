/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(n) cout << "DEBUG: " << n << endl;

static const pair<string, short> strToInt[] = {
    {"III", 3},
    {"II", 2},
    {"I", 1},
    {"IV", 4},
    {"V", 5},
    {"IX", 9},
    {"XXX", 30},
    {"XX", 20},
    {"X", 10},
    {"XL", 40},
    {"L", 50},
    {"XC", 90},
    {"CCC", 300},
    {"CC", 200},
    {"C", 100},
    {"CD", 400},
    {"D", 500},
    {"CM", 900},
    {"MMM", 3000},
    {"MM", 2000},
    {"M", 1000}
}; // len = 21;

class Solution
{
public:
    int romanToInt(string s)
    {
        int res = 0;
        while (s.length() > 0)
        {
            for (int i = 0; i < 21; i++)
            {
                pair<string, short> strToIntPair = strToInt[i];
                int pl = strToIntPair.first.length();
                int sl = s.length();
                
                if (pl <= sl && s.substr(sl-pl, pl) == strToIntPair.first)
                {
                    //DEBUG(strToIntPair.first + ": " + to_string(strToIntPair.second))
                    res += strToIntPair.second;
                    s = s.substr(0, sl-pl);
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
