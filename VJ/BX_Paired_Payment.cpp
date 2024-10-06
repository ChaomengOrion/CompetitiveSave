#include <bits/stdc++.h>

using namespace std;
template<typename T> bool minimize(T &a, const T &b) {if(a > b){a = b; return true;} return false;}
typedef pair<int, int> pp;
const int N = int(1e5) + 1, INF = int(2.1e9);
int n, d[N];
vector<pp> G[N];

void dijkstra(const int &src)
{
    fill(d + 1, d + n + 1, INF);
    d[src] = 0;
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    pq.push({0, src});
    auto sqr = [](int x) -> int {
        return x * x;
    };
    while(pq.size()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if(du != d[u]) continue;
        for(const pp &w : G[u]) {
            for(const pp &v : G[w.second]) {
                if(v.second == u) continue;
                if(minimize(d[v.second], du + sqr(w.first + v.first)))
                    pq.push({d[v.second], v.second});
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
    int m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({w, v});
        G[v].push_back({w, u});
    }
    dijkstra(1);
    for(int i = 1; i <= n; ++i) cout << (d[i] == INF ? -1 : d[i]) << ' ';
	return 0;
}