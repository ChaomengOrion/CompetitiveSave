#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);
    int arr[100];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int last = -1, j = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] != last) {
            last = arr[j] = arr[i];
            j++;
        }
    }
    for (int i = 0; i < j; i++) {
        printf("%d ", arr[i]);
    }
}