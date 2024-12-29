#include <bits/stdc++.h>

using i64 = long long;
#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;

void solve() {
    i64 l, r, G;
    std::cin >> l >> r >> G;
    
    // 计算 x_min 和 x_max
    i64 x_min = (l + G - 1) / G; // 向上取整
    i64 x_max = r / G;           // 向下取整

    //LOG(x_min << " " << x_max)
    
    // 初始化 A 和 B
    i64 A = -1, B = -1;
    
    if (x_min > x_max) {
        // 没有 G 的倍数
        A = -1;
        B = -1;
    }
    else if (x_min == x_max) {
        if (x_min == 1) {
            // 只有一个倍数且 x=1，满足 GCD(A,B)=G
            A = G;
            B = G;
        }
        else {
            //* 只有一个倍数且 x >1，不满足 GCD(A,B)=G eg: 33 33 3
            A = -1;
            B = -1;
        }
    }
    else {
        if (x_min == 1) {
            // x_min =1，直接选择 A=G, B=G*x_max
            A = G;
            B = G * x_max;
        }
        else {
            //? 寻找最大的 y=x_max，满足 GCD(x_min, y)=1
            i64 candidate_y = x_max;
            while (candidate_y >= x_min) {
                if (std::gcd(x_min, candidate_y) == 1) {
                    A = G * x_min;
                    B = G * candidate_y;
                    break;
                }
                candidate_y--;
            }
            while ((x_max - x_min) * G > B - A) {
                x_min++;
                candidate_y = x_max;
                while (candidate_y >= x_min) {
                    if (std::gcd(x_min, candidate_y) == 1) {
                        i64 tA = G * x_min,
                        tB = G * candidate_y;
                        if (tB - tA > B - A) {
                            A = tA;
                            B = tB;
                        }
                        break;
                    }
                    candidate_y--;
                }
            }
        }
    }
    
    // 输出结果
    std::cout << A << " " << B << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}