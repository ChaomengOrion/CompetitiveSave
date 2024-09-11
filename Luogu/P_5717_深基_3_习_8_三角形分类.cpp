#include <bits/stdc++.h>

int main()
{
    std::vector<int> tri(3);
    std::cin >> tri[0] >> tri[1] >> tri[2];
    std::sort(tri.begin(), tri.end());
    if (tri[0] + tri[1] <= tri[2]) {
        std::cout << "Not triangle" << std::endl;
        return 0;
    }
    int abS = tri[0]*tri[0] + tri[1]*tri[1], cS = tri[2]*tri[2];
    if (abS == cS) std::cout << "Right triangle" << std::endl;
    else if (abS < cS) std::cout << "Obtuse triangle" << std::endl;
    else std::cout << "Acute triangle" << std::endl;
    if (tri[0] == tri[1] || tri[1] == tri[2])  std::cout << "Isosceles triangle" << std::endl;
    if (tri[0] == tri[2]) std::cout << "Equilateral triangle" << std::endl;
    return 0;
}