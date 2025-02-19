#include <bits/stdc++.h>

void foo(int test0[], int test1[][3], int* test2[2]);

int main() {
    int test0[] = {1, 2, 3};

    int test1[2][3] = {{1, 2, 3}, {9, 8, 7}};
    int _test1[][3] = {{1, 2, 3}, {9, 8, 7}};
    //* 数组第一维长度可以省略，而后面都不能省略

    int a1[3] = {1, 2, 3};
    int a2[3] = {9, 8, 7};

    int* test2[2] = {a1, a2};

    auto t0_a = test0;
    auto t0_b = &test0;
    auto t1_a = test1;
    auto t1_b = &test1;
    auto t2_a = test2;
    auto t2_b = &test2;
    
    foo(test0, test1, test2);
}

void foo(int test0[], int test1[][3], int* test2[2]) {
    auto t0_a = test0;
    auto t0_b = &test0;
    auto t1_a = test1;
    auto t1_b = &test1;
    auto t2_a = test2;
    auto t2_b = &test2;
}