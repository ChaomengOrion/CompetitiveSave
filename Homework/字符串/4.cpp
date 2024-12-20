#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 找到字符串数组的最长公共前缀
string longestCommonPrefix(const vector<string>& strs) {
    if (strs.empty()) return "NO COMMON PREFIX";
    
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); ++i) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "NO COMMON PREFIX";
        }
    }
    return prefix;
}

int main() {
    string input;
    getline(cin, input); // 读取输入字符串
    
    vector<string> strs;
    string word;
    for (char ch : input) {
        if (ch == ' ') {
            if (!word.empty()) {
                strs.push_back(word);
                word.clear();
            }
        } else {
            word += ch;
        }
    }
    if (!word.empty()) {
        strs.push_back(word);
    }
    
    string result = longestCommonPrefix(strs);
    cout << result << endl;
    
    return 0;
}