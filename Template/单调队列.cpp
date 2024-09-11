#include <bits/stdc++.h>

// 关键：掐头（去掉超出窗口范围的）去尾（去掉比输入小的）

void test(std::vector<int>& vec, int maxDis) // 升序单调队列
{
    std::deque<int> dq;

    auto add = [&](int n) -> void // n: 1 -> len - 1
    {
        while (!dq.empty() && dq.front() < n - maxDis) dq.pop_front();
        // Do something
        while (!dq.empty() && vec[dq.back()] > vec[n]) dq.pop_back();
    };
}

int main()
{
    return 0;
}