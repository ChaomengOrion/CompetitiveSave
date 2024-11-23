#include <iostream>

using namespace std;

// 函数声明
void selectionSort(int arr[], int start, int n);
int findMinIndex(int arr[], int start, int n);

// 递归选择排序函数
void selectionSort(int arr[], int start, int n) {
    // 基本情况：如果子数组的大小为1，则数组已排序
    if (start >= n - 1) {
        return;
    }

    // 找到当前子数组中的最小元素的索引
    int minIndex = findMinIndex(arr, start, n);

    // 将最小元素与子数组的第一个元素交换
    if (minIndex != start) {
        swap(arr[start], arr[minIndex]);
    }

    // 对剩余的子数组递归调用 selectionSort 函数
    selectionSort(arr, start + 1, n);
}

// 找到当前子数组中的最小元素的索引
int findMinIndex(int arr[], int start, int n) {
    int minIndex = start;
    for (int i = start + 1; i < n; ++i) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr, 0, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}