#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findBlackPixel(vector<vector<char>> &picture, int target) {
        int res = 0, n = (int) picture.size(), m = (int) picture[0].size();
        vector<int> r(n), c(m);
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (picture[i][j] == 'B') {
                    cnt++;
                }
            }
            r[i] = cnt;
        }
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (picture[i][j] == 'B') {
                    cnt++;
                }
            }
            c[j] = cnt;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (picture[i][j] == 'B' && r[i] == target && c[j] == target) {
                    int cnt = 0;
                    for (int row = 0; row < n; row++) {
                        if (row == i) continue;
                        if (picture[row] == picture[i]) cnt++;
                    }
                    if (cnt == target - 1) res++;
                }
            }
        }
        return res;
    }
};