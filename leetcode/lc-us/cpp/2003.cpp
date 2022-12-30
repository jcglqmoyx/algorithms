#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int> &parents, vector<int> &nums) {
        const int N = 1e5 + 5;
        int h[N], e[N], ne[N], idx;
        memset(h, -1, sizeof h), idx = 0;

        auto add = [&](int a, int b) {
            e[idx] = b, ne[idx] = h[a], h[a] = idx++;
        };

        int n = (int) parents.size();
        int node = -1;
        for (int i = 0; i < n; i++) {
            if (parents[i] != -1) {
                add(parents[i], i);
            }
            if (nums[i] == 1) node = i;
        }
        bool vis[n + 1], exist[100002] = {};
        memset(vis, false, sizeof vis);

        vector<int> res(n, 1);

        function<void(int)> collect_values = [&](int u) {
            if (vis[u]) return;
            exist[nums[u]] = true;
            vis[u] = true;
            for (int i = h[u]; ~i; i = ne[i]) {
                collect_values(e[i]);
            }
        };
        if (node == -1) return res;
        for (int mex = 1; node != -1; node = parents[node]) {
            collect_values(node);
            while (exist[mex]) mex++;
            res[node] = mex;
        }
        return res;
    }
};