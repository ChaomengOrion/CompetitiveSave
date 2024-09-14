/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(n) cout << "DEBUG: " << n << endl;

class Solution {
public:
    string intToRoman(int num) {
        string N = to_string(num);
        int len = N.length();
        string res;
        while (N.length() > 0)
        {
            if (N[0] == '4')
            {
                switch (N.length())
                {
                    case 3:
                        res += "CD";
                        break;
                    case 2:
                        res += "XL";
                        break;
                    case 1:
                        res += "IV";
                        break;
                }
            }
            else if (N[0] == '9')
            {
                switch (N.length())
                {
                    case 3:
                        res += "CM";
                        break;
                    case 2:
                        res += "XC";
                        break;
                    case 1:
                        res += "IX";
                        break;
                }
            }
            else if (N[0] == '5')
            {
                switch (N.length())
                {
                    case 3:
                        res += 'D';
                        break;
                    case 2:
                        res += 'L';
                        break;
                    case 1:
                        res += 'V';
                        break;
                }
            }
            else if (N[0] != '0')
            {
                int n = N[0] - '0';
                if (n > 5)
                {
                    switch (N.length())
                    {
                        case 3:
                            res += 'D';
                            break;
                        case 2:
                            res += 'L';
                            break;
                        case 1:
                            res += 'V';
                            break;
                    }
                    n -= 5;
                }
                for (char i = 0; i < n; i++)
                {
                    switch (N.length())
                    {   
                        case 4:
                            res += 'M';
                            break;
                        case 3:
                            res += 'C';
                            break;
                        case 2:
                            res += 'X';
                            break;
                        case 1:
                            res += 'I';
                            break;
                    }
                }
            }
            N = N.substr(1, N.length()-1); // TODO
        }
        return res;
    }
};
// @lc code=end

