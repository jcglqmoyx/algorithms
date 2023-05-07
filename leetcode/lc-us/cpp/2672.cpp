#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>> &queries) {
        int m = (int) queries.size();
        vector<int> res(m);
        int color[n];
        memset(color, 0, sizeof color);
        for (int i = 0, cnt = 0; i < m; i++) {
            int p = queries[i][0], c = queries[i][1];
            if (p && color[p - 1] && color[p] == color[p - 1]) cnt--;
            if (p < n - 1 && color[p] && color[p] == color[p + 1]) cnt--;
            if (p && color[p - 1] == c) cnt++;
            if (p < n - 1 && c == color[p + 1]) cnt++;
            color[p] = c;
            res[i] = cnt;
        }
        return res;
    }
};