//#include <bits/stdc++.h>
#include <iostream>

struct node {
    int data;
    node* next;
};

void foo(int arr[]);

void Create(node*& head) {
    int temp;
    node* p;
    std::cin >> temp;
    while (temp != 0) {
        p = new node;
        p->data = temp;
        p->next = head;
        head = p;
        std::cin >> temp;
    }
    std::swap(p,p);
    int a[3][2];
    foo(*a);
}