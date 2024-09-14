#
# @lc app=leetcode.cn id=7 lang=python3
#
# [7] 整数反转
#

# @lc code=start
class Solution:
    low = -2 ** 31
    up = 2 ** 31 - 1
    def reverse(self, x: int) -> int:
        if x < 0:
            sgn = -1
        else:
            sgn = 1
        res = sgn * int(str(sgn * x)[::-1])
        if res < self.low or res > self.up:
            return 0
        else:
            return res
# @lc code=end

