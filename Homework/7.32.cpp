#include <iostream>
#include <string>

using namespace std;

// 递归函数检查字符串是否是回文
bool testPalindrome(const string& str, int start, int end) {
    // 基本情况：字符串长度为0或1
    if (start >= end) {
        return true;
    }

    // 检查第一个和最后一个字符是否相同
    if (str[start] != str[end]) {
        return false;
    }

    // 递归检查去掉第一个和最后一个字符后的子字符串
    return testPalindrome(str, start + 1, end - 1);
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    // 调用递归函数检查字符串是否是回文
    if (testPalindrome(str, 0, str.length() - 1)) {
        cout << "\"" << str << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << str << "\" is not a palindrome." << endl;
    }

    return 0;
}