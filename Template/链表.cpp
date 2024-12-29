#include <bits/stdc++.h>

struct node {
    node(int v) : val(v) {}
    int val;
    node *next, *prev;
};

int main() {
    node *head = nullptr, *last = nullptr;

    auto add = [&](int val) -> void {
        node* p = new node(val);
        p->prev = last;
        if (last) last = last->next = p;
        else head = last = p;

        //! 单向版本
        /*{
            node* p = new node(val);
            if (last) last = last->next = p;
            else head = last = p;
        }*/
        //!
    };

    auto del = [&](node* p) -> void {
        if (p->next) p->next->prev = p->prev;
        else last = p->prev;
        if (p->prev) p->prev->next = p->next;
        else head = p->next;
        delete p;
    };

    auto get = [&](int pos) -> node* {
        node* t = head;
        while (pos--) t = t->next;
        return t;
    };

    auto insert = [&](int pos, int val) -> void {
        node* p = new node(val);
        if (pos == 0) {
            p->prev = nullptr;
            p->next = head;
            if (head) head->prev = p;
            else last = p; 
            head = p;
            return;
        }
        node* t = get(pos - 1);
        p->prev = t;
        p->next = t->next;
        t->next = p;
        if (p->next) p->next->prev = p;
        else last = p;
    };

    while (true) {
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "end") break;
        int p1 = cmd.find_first_of(','), p2 = cmd.find_last_of(',');
        std::string s0 = cmd.substr(0, p1);
        if (s0 == "append") add(stoi(cmd.substr(p1 + 1)));
        else if (s0 == "insert") insert(stoi(cmd.substr(p1 + 1, p2)) - 1, stoi(cmd.substr(p2 + 1)));
        else if (s0 == "delete") del(get(stoi(cmd.substr(p1 + 1, p2)) - 1));
    }

    node* p = head;
    while (p) {
        std::cout << p->val << ' ';
        p = p->next;
    }

    std::cout << std::endl;

    p = last;
    while (p) {
        std::cout << p->val << ' ';
        p = p->prev;
    }
}
