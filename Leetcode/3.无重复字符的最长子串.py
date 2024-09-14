#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxLen = 0
        start = 0
        map = dict()
        for end in range(len(s)):
            n = s[end]
            if n in s[start:end]:
                start = map[n]
            map[n] = end + 1
            llen = end + 1 - start
            if llen > maxLen:
                maxLen = llen
        return maxLen

        
# @lc code=end

