#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
        int m = (int) edges.size();
        int p[n], sz[n], cnt;
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        };

        for (int i = 0; i < m; i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });

        function<int(int)> add = [&](int i) -> int {
            int x = edges[i][0], y = edges[i][1];
            int px = find(x), py = find(y);
            if (px != py) {
                if (sz[px] > sz[py]) swap(px, py);
                p[px] = py;
                sz[py] += sz[px];
                cnt--;
                return edges[i][2];
            }
            return 0;
        };

        function<int(int)> get1 = [&](int k) -> int {
            for (int i = 0; i < n; i++) p[i] = i, sz[i] = 1;
            cnt = n;
            int res = 0;
            for (int i = 0; i < m && cnt > 1; i++) {
                if (i != k) res += add(i);
            }
            return cnt == 1 ? res : INT32_MAX;
        };
        function<int(int)> get2 = [&](int k) -> int {
            for (int i = 0; i < n; i++) p[i] = i, sz[i] = 1;
            cnt = n;
            int res = add(k);
            for (int i = 0; i < m && cnt > 1; i++) {
                if (i != k) res += add(i);
            }
            return cnt == 1 ? res : INT32_MAX;
        };
        int mst = get1(m);
        vector<vector<int>> res(2);
        for (int i = 0; i < m; i++) {
            int len1 = get1(i), len2 = get2(i);
            if (len1 > mst) res[0].push_back(edges[i][3]);
            if (len1 == mst && len2 == mst) res[1].push_back(edges[i][3]);
        }
        return res;
    }
};