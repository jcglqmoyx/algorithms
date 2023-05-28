#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canTraverseAllPairs(vector<int> &nums) {
        int n = (int) nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        if (n > 1 && mn == 1) return false;

        vector<vector<int>> v(mx + 1);
        for (int i = 0; i < n; i++) {
            v[nums[i]].push_back(i);
        }

        bool st[mx + 1];
        memset(st, 0, sizeof st);

        int prime[mx], cnt_prime = 0;
        for (int i = 2; i <= mx; i++) {
            if (!st[i]) prime[cnt_prime++] = i;
            for (int j = 0; prime[j] * i <= mx; j++) {
                st[prime[j] * i] = true;
                if (i % prime[j] == 0) break;
            }
        }

        int p[n], sz[n], cnt_component = n;
        for (int i = 0; i < n; i++) p[i] = i, sz[i] = 1;

        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        };

        for (int i = 0; i < cnt_prime; i++) {
            int x = prime[i];
            vector<int> idx;
            for (int y = x; y <= mx; y += x) {
                if (!v[y].empty()) {
                    for (int u: v[y]) idx.push_back(u);
                }
            }
            if (idx.empty()) continue;
            int a = idx[0];
            for (int j = 1; j < idx.size(); j++) {
                int pa = find(a), pb = find(idx[j]);
                if (pa != pb) {
                    if (sz[pa] > sz[pb]) swap(pa, pb);
                    p[pa] = pb, sz[pb] += sz[pa];
                    cnt_component--;
                }
            }
        }

        return cnt_component == 1;
    }
};