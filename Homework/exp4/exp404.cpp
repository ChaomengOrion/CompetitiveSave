#include <bits/stdc++.h>

using i64 = long long;

struct ListNode {
    int val;
    ListNode* next;
};

ListNode* getList(std::vector<int>& arr) {
    ListNode* head = nullptr;
    ListNode** nxt = &head;

    auto add = [&](int val) -> void {
        *nxt = new ListNode { val, nullptr };
        nxt = &(*nxt)->next;
    };
    
    for (int i = 0; i < (int)arr.size(); i++) {
        add(arr[i]);
    }
    return head;
}

void print(ListNode* p) {
    while (p) {
        std::cout << p->val << ' ';
        p = p->next;
    }
    std::cout << std::endl;
}

ListNode* mergeList(ListNode* p1, ListNode* p2) {
    ListNode* head = nullptr;
    ListNode** nxt = &head;

    auto add = [&](int val) -> void {
        *nxt = new ListNode { val, nullptr };
        nxt = &(*nxt)->next;
    };

    while (p1 || p2) {
        if (p1 && p2) {
            int v1 = p1->val;
            int v2 = p2->val;
            if (v1 <= v2) {
                add(v1);
                p1 = p1->next;
            } else {
                add(v2);
                p2 = p2->next;
            }
        } else if (p1) { // p1非空
            add(p1->val);
            p1 = p1->next;
        } else { // p2非空
            add(p2->val);
            p2 = p2->next;
        }
    }

    return head;
}

int main() {
    std::vector<int> arr1 = {-1, -2, 3, 4, 5, 6, 35, 455};
    std::vector<int> arr2 = {-114, 514, 999};
    
    ListNode* p1 = getList(arr1);
    ListNode* p2 = getList(arr2);

    print(p1);
    print(p2);

    print(mergeList(p1, p2));
}