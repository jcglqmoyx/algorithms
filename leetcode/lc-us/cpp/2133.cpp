#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>> &matrix) {
        int n = (int) matrix.size();
        for (int i = 0; i < n; i++) {
            vector<int> cnt(n + 1);
            for (int j = 0; j < n; j++) {
                cnt[matrix[i][j]]++;
            }
            for (int num = 1; num <= n; num++) {
                if (!cnt[num]) return false;
            }
        }
        for (int j = 0; j < n; j++) {
            vector<int> cnt(n + 1);
            for (int i = 0; i < n; i++) {
                cnt[matrix[i][j]]++;
            }
            for (int num = 1; num <= n; num++) {
                if (!cnt[num]) return false;
            }
        }
        return true;
    }
};