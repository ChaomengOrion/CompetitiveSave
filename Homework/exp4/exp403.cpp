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

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, -3, 35, 5, 3, 2};
    
    ListNode* p = getList(arr);
    while (p) {
        std::cout << p->val << std::endl;
        p = p->next;
    }
}