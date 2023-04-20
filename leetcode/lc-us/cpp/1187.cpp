#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        int n = (int) arr1.size(), m = (int) arr2.size(), INF = 0x3f3f3f3f;
        m = min(n, m);
        arr2.push_back(INF + 5);
        int f[m + 1];
        memset(f, 0x3f, sizeof f);
        f[0] = arr1[0];
        for (int i = 1; i <= m; i++) f[i] = min(arr1[0], arr2[0]);
        for (int i = 1; i < n; i++) {
            int g[m + 1];
            memset(g, 0x3f, sizeof g);
            for (int j = 0; j <= m; j++) {
                if (arr1[i] > f[j]) g[j] = arr1[i];
                if (j > 0) {
                    g[j] = min(g[j], *upper_bound(arr2.begin(), arr2.end(), f[j - 1]));
                }
            }
            memcpy(f, g, sizeof g);
        }
        for (int i = 0; i <= m; i++) {
            if (f[i] < INF) return i;
        }
        return -1;
    }
};