#include <iostream>
#include <vector>

using namespace std;

const int N = 8;

// 打印棋盘
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

// 检查是否可以在 (row, col) 放置皇后
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    // 检查当前行的左侧
    for (int i = 0; i < col; ++i) {
        if (board[row][i]) {
            return false;
        }
    }

    // 检查左上方的对角线
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) {
            return false;
        }
    }

    // 检查左下方的对角线
    for (int i = row, j = col; i < N && j >= 0; ++i, --j) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// 递归解决八皇后问题
bool solveNQueens(vector<vector<int>>& board, int col) {
    // 基本情况：所有列都成功放置了皇后
    if (col >= N) {
        return true;
    }

    // 尝试在当前列的每一行放置皇后
    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // 放置皇后

            // 递归尝试在下一列放置皇后
            if (solveNQueens(board, col + 1)) {
                return true;
            }

            board[i][col] = 0; // 回溯
        }
    }

    return false;
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, 0)); // 初始化棋盘

    if (solveNQueens(board, 0)) {
        printBoard(board); // 打印解决方案
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}