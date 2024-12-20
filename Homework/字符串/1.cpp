/// FileName: 1.cpp
/// Date: 2024/12/08
/// Author: ChaomengOrion

#include <bits/stdc++.h>

using namespace std;

// 清理输入字符串，去除非字母字符并转换为小写
string cleanString(const string& str) {
    string cleaned;
    for (char ch : str) {
        if (isalpha(ch)) {
            cleaned += tolower(ch);
        }
    }
    return cleaned;
}

// 检查字符串是否为回文
bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string input;
    getline(cin, input); // 读取输入字符串

    string cleanedInput = cleanString(input);
    if (isPalindrome(cleanedInput)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}