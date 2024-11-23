#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int SIZE = 1000;
    vector<bool> prime(SIZE, true); // 创建一个大小为1000的数组，并将所有元素初始化为true

    // 忽略元素0和1
    prime[0] = prime[1] = false;

    // 埃拉托斯特尼筛法
    for (int i = 2; i * i < SIZE; ++i) {
        if (prime[i]) {
            for (int j = i * i; j < SIZE; j += i) {
                prime[j] = false;
            }
        }
    }

    // 打印所有素数
    cout << "Prime numbers between 2 and 999:" << endl;
    for (int i = 2; i < SIZE; ++i) {
        if (prime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}