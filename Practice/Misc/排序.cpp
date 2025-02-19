#include <bits/stdc++.h>

// 冒泡
void sort_1(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 选择
void sort_2(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// 插入
void sort_3(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int cur = arr[i];
        int pos = i;
        while (pos > 0 && cur < arr[pos - 1]) {
            arr[pos] = arr[pos - 1];
            pos--;
        }
        arr[pos] = cur;
    }
}

void Merge(int arr[], int front, int mid, int end) {
    // preconditions:
    // Array[front...mid] is sorted
    // Array[mid+1 ... end] is sorted
    // Copy Array[front ... mid] to LeftSubArray
    // Copy Array[mid+1 ... end] to RightSubArray
    std::vector<int> LeftSubArray(arr + front, arr + mid + 1);
    std::vector<int> RightSubArray(arr + mid + 1, arr + end + 1);
    int idxLeft = 0, idxRight = 0;
    LeftSubArray.insert(LeftSubArray.end(), std::numeric_limits<int>::max());
    RightSubArray.insert(RightSubArray.end(), std::numeric_limits<int>::max());
    // Pick min of LeftSubArray[idxLeft] and RightSubArray[idxRight], and put into Array[i]
    for (int i = front; i <= end; i++) {
        if (LeftSubArray[idxLeft] < RightSubArray[idxRight]) {
            arr[i] = LeftSubArray[idxLeft];
            idxLeft++;
        } else {
            arr[i] = RightSubArray[idxRight];
            idxRight++;
        }
    }
}

void MergeSort(int arr[], int front, int end) {
    if (front >= end)
        return;
    int mid = (front + end) >> 1;
    MergeSort(arr, front, mid);
    MergeSort(arr, mid + 1, end);
    Merge(arr, front, mid, end);
}

// 归并
void sort_4(int arr[], int size) {
    MergeSort(arr, 0, size - 1);
}

int main() {
    int arr[] = {9, -2, 3, -5, 3, 4, 33332, -3334, 0, 234,44, 43, 3, -3};
    int test[sizeof(arr) / sizeof(arr[0])];

    auto print = [&]() -> void {
        std::cout << "=====\n";
        std::copy(test, std::end(test), std::ostream_iterator<int>(std::cout, " "));
        std::cout << "\n";
    };

    memcpy(test, arr, sizeof(arr));
    print();
    sort_1(test, sizeof(arr) / sizeof(arr[0]));
    print();
    memcpy(test, arr, sizeof(arr));
    sort_2(test, sizeof(arr) / sizeof(arr[0]));
    print();
    memcpy(test, arr, sizeof(arr));
    sort_3(test, sizeof(arr) / sizeof(arr[0]));
    print();
    memcpy(test, arr, sizeof(arr));
    sort_4(test, sizeof(arr) / sizeof(arr[0]));
    print();
}