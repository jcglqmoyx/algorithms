#include <bits/stdc++.h>

using namespace std;

using VI = vector<int>;
using VVI = vector<vector<int>>;

const int N = 1010, M = 2010, INF = 0x3f3f3f3f;

int f[N][M];
int h[N], w[M << 1], e[M << 1], ne[M << 1], idx;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
public:
    int minimumCost(int n, vector<vector<int>> &highways, int discounts) {
        memset(f, 0x3f, sizeof f), memset(h, -1, sizeof h), idx = 0;
        for (auto &way: highways) {
            int x = way[0], y = way[1], z = way[2];
            add(x, y, z), add(y, x, z);
        }
        priority_queue<VI, VVI, greater<>> heap;
        heap.push({0, 0, 0});
        for (int i = 0; i <= discounts; i++) f[0][i] = 0;
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            int cost = t[0], u = t[1], cnt = t[2];
            if (u == n - 1) return cost;
            for (int i = h[u]; ~i; i = ne[i]) {
                int j = e[i];
                if (cost + w[i] < f[j][cnt]) {
                    f[j][cnt] = cost + w[i];
                    heap.push({f[j][cnt], j, cnt});
                }
                if (cnt < discounts && cost + w[i] / 2 < f[j][cnt + 1]) {
                    f[j][cnt + 1] = cost + w[i] / 2;
                    heap.push({f[j][cnt + 1], j, cnt + 1});
                }
            }
        }
        return f[n - 1][discounts] == INF ? -1 : f[n - 1][discounts];
    }
};