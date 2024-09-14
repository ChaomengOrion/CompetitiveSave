/*
 * @lc app=leetcode.cn id=2576 lang=cpp
 *
 * [2576] 求出最多标记下标
 */

// @lc code=start
#include <bits/stdc++.h>
template <int B, class T>
void radixSort(std::vector<T> &a) {
    const int mask = (1 << B) - 1, n = a.size();

    std::vector<T> b(n);
    std::vector<int> cnt(1 << B);

    T maxV = *std::max_element(begin(a), end(a));

    for (int i = 0; maxV; i += B, maxV >>= B) {
        std::fill(begin(cnt), end(cnt), 0);
        for (int j = 0; j < n; j++)
            cnt[a[j] >> i & mask] += 1;
        for (int j = 1; j < (1 << B); j++)
            cnt[j] += cnt[j - 1];
        for (int j = n - 1; j >= 0; j--)
            b[--cnt[a[j] >> i & mask]] = a[j];
        std::swap(a, b);
    }
}

class Solution {
public:
    int maxNumOfMarkedIndices(std::vector<int>& nums) {
        const int n = nums.size();
        if (n < 2) return 0;
        static constexpr int B = 15;
        if (n < (1 << B) / 5) {
            std::sort(nums.begin(), nums.end());
        } else {
            radixSort<B>(nums);
        }
        int cnt = 0, l = 0, lsize = n >> 1;
        std::vector<int>::iterator r = nums.begin() + (n >> 1);
        while (true) {
            while(r != nums.end() && nums[l] * 2 > *r) r++;
            if (r == nums.end()) return cnt;
            cnt += 2;
            if (++l >= lsize) return cnt;
            r++;
        }
    }
};
// @lc code=end

