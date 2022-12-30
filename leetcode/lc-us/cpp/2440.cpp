#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int componentValue(vector<int> &nums, vector<vector<int>> &edges) {
        int mx = *max_element(nums.begin(), nums.end());
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int n = (int) nums.size();
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int target;
        function<int(int, int)> dfs = [&](int u, int p) -> int {
            int sum = nums[u];
            for (int x: g[u]) {
                if (x == p) continue;
                int t = dfs(x, u);
                if (t == -1) return -1;
                sum += t;
            }
            if (sum > target) return -1;
            return sum < target ? sum : 0;
        };
        for (int i = tot / mx;; i--) {
            if (tot % i) continue;
            target = tot / i;
            if (dfs(0, -1) == 0) return i - 1;
        }
    }
};