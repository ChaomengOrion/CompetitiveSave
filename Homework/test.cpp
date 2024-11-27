#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//递归方式合并
ListNode* mergeListRecursively(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;//链表头节点为空，返回链表头节点
    if (l2 == nullptr) return l1;

    if (l1->val <= l2->val)//比较两个链表的头节点 
        //若l1小于l2中的数据，则保留其作为链表头节点，使其下一个节点与l2比较
    {
        l1->next = mergeListRecursively(l1->next, l2);
        return l1;
    }
    //若l2小于l1中的数据，则保留其作为链表头节点，使其下一个节点与l1比较
    else {
        l2->next = mergeListRecursively(l1, l2->next);
        return l2;
    }
}

//非递归方式合并
ListNode* mergeListNonRecursively(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1);
        ListNode* current = preHead;
        while (l1 && l2) {
            //比较头节点，较小的作为新链表的头节点
            if (l1->val <= l2->val) {
                current->next = l1;
                current = l1;
                l1 = l1->next;
            }
            else {
                current->next = l2;
                current = l2;
                l2 = l2->next;
            }
        }
        
        current->next = l1 ? l1 : l2;
        return preHead->next;
}

///打印链表
void printList(ListNode* head) {
    //while循环输出链表的数据
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;//移动指针，使其指向下一个节点
    }
}

int main() {
    // 创建两个测试链表
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);

    // 合并链表并打印结果
    ListNode* mergedListRecursively = mergeListRecursively(l1, l2);
    printList(mergedListRecursively);
    cout << endl;
    
    l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);

    l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);
    ListNode* mergedListNonRecursively = mergeListNonRecursively(l1, l2);
    printList(mergedListNonRecursively);

    return 0;
}