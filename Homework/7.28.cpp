#include <iostream>
#include <iomanip>

using namespace std;

const int BOARD_SIZE = 8;
const int MOVES = 8;

// 定义骑士的8个可能移动方向
int horizontal[MOVES] = {2, 1, -1, -2, -2, -1, 1, 2};
int vertical[MOVES] = {1, 2, 2, 1, -1, -2, -2, -1};

// 检查骑士是否可以移动到指定位置
bool isValidMove(int x, int y, int board[BOARD_SIZE][BOARD_SIZE]) {
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == 0);
}

// 打印棋盘
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << setw(2) << board[i][j] << " ";
        }
        cout << endl;
    }
}

// 实现骑士巡游算法
bool knightTour(int board[BOARD_SIZE][BOARD_SIZE], int x, int y, int moveCount) {
    if (moveCount == BOARD_SIZE * BOARD_SIZE) {
        // 检查是否为闭合巡游
        for (int i = 0; i < MOVES; ++i) {
            int nextX = x + horizontal[i];
            int nextY = y + vertical[i];
            if (nextX == 0 && nextY == 0) {
                return true; // 闭合巡游
            }
        }
        return false; // 完整巡游但不是闭合巡游
    }

    for (int i = 0; i < MOVES; ++i) {
        int nextX = x + horizontal[i];
        int nextY = y + vertical[i];
        if (isValidMove(nextX, nextY, board)) {
            board[nextX][nextY] = moveCount + 1;
            if (knightTour(board, nextX, nextY, moveCount + 1)) {
                return true;
            }
            board[nextX][nextY] = 0; // 回溯
        }
    }
    return false;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    board[0][0] = 1; // 起始位置

    if (knightTour(board, 0, 0, 1)) {
        cout << "Closed tour found:" << endl;
    } else {
        cout << "No closed tour found." << endl;
    }

    printBoard(board);

    return 0;
}