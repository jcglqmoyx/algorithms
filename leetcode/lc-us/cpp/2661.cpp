#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
        int n = (int) mat.size(), m = (int) mat[0].size();
        int r[n], c[m];
        memset(r, 0, sizeof r);
        memset(c, 0, sizeof c);
        unordered_map<int, pair<int, int>> M;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) M[mat[i][j]] = {i, j};
        for (int i = 0; i < arr.size(); i++) {
            int x = M[arr[i]].first, y = M[arr[i]].second;
            r[x]++, c[y]++;
            if (r[x] == m || c[y] == n) return i;
        }
        return 0;
    }
};