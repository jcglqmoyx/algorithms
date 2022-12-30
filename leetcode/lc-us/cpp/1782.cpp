#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries) {
        vector<int> deg(n + 1);
        unordered_map<int, int> cnt;
        for (auto &e: edges) {
            int a = e[0], b = e[1];
            if (a > b) swap(a, b);
            deg[a]++, deg[b]++;
            cnt[a * (n + 1) + b]++;
        }

        vector<int> d(deg.begin() + 1, deg.end());
        sort(d.begin(), d.end());

        int m = (int) queries.size();
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            int q = queries[i];
            int s1 = 0, s2 = 0, s3 = 0;
            for (auto[k, v]: cnt) {
                int a = k / (n + 1), b = k % (n + 1);
                if (deg[a] + deg[b] - v > q) s1++;
                if (deg[a] + deg[b] > q) s3++;
            }
            for (int l = 0, r = n - 1; l < r; r--) {
                while (l < r && d[l] + d[r] <= q) l++;
                s2 += r - l;
            }
            res[i] = s1 + s2 - s3;
        }
        return res;
    }
};