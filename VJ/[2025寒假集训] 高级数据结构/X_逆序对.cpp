#include <bits/stdc++.h>

using i64 = long long;

#define LOG(...) std::cerr << "Line[" << __LINE__ << "]: " << __VA_ARGS__ << std::endl;
#define LOGV(_vec, _size)                         \
    std::cerr << #_vec << " = " << '[';           \
    for (int _i = 0; _i < (_size); _i++) {        \
        std::cerr << (_vec)[_i];                  \
        if (_i != (_size) - 1) std::cerr << ", "; \
    }                                             \
    std::cerr << ']' << std::endl;

int n, a[500010], c[500010];
i64 ans;

void msort(int l, int r) // 归并排序
{
    if (l == r) return;
    int mid = (l + r) / 2, i = l, j = mid + 1, k = l;
    msort(l, mid), msort(mid + 1, r);
    while (i <= mid && j <= r)
        if (a[i] <= a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++], ans += mid - i + 1; // 统计答案
    while (i <= mid) c[k++] = a[i++];
    while (j <= r) c[k++] = a[j++];
    for (int l = l; l <= r; l++) a[l] = c[l];
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    msort(1, n);
    std::cout << ans << std::endl;
    return 0;
}