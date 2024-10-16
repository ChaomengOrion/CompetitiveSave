#include <bits/stdc++.h>

int main() {
    //system("chcp 65001"); // 防止中文乱码
    double a, b, c;
    std::cout << "请输入一元二次方程的系数a, b, c (a≠0): ";
    std::cin >> a >> b >> c;

    if (a == 0) {
        std::cout << "系数a不能为0。" << std::endl;
        return 1;
    }

    double delta = b * b - 4 * a * c; // 判别式
    // 分类讨论
    if (delta > 0) {
        double root1 = (-b + sqrt(delta)) / (2 * a);
        double root2 = (-b - sqrt(delta)) / (2 * a);
        std::cout << "有两个不同的实数根: " << root1 << " 和 " << root2 << std::endl;
    } else if (delta == 0) {
        double root = -b / (2 * a);
        std::cout << "有一个实数根: " << root << std::endl;
    } else {
        double i = sqrt(-delta) / (2 * a);
        double r = -b / (2 * a);
        std::cout << "有两个复数根: " << r << '+' << i << 'i' << " 和 " << r << '-' << i << 'i' << std::endl;
    }

    return 0;
}