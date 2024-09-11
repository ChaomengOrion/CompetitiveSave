#include <vector>
#include <iostream>

#define cin std::cin
#define cout std::cout
#define endl std::endl

void solve()
{
    int nodeCount;
    cin >> nodeCount;
    std::vector<std::pair<int, int>> ans;
    std::vector<int> openList(nodeCount-1);
    for (int i = 1; i < nodeCount; i++) openList[i-1] = i + 1;

    auto find = [&] (auto find, int a, int b) -> void
    {
        bool ok = false;
        for (int i : openList)
        {
            if (i == a || i == b)
            {
                ok = true;
                break;
            }
        }
        if (!ok) return; // 重复查询直接跳过
        printf("? %d %d\n", a, b);
        fflush(stdout);
        int res;
        cin >> res;
        if (res == a)
        {
            ans.push_back({ a, b }); // 记录边
            for (int i = 0; i < openList.size(); i++)
            {
                if (openList[i] == a || openList[i] == b) openList.erase(openList.begin() + i);
            }
        }
        else
        {
            find(find, a, res); // 双向递归
            find(find, res, b);
        }
    };

    while (openList.size() > 0) find(find, 1, openList[0]);

    cout << '!';
    for (auto [a, b] : ans) cout << ' ' << a << ' ' << b;
    cout << endl;
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}