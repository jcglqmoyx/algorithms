#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> getDistances(vector<int> &arr) {
        using LL = long long;
        const int N = 1e5 + 5;

        vector<vector<int>> indices(N, vector<int>());
        int size = (int) arr.size();
        for (int i = 0; i < size; i++) {
            indices[arr[i]].push_back(i);
        }
        vector<LL> res(size);
        for (int i = 0; i < N; i++) {
            if (!indices[i].empty()) {
                LL l = 0, r = 0;
                for (int idx: indices[i]) {
                    r += idx;
                }
                int n = (int) indices[i].size();
                for (int j = 0; j < n; j++) {
                    l += indices[i][j];
                    r -= indices[i][j];
                    res[indices[i][j]] = r - (LL) (n - j - 1) * indices[i][j] + (LL) indices[i][j] * (j + 1) - l;
                }
            }
        }
        return res;
    }
};