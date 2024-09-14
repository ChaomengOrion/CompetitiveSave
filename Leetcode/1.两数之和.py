#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#

# @lc code=start
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        for i in range(len(nums)):
            d = target - nums[i]
            if d in nums:
                for k in range(i + 1, len(nums)):
                    if nums[k] == d:
                        return[i, k]
# @lc code=end