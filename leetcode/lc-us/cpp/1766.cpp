#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10, M = N << 1;

int h[N], e[M], ne[M], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
public:
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges) {
        int n = (int) nums.size();
        memset(h, -1, sizeof h), idx = 0;
        for (auto &edge: edges) {
            add(edge[0], edge[1]), add(edge[1], edge[0]);
        }
        vector<int> res(n, -1);

        int max_value = *max_element(nums.begin(), nums.end());
        vector<pair<int, int>> v(max_value + 1, {-1, -1});

        function<int(int, int)> gcd = [&](int x, int y) -> int {
            return x % y ? gcd(y, x % y) : y;
        };

        bool st[n];
        memset(st, false, sizeof st);

        function<void(int, int)> dfs = [&](int u, int current_depth) {
            if (st[u]) return;
            st[u] = true;
            int max_depth = -1;
            for (int num = 1; num <= max_value; num++) {
                if (gcd(num, nums[u]) > 1) continue;
                int depth = v[num].first, node = v[num].second;
                if (depth == -1) continue;
                if (depth > max_depth) {
                    max_depth = depth;
                    res[u] = node;
                }
            }
            int x = v[nums[u]].first, y = v[nums[u]].second;
            v[nums[u]] = {current_depth, u};

            for (int i = h[u]; ~i; i = ne[i]) {
                int j = e[i];
                dfs(j, current_depth + 1);
            }
            v[nums[u]] = {x, y};
        };
        dfs(0, 0);
        return res;
    }
};