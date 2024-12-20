#include <iostream>
using namespace std;

struct Employee {
    int id;
    int age;
    char gender;
    Employee* next;
};

// 根据输入的职工个数建立单链表
Employee* createList(int n) {
    Employee* head = nullptr;
    Employee* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        Employee* newEmployee = new Employee();
        cin >> newEmployee->id >> newEmployee->age >> newEmployee->gender;
        newEmployee->next = nullptr;
        if (head == nullptr) {
            head = newEmployee;
            tail = newEmployee;
        } else {
            tail->next = newEmployee;
            tail = newEmployee;
        }
    }
    return head;
}

// 遍历链表并输出全部职工信息
void printList(Employee* head) {
    Employee* current = head;
    while (current != nullptr) {
        cout << current->id << " " << current->age << " " << current->gender << endl;
        current = current->next;
    }
}

// 统计男、女职工的人数
void countGender(Employee* head, int& maleCount, int& femaleCount) {
    maleCount = 0;
    femaleCount = 0;
    Employee* current = head;
    while (current != nullptr) {
        if (current->gender == 'm') {
            maleCount++;
        } else if (current->gender == 'f') {
            femaleCount++;
        }
        current = current->next;
    }
}

// 在链表尾部插入新职工结点
void insertAtEnd(Employee*& head, int id, int age, char gender) {
    Employee* newEmployee = new Employee();
    newEmployee->id = id;
    newEmployee->age = age;
    newEmployee->gender = gender;
    newEmployee->next = nullptr;
    if (head == nullptr) {
        head = newEmployee;
    } else {
        Employee* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = newEmployee;
    }
}

// 删除指定编号的职工结点
void deleteById(Employee*& head, int id) {
    if (head == nullptr) return;
    if (head->id == id) {
        Employee* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Employee* current = head;
    while (current->next != nullptr && current->next->id != id) {
        current = current->next;
    }
    if (current->next != nullptr) {
        Employee* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

int main() {
    int n;
    cin >> n;
    Employee* head = createList(n);
    printList(head);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int id, age;
        char gender;
        cin >> id >> age >> gender;
        insertAtEnd(head, id, age, gender);
    }
    printList(head);

    int maleCount, femaleCount;
    countGender(head, maleCount, femaleCount);
    cout << "Number of male employees:" << maleCount << endl;
    cout << "Number of female employees:" << femaleCount << endl;

    deleteById(head, 2);
    printList(head);

    return 0;
}