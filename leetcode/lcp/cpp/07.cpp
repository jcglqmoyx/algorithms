#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numWays(int n, vector<vector<int>> &relation, int k) {
        vector<int> f(n);
        f[0] = 1;
        for (int i = 0; i < k; i++) {
            vector<int> next(n);
            for (auto &e: relation) {
                int src = e[0], dst = e[1];
                next[dst] += f[src];
            }
            f = next;
        }
        return f[n - 1];
    }
};