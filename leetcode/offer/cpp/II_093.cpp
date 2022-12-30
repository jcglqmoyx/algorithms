#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int> &arr) {
        int n = (int) arr.size(), res = 0;
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) index[arr[i]] = i;
        vector<vector<int>> f(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int x = arr[i] - arr[j];
                f[i][j] = 2;
                if (index.count(x) && x < arr[j]) {
                    f[i][j] = max(f[i][j], f[j][index[x]] + 1);
                }
                res = max(res, f[i][j]);
            }
        }
        return res < 3 ? 0 : res;
    }
};