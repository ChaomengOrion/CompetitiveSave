#include <iostream>
using namespace std;

class MyClass {
private:
    int privateData;
    
public:
    MyClass(int data) : privateData(data) {}
    
    // 声明一个友元函数
    friend void showPrivateData(const MyClass& obj);
    
    // 声明一个友元类
    friend class FriendClass;
};

// 友元函数定义
void showPrivateData(const MyClass& obj) {
    // 可以直接访问私有成员变量
    cout << "Private data: " << obj.privateData << endl;
}

// 友元类定义
class FriendClass {
public:
    void display(const MyClass& obj) {
        // 可以直接访问MyClass的私有成员
        cout << "Friend class accessing private data: " << obj.privateData << endl;
    }
};

int main() {
    MyClass obj(100);
    
    // 通过友元函数访问私有数据
    showPrivateData(obj);
    
    // 通过友元类访问私有数据
    FriendClass friendObj;
    friendObj.display(obj);
    
    return 0;
}