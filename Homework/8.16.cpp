#include <iostream>
//#include <vector>

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
        if (x != startX && y != startY) { // 不是起点，那么就是终点
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

int main() {
    std::cin >> startX >> startY; // 输入起点坐标
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cin >> map[i][j]; // 输入地图，i是第几行，j是第几列
        }
    }
    mazeTraverse(startX, startY);
    std::cout << "================ The path is ================\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) { // 输出地图
            if (path[i][j]) std::cout << 'X';
            else std::cout << map[i][j];
        }
        std::cout << '\n';
    }
    return 0;
}

/*
2 0
############
#...#......#
..#.#.####.#
###.#....#.#
#....###.#..
####.#.#.#.#
#..#.#.#.#.#
##.#.#.#.#.#
#........#.#
######.###.#
#......#...#
############
*/