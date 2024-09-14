/*
 * @lc app=leetcode.cn id=2181 lang=cpp
 *
 * [2181] 合并零之间的节点
 */

// @lc code=start

/* #include <bits/stdc++.h>
#define DEBUG(n) std::cout << "DEBUG: " << n << std::endl;
#define DEBUGI(i, n) std::cout << "DEBUG[" << i << "]: " << n << std::endl;
#define DEBUGV(vec, size) std::cout << '['; for (int i = 0; i < size; i++) { std::cout << vec[i]; if (i != size - 1) std::cout << ", "; } std::cout << ']' << std::endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; */

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        auto p = head->next;
        while(p) {
            while(p->next->val != 0) {
                p->val += p->next->val;
                p->next = p->next->next;
            }
            p = p->next = p->next->next;
        }
        return head->next;
    }
};
// @lc code=end

