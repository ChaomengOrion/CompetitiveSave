#include <algorithm>
#include <iostream>
#include <map>
#include <vector>


using i64 = long long;

#define string std::string
#define cin std::cin
#define cout std::cout
#define endl std::endl

#define DEBUG(n) cout << "DEBUG: " << n << endl;

class Node
{
    std::vector<Node*> nexts; // bool代表是否只能走一次
    bool isStrong, isOTH;

public:
    int id, final;

    Node(int id, bool isOTH)
        : id(id)
        , isOTH(isOTH)
    {
        final = -1;
        isStrong = false;
    }

    int Findfinal()
    {
        if (final != -1) return final;
        if (nexts.size() == 0) return id;
        int max = -1;
        for (auto& node : nexts)
        {
            if (!isOTH || node->isStrong)
                max = std::max(max, node->Findfinal());
            else
                max = std::max(max, node->id);
        }
        return max;
    }

    void AddNext(Node* next)
    {
        for (auto node : nexts)
            if (*node == *next) return;
        nexts.push_back(next);
        if (nexts.size() >= 2) isStrong = true;
    }

    inline bool operator==(const Node& other) const { return other.id == this->id; }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    std::vector<std::pair<int, int>> spec;

    for (int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        std::vector<int> vec(len);
        for (int j = 0; j < len; j++) cin >> vec[j];
        std::sort(vec.begin(), vec.end());
        bool skip = false;
        int first = -1, last = -1, specNum = -1;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == last)
            {
                if (i < vec.size() - 1) continue;
            }
            if (vec[i] == last + 1)
            {
                last = vec[i];
                if (i < vec.size() - 1) continue;
            }
            if (!skip)
            {
                skip = true;
                last += 1;
                specNum = last;
                first = last;
                i--;
                continue;
            }
            else
                break;
        }
        spec[i] = { first, last + 1 };
    }

    const int OTH = -2;
    std::map<int, Node> map;
    map.insert({ OTH, Node(OTH, true) });
    for (auto [a, b] : spec)
    {
        if (!map.contains(a)) map.insert({ a, Node(a, false) });
        if (!map.contains(b)) map.insert({ b, Node(b, false) });

        map.at(OTH).AddNext(&map.at(a));
        map.at(a).AddNext(&map.at(b));
    }
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