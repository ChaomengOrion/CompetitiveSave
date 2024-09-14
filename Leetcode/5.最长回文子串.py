#
# @lc app=leetcode.cn id=5 lang=python3
#
# [5] 最长回文子串
#

# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> str:
        max_len = 0
        max_s = s[0]
        lens = len(s)
        for i in range(1, lens):
            k = 1
            while True:
                if i - k < 0 or i + k - 1 >= lens or s[i - k] != s[i + k - 1]:
                    break
                k += 1
            k -= 1
            lenr = k * 2
            if lenr > max_len:
                max_len = lenr
                max_s = s[i - k : i + k]

            k = 1
            while True:
                if i - k < 0 or i + k >= lens or s[i - k] != s[i + k]:
                    break
                k += 1
            k -= 1
            lenr = k * 2 + 1
            if lenr > max_len:
                max_len = lenr
                max_s = s[i - k : i + k + 1]
        return max_s
# @lc code=end

