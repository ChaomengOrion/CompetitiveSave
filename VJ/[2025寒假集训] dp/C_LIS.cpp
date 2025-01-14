#include <bits/stdc++.h>

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size) std::cerr << #_vec << " = " << '['; for (int _i = 0; _i < (_size); _i++) { std::cerr << (_vec)[_i]; if (_i != (_size) - 1) std::cerr << ", "; } std::cerr << ']' << std::endl;

int main() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    int size = arr.size();
    std::vector<int> low(size, INT_MAX);
    int max_s = 0;
    for (int i = 0; i < size; i++) {
        int pos = std::lower_bound(low.begin(), low.end(), arr[i]) - low.begin();
        low[pos] = arr[i];
        max_s = std::max(max_s, pos + 1);
    }
    std::cout << max_s << std::endl;
    //LOGV(low, size)
}