#include <bits/stdc++.h>

int main()
{
    //system("chcp 65001");
    int score;
    std::cout << "Please input a score between 0-100: ";
    while (std::cin >> score) {
        while (score < 0 || score > 100) {
            std::cout << "Score error, please input a score between 0-100: ";
            std::cin >> score;
        }
        switch (score / 10) { // 利用int的四舍五入，除10讨论
        case 10:
        case 9: std::cout << "优秀" << std::endl; break;
        case 8: std::cout << "良" << std::endl; break;
        case 6:
        case 7: std::cout << "及格" << std::endl; break;
        default: std::cout << "不及格" << std::endl; break;
        }
        std::cout << "Please input a score between 0-100: ";
    }
    return 0;
}