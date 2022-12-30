#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> dfs(int n, int i) {
        vector<vector<int>> res;
        while (i * i <= n) {
            if (n % i == 0) {
                res.push_back({i, n / i});
                for (vector<int> &v: dfs(n / i, i)) {
                    v.push_back(i);
                    res.push_back(v);
                }
            }
            i++;
        }
        return res;
    }

public:
    vector<vector<int>> getFactors(int n) {
        return dfs(n, 2);
    }
};