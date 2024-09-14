#
# @lc app=leetcode.cn id=4 lang=python3
#
# [4] 寻找两个正序数组的中位数
#

# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        l = sorted(nums1 + nums2)
        llen = len(l)
        if llen % 2:
            return l[(llen+1)//2-1]
        else:
            return (l[llen//2-1]+l[llen//2])/2
# @lc code=end

