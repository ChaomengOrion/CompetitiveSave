#include <bits/stdc++.h>

using i64 = long long;

int* reverse(int* arr, int size) {
    int* rev = new int[10];
    for (int i = 0; i < size; i++) {
        *(rev + size - 1 - i) = *(arr + i);
    }
    arr = rev;
    return rev;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, -3, 35, 5, 3, 2};
    int* ans = reverse(arr, 10);
    for (int i = 0; i < 10; i++) {
        std::cout << ans[i] << ' ';
    }
}