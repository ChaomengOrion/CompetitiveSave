#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 生成字符串的所有排列组合
void permute(string str, int l, int r, vector<string>& result) {
    if (l == r) {
        result.push_back(str);
    } else {
        for (int i = l; i <= r; ++i) {
            swap(str[l], str[i]);
            permute(str, l + 1, r, result);
            swap(str[l], str[i]); // 回溯
        }
    }
}

int main() {
    string input;
    cin >> input; // 读取输入字符串
    
    vector<string> result;
    permute(input, 0, input.size() - 1, result);
    
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    
    for (const string& s : result) {
        cout << s << endl;
    }
    
    return 0;
}