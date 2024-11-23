#include <iostream>

using namespace std;

// 递归函数执行线性搜索
int linearSearch(const int arr[], int size, int index, int key) {
    // 基本情况：当前索引超出数组大小
    if (index >= size) {
        return -1;
    }

    // 检查当前索引的元素是否等于搜索键
    if (arr[index] == key) {
        return index;
    }

    // 递归检查下一个索引
    return linearSearch(arr, size, index + 1, key);
}

int main() {
    const int SIZE = 10;
    int arr[SIZE] = {34, 7, 23, 32, 5, 62, 32, 2, 45, 12};
    int key;

    cout << "Enter the search key: ";
    cin >> key;

    // 调用递归函数执行线性搜索
    int result = linearSearch(arr, SIZE, 0, key);

    if (result != -1) {
        cout << "Search key " << key << " found at index " << result << "." << endl;
    } else {
        cout << "Search key " << key << " not found." << endl;
    }

    return 0;
}