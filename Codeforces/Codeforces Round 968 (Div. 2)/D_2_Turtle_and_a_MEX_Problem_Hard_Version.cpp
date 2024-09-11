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
#define DEBUGI(i, n) cout << "DEBUG[" << i << "]: " << n << endl;

class Node
{
    std::vector<Node*> nexts;
    bool isStrong, isOTH; // isStrong代表子节点大于2, isOTH代表该节点为任意数输入节点

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
        for (auto& node : nexts) {
            if (!isOTH || node->isStrong)
                max = std::max(max, node->Findfinal());
            else
                max = std::max(max, node->id);
        }
        final = max;
        return max;
    }

    void AddNext(Node* next)
    {
        for (auto node : nexts) {
            if (*node == *next) {
                isStrong = true;
                return;
            }
        }
        nexts.push_back(next);
        if (nexts.size() >= 2) isStrong = true;
    }

    inline bool operator==(const Node& other) const { return other.id == this->id; }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    std::vector<std::pair<int, int>> spec(n);

    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        std::vector<int> vec(len);
        for (int j = 0; j < len; j++) cin >> vec[j];
        std::sort(vec.begin(), vec.end());
        bool skip = false;
        int first = -1, last = -1;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == last) {
                if (i < vec.size() - 1) continue;
            }
            if (vec[i] == last + 1) {
                last = vec[i];
                if (i < vec.size() - 1) continue;
            }
            if (!skip) {
                skip = true;
                last += 1;
                first = last;
                i--;
                continue;
            } else
                break;
        }
        spec[i] = {first, last + 1};
    }

    const int OTH = -2;
    std::map<int, Node> map;
    map.insert({OTH, Node(OTH, true)});
    for (auto& [a, b] : spec) {
        if (!map.contains(a)) map.insert({a, Node(a, false)});
        if (!map.contains(b)) map.insert({b, Node(b, false)});

        map.at(OTH).AddNext(&map.at(a));
        map.at(a).AddNext(&map.at(b));
    }

    for (auto& [id, node] : map) {
        node.Findfinal();
    }

    int oth_mex = map.at(OTH).final;
    i64 ans = 0;

    if (m <= oth_mex) {
        ans += 1LL * oth_mex * (m + 1);
    } else {
        ans += 1LL * oth_mex * oth_mex;
        ans += ((i64)oth_mex + (i64)m) * ((i64)m - (i64)oth_mex + 1) / 2;
    }

    for (auto& [id, node] : map) {
        if (id != OTH && id <= m) {
            int mex = std::max(oth_mex, node.final);
            ans -= std::max(oth_mex, id);
            ans += std::max(mex, id);
        }
    }

    cout << ans << endl;
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