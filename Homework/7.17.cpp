#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int rolls = 36000;
    const int sides = 6;
    const int maxSum = 12;
    int sumCounts[maxSum + 1] = {0}; // 数组索引从0到12

    // 初始化随机数生成器
    srand(static_cast<unsigned int>(time(0)));

    // 模拟掷骰子36,000次
    for (int i = 0; i < rolls; ++i) {
        int die1 = rand() % sides + 1; // 掷第一个骰子
        int die2 = rand() % sides + 1; // 掷第二个骰子
        int sum = die1 + die2; // 计算和
        sumCounts[sum]++; // 统计和出现的次数
    }

    // 打印结果
    cout << "Sum\tFrequency\tExpected Frequency" << endl;
    for (int sum = 2; sum <= maxSum; ++sum) {
        double expectedFrequency = static_cast<double>(rolls) * (sum == 7 ? 6.0 / 36.0 : (sum == 2 || sum == 12 ? 1.0 / 36.0 : (sum == 3 || sum == 11 ? 2.0 / 36.0 : (sum == 4 || sum == 10 ? 3.0 / 36.0 : (sum == 5 || sum == 9 ? 4.0 / 36.0 : 5.0 / 36.0)))));
        cout << sum << "\t" << sumCounts[sum] << "\t\t" << expectedFrequency << endl;
    }

    return 0;
}