#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int> &colors, vector<vector<int>> &queries) {
        vector<int> res(queries.size());
        _colors = colors;
        n = (int) colors.size();
        f.resize(3, vector<int>(n, INT32_MAX));
        for (int color = 1; color <= 3; color++) init(color);
        for (int i = 0; i < queries.size(); i++) {
            int idx = queries[i][0], color = queries[i][1];
            res[i] = f[color - 1][idx];
            if (res[i] == INT32_MAX) res[i] = -1;
        }
        return res;
    }

private:
    int n;
    vector<int> _colors;
    vector<vector<int>> f;

    void init(int color) {
        bool flag = false;
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (color == _colors[i]) len = 0, flag = true;
            else len++;
            if (flag) f[color - 1][i] = min(f[color - 1][i], len);
        }
        len = 0, flag = false;
        for (int i = n - 1; i >= 0; i--) {
            if (color == _colors[i]) len = 0, flag = true;
            else len++;
            if (flag) f[color - 1][i] = min(f[color - 1][i], len);
        }
    }
};