# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        def ton(l: ListNode):
            n = 0
            i = 0
            node = l
            while node:
                n += node.val * (10 ** i)
                i+=1
                node = node.next
            return n
        n1 = ton(l1)
        n2 = ton(l2)
        n = n1 + n2
        
        res = ListNode()
        node = res

        while True:
            l = n % 10
            node.val = l
            if n > l:
                node_next = ListNode()
                node.next = node_next
                node = node_next
                n = (n - l) // 10
            else:
                break
        return res
# @lc code=end