#include <bits/stdc++.h>

uint32_t highbit(uint32_t x) {
    if (x == 0) return 0; // 处理0的特殊情况
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    // 对于64位数，增加一行：x |= x >> 32;
    return (x + 1) >> 1;
}

// 两个都只支持GCC/Clang 版本 __builtin_clz计算前导0
int msb1(int x)
{
    return 31 - __builtin_clz(x);
}

// 返回从右往左数最高位1的索引（从0开始）
int msb(int x)
{
    // floor(log2(x))
    return std::__lg(x);

    // 等价，C++20以后
    return std::bit_width<uint32_t>(x) - 1;

    // x为0时候返回-1
}

#include <bit>
auto cpp20(uint32_t x) {
    // 若 x 非零，则计算不大于 x 的最大的二的整数次幂。若 x 为零，则返回零。
    uint32_t f = std::bit_floor(x);
    // 补充向上的
    uint32_t c = std::bit_ceil(x);
    // 计算二进制数的前导零（leading zeros）数量。
    int a = std::countl_zero(x);
    a = std::countl_one(x);
    a = std::countr_zero(x);
    a = std::countr_one(x);
    int w = std::bit_width(x);
    int d = __builtin_popcount(x); // 计数1
    d = std::popcount(x);
}

bool is2(int x) {
    return (x & -x) == x;
}

bool is2_(int x) {
    return std::popcount<uint32_t>(x) == 1;
}

bool is2_1(int x) {
    return std::has_single_bit<uint32_t>(x);
}