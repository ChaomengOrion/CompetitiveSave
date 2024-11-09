#include <bits/stdc++.h>

using namespace std;

void move_iterate(int n, char des, char now, char temp)
{
    char inorder[2][4] = {'0', temp, des, now, '0', des, now, temp};
    int i, j, k;
    char* np = new char[n + 1];
    for (int i = 0; i < n + 1; i++) np[i] = 'A';

    for (i = 1; i < (1 << n); i++) {
        for (j = i, k = 1; j % 2 == 0; k++, j /= 2);
        cout << "将圆盘" << k << "从 " << np[k] << " 移动到 ";
        np[k] = inorder[(1 + n + k) % 2][np[k] - 'A' + 1];
        cout << np[k] << endl;
    }
}

int main()
{
    int n;
    while (true) {
        cout << "请输入汉诺塔高度:";
        cin >> n;
        cout << "默认从A移动到C" << endl;
        move_iterate(n, 'C', 'A', 'B');
    }
}