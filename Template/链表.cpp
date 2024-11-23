#include <bits/stdc++.h>
using namespace std;

struct node {
    node(int v) : val(v) {}
    int val;
    node *next, *prev;
};

int main() {
    node *head = nullptr, *last = nullptr;
    node** nxt = &head;

    auto add = [&](int val) -> void {
        *nxt = new node(val);
        (*nxt)->prev = last;
        last = *nxt;
        nxt = &(last->next = nullptr);
    };

    auto del = [&](node* p) -> void {
        if (p->next) p->next->prev = p->prev;
        else last = p->prev;
        if (p->prev) p->prev->next = p->next;
        else head = p->next;
        delete p;
    };

    add(51);
    add(3);
    add(235);
    add(-44);

    del(head);
    del(last);

    node* p = head;
    while (p) {
        std::cout << p->val << std::endl;
        p = p->next;
    }

    p = last;
    while (p) {
        std::cout << p->val << std::endl;
        p = p->prev;
    }
}
