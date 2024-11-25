#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int SIZE = 12; // 迷宫的宽高
char map[SIZE][SIZE]; // 声明二维char数组，用来存储地图
bool visited[SIZE][SIZE] = {}; // 另外一个二维数组，记录某个格子有没有走过
bool path[SIZE][SIZE] = {}; // 另外一个二维数组，用来记录最终可行的路线，与visited不同，只记录走下去最终能到终点的点
int startX, startY; // 起点坐标

bool check(int x, int y) { // 判断这个坐标是不是在地图范围内，x是第几行，y是第几列
    return x >= 0 && y >= 0 && x < SIZE && y < SIZE;
}

// dfs递归函数，返回值代表点(x,y)处走下去能不能到达出口
bool mazeTraverse(int x, int y) {
    if (!check(x, y)) return false; // 目标格子超出边界了
    if (visited[x][y]) return false; // 目标格子已经走过了
    if (map[x][y] != '.') return false; // 撞墙了
    
    visited[x][y] = true; // 标记当前格子已经走过
    path[x][y] = true; // 暂时把当前格子加入最终可行的路线，后面发现走不通再去掉

    if (x == 0 || y == 0 || x == SIZE - 1 || y == SIZE - 1) { // 如果到达边界了
        if (x != startX || y != startY) { // 不是起点，那么就是终点
            return true;
        }
    }
    // 没到终点，尝试往四周走
    // 尝试向上走
    if (mazeTraverse(x, y + 1)) return true;
    // 尝试向下走
    if (mazeTraverse(x, y - 1)) return true;
    // 尝试向左走
    if (mazeTraverse(x - 1, y)) return true;
    // 尝试向右走
    if (mazeTraverse(x + 1, y)) return true;

    // 这个格子没法到达终点，从可行路线中去掉
    path[x][y] = false;
    return false;
}

// 随机生成迷宫
void mazeGenerator(char maze[SIZE][SIZE], int* entryRow, int* entryCol) {
    srand(time(nullptr));

    // 初始化迷宫，将所有元素设置为墙（#）
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            maze[i][j] = '#';
        }
    }

    // 随机选择一个入口点，并将其设置为路径（.）
    *entryRow = rand() % (SIZE - 2) + 1; // -2 再加 1，避免起点在角落上
    *entryCol = rand() % (SIZE - 2) + 1;
    int tx = 0, ty = 0;

    switch (rand() % 4) { // 入口点要贴边缘，随机一个边贴
        case 0:
            *entryRow = 0;
            tx = 1;
            break;
        case 1:
            *entryRow = SIZE - 1;
            tx = -1;
            break;
        case 2:
            *entryCol = 0;
            ty = 1;
            break;
        case 3:
            *entryCol = SIZE - 1;
            ty = -1;
            break;
    }
    // 使用迭代的方法生成迷宫路径
    int x = *entryRow, y = *entryCol;

    maze[x][y] = '.';
    for (int i = 0; i < 5; i++) { // 先往迷宫内走5步再开始随机乱走，不然效果不好
        if (!check(x + tx, y + ty)) break;
        x += tx, y += ty;
        maze[x][y] = '.'; // 标记为路
    }

    const std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 方向

    while (true) {
        auto [dx, dy] = directions[rand() % 4]; // 随机从上下左右取一个方向走
        int step = rand() % 3 + 1; // 随机在这个方向走1-3步
        for (int i = 0; i < step; i++) {
            if (!check(x + dx, y + dy)) break;
            x += dx, y += dy;
            maze[x][y] = '.'; // 标记为路
        }
        if (x == 0 || y == 0 || x == SIZE - 1 || y == SIZE - 1) { // 如果到达边界了，记录为迷宫终点
            if (x != *entryRow || y != *entryCol) { // 不是起点
                return;
            }
        }
    }
}

int main() {
    int entryRow, entryCol;
    mazeGenerator(map, &entryRow, &entryCol);

    std::cout << "Generated Maze: (start point is " << entryRow << ", " << entryCol << ")" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << map[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    startX = entryRow;
    startY = entryCol;

    if (!mazeTraverse(startX, startY)) {
        std::cout << "No exit found." << std::endl;
    } else {
        std::cout << "Path found:" << std::endl;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                std::cout << (path[i][j] ? 'X' : map[i][j]) << ' ';
            }
            std::cout << std::endl;
        }
    }

    return 0;
}