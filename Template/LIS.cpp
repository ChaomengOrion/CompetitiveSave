#include <bits/stdc++.h>

int main() {
    std::vector<int> arr = {3, 1, 3, 4, 5, 3, 2};
    int size = arr.size();
    std::vector<int> low(size, INT_MAX);
    int max_s = 0;
    for (int i = 0; i < size; i++) {
        int pos = std::lower_bound(low.begin(), low.end(), arr[i]) - low.begin();
        low[pos] = arr[i];
        max_s = std::max(max_s, pos + 1);
    }
    std::cout << max_s << std::endl;
}