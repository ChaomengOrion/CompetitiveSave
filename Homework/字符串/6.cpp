#include <iostream>
#include <vector>
using namespace std;

// 读取矩阵
vector<vector<int>> readMatrix(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// 计算矩阵乘积
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    int p = B[0].size();
    vector<vector<int>> C(n, vector<int>(p, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < m; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    int n, m, p;
    cin >> n >> m;
    vector<vector<int>> A = readMatrix(n, m);
    
    cin >> m >> p;
    vector<vector<int>> B = readMatrix(m, p);
    
    vector<vector<int>> C = multiplyMatrices(A, B);
    
    for (const auto& row : C) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}