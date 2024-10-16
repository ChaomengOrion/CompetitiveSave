// 这不是洛谷原题嘛
#include <bits/stdc++.h>

void sovle(std::vector<int>& tri)
{
    std::sort(tri.begin(), tri.end()); // 排序三条边
    if (tri[0] + tri[1] <= tri[2]) { // 两边小于第三边
        std::cout << "Not triangle" << std::endl;
        return;
    }
    int abS = tri[0] * tri[0] + tri[1] * tri[1], cS = tri[2] * tri[2]; // 算平方
    if (abS == cS)
        std::cout << "Right triangle" << std::endl; // 勾股定理
    else if (abS < cS)
        std::cout << "Obtuse triangle" << std::endl;
    else
        std::cout << "Acute triangle" << std::endl;
    if (tri[0] == tri[1] || tri[1] == tri[2]) std::cout << "Isosceles triangle" << std::endl; // 等腰
    if (tri[0] == tri[2]) std::cout << "Equilateral triangle" << std::endl; // 等边
}

int main()
{
    std::vector<int> tri(3);
    std::cout << "Input 3 edge of the triangle: " << std::endl;
    while (std::cin >> tri[0] >> tri[1] >> tri[2]) {
        sovle(tri);
        std::cout << "Input 3 edge of the triangle: " << std::endl;
    }
    return 0;
}