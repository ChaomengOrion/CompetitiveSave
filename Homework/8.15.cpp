#include <iostream>

using namespace std;

// 分区函数
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // 选择第一个元素作为枢轴
    int left = low + 1;
    int right = high;

    while (true) {
        // 从左向右找到第一个大于枢轴的元素
        while (left <= right && arr[left] <= pivot) {
            left++;
        }

        // 从右向左找到第一个小于枢轴的元素
        while (left <= right && arr[right] >= pivot) {
            right--;
        }

        // 如果左指针超过右指针，退出循环
        if (left > right) {
            break;
        }

        // 交换左指针和右指针指向的元素
        swap(arr[left], arr[right]);
    }

    // 将枢轴元素放到正确的位置
    swap(arr[low], arr[right]);

    return right; // 返回枢轴元素的位置
}

// 快速排序函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // 执行分区步骤
        quickSort(arr, low, pivotIndex - 1); // 递归排序左子数组
        quickSort(arr, pivotIndex + 1, high); // 递归排序右子数组
    }
}

int main() {
    int arr[] = {37, 264, 89, 8, 10, 12, 68, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}