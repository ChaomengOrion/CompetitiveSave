#include <iostream>
using namespace std;

struct List {
    int data;
    List* next;
};

// 创建链表
List* createList(int n) {
    List* head = nullptr;
    List* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        List* newNode = new List();
        cin >> newNode->data;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// 计算并输出链表中有相同值的结点及其个数
void Count(List* head) {
    if (head == nullptr) return;
    
    List* current = head;
    while (current != nullptr) {
        int count = 1;
        while (current->next != nullptr && current->data == current->next->data) {
            count++;
            current = current->next;
        }
        if (count > 1) {
            cout << current->data << " " << count << endl;
        }
        current = current->next;
    }
}

int main() {
    int n;
    while (cin >> n) {
        List* head = createList(n);
        Count(head);
    }
    return 0;
}