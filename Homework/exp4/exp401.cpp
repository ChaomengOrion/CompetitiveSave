#include <bits/stdc++.h>

using i64 = long long;

i64 getSum(int* arr, int size) {
    i64 sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, -3, 35, 5, 3, 2};
    std::cout << getSum(arr, sizeof(arr) / sizeof(arr[0])) << std::endl;
}