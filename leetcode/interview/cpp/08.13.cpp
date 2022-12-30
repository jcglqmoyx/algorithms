#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pileBox(vector<vector<int>> &box) {
        sort(box.begin(), box.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) {
                if (a[1] == b[1]) {
                    return a[2] < b[2];
                }
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        int n = (int) box.size();
        int f[n];
        memset(f, 0, sizeof f);
        int res = 0;
        for (int i = 0; i < n; i++) {
            f[i] = box[i][2];
            for (int j = 0; j < i; j++) {
                if (box[i][0] > box[j][0] && box[i][1] > box[j][1] && box[i][2] > box[j][2]) {
                    f[i] = max(f[i], f[j] + box[i][2]);
                }
            }
            res = max(res, f[i]);
        }
        return res;
    }
};