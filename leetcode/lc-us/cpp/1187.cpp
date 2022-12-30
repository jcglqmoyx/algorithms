#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
        int n = (int) arr1.size(), m = (int) arr2.size(), INF = 2e9;
        m = min(n, m);
        sort(arr2.begin(), arr2.end());
        arr2.push_back(INF + 5);
        vector<vector<int>> f(n, vector<int>(m + 1, INF));
        f[0][0] = arr1[0];
        for (int i = 1; i <= m; i++) f[0][i] = min(arr1[0], arr2[0]);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                if (arr1[i] > f[i - 1][j]) f[i][j] = arr1[i];
                if (j > 0) {
                    f[i][j] = min(f[i][j], *upper_bound(arr2.begin(), arr2.end(), f[i - 1][j - 1]));
                }
            }
        }
        for (int i = 0; i <= m; i++) {
            if (f[n - 1][i] < INF) return i;
        }
        return -1;
    }
};