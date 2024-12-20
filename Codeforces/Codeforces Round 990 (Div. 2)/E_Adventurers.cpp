#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 定义城市坐标结构体
struct City {
    int x, y;
    bool operator<(const City &other) const {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }
};

// 使用二维树状数组（BIT）来处理问题
class BIT2D {
public:
    BIT2D(int maxX, int maxY) : maxX(maxX), maxY(maxY) {
        bit.assign(maxX + 1, vector<int>(maxY + 1, 0));
    }

    void update(int x, int y, int delta) {
        for (int i = x; i <= maxX; i += i & -i) {
            for (int j = y; j <= maxY; j += j & -j) {
                bit[i][j] += delta;
            }
        }
    }

    int query(int x, int y) {
        int res = 0;
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                res += bit[i][j];
            }
        }
        return res;
    }

    int queryRectangle(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }

private:
    int maxX, maxY;
    vector<vector<int>> bit;
};

// 坐标压缩
vector<int> compressCoordinates(vector<int> &coords) {
    vector<int> compressed = coords;
    sort(compressed.begin(), compressed.end());
    compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());
    return compressed;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<City> cities(n);
        vector<int> x_coords(n), y_coords(n);

        // 输入城市数据
        for (int i = 0; i < n; i++) {
            cin >> cities[i].x >> cities[i].y;
            x_coords[i] = cities[i].x;
            y_coords[i] = cities[i].y;
        }

        // 坐标离散化
        vector<int> x_compressed = compressCoordinates(x_coords);
        vector<int> y_compressed = compressCoordinates(y_coords);

        // 进行坐标离散化，将坐标映射到[1, 2, 3, ..., n]
        for (int i = 0; i < n; i++) {
            cities[i].x = lower_bound(x_compressed.begin(), x_compressed.end(), cities[i].x) - x_compressed.begin() + 1;
            cities[i].y = lower_bound(y_compressed.begin(), y_compressed.end(), cities[i].y) - y_compressed.begin() + 1;
        }

        // 创建二维树状数组，大小为压缩后坐标的最大值
        BIT2D bit(x_compressed.size(), y_compressed.size());

        // 更新树状数组，对于每个城市都要更新它的坐标
        for (int i = 0; i < n; i++) {
            bit.update(cities[i].x, cities[i].y, 1);  // 对每个城市的坐标进行更新
        }

        int bestK = 0;
        int bestX = 0, bestY = 0;

        // 遍历每个候选分割点
        for (int i = 0; i < n; i++) {
            int x0 = cities[i].x;
            int y0 = cities[i].y;

            // 查询四个区域的城市数量
            int rightUp = bit.queryRectangle(x0, y0, x_compressed.size(), y_compressed.size());
            int rightDown = bit.queryRectangle(x0, 1, x_compressed.size(), y0);
            int leftUp = bit.queryRectangle(1, y0,  x0, y_compressed.size());
            int leftDown = bit.queryRectangle(1, 1, x0, y0);

            // 计算最小的城市数量
            int minCities = min({rightUp, rightDown, leftUp, leftDown});
            bestK = max(bestK, minCities);
            if (bestK == minCities) {
                bestX = x0;
                bestY = y0;
            }
        }

        // 输出结果
        cout << bestK << "\n";
        cout << x_compressed[bestX - 1] << " " << y_compressed[bestY - 1] << "\n";
    }

    return 0;
}
