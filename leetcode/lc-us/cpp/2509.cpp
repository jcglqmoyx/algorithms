#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries) {
        int m = (int) queries.size();
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            int x = queries[i][0], y = queries[i][1];
            int cnt = 1;
            while (x != y) {
                if (x > y) x >>= 1;
                else y >>= 1;
                cnt++;
            }
            res[i] = cnt;
        }
        return res;
    }
};