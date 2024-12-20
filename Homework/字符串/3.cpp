/// FileName: 3.cpp
/// Date: 2024/12/08
/// Author: ChaomengOrion

#include <bits/stdc++.h>

using namespace std;

// 读取二维数组
vector<vector<int>> readMatrix(int m, int n) {
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// 按螺旋顺序打印二维数组
vector<int> spiralOrder(const vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) return result;
    
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0, right = n - 1, top = 0, bottom = m - 1;
    
    while (left <= right && top <= bottom) {
        for (int j = left; j <= right; ++j) result.push_back(matrix[top][j]);
        for (int i = top + 1; i <= bottom; ++i) result.push_back(matrix[i][right]);
        if (top < bottom) {
            for (int j = right - 1; j >= left; --j) result.push_back(matrix[bottom][j]);
        }
        if (left < right) {
            for (int i = bottom - 1; i > top; --i) result.push_back(matrix[i][left]);
        }
        ++top;
        --bottom;
        ++left;
        --right;
    }
    
    return result;
}

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> matrix = readMatrix(m, n);
    vector<int> result = spiralOrder(matrix);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}