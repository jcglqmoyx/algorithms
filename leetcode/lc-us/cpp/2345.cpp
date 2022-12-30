#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int visibleMountains(vector<vector<int>> &peaks) {
        map<pair<int, int>, int> S;
        for (auto &p: peaks) {
            int a = p[0], b = p[1];
            p[0] = a - b, p[1] = a + b;
            S[{a - b, a + b}]++;
        }
        sort(peaks.begin(), peaks.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        });
        int res = 0, n = (int) peaks.size();
        for (int i = 0; i < n; i++) {
            if (S[{peaks[i][0], peaks[i][1]}] == 1) {
                res++;
            }
            int j = i + 1;
            while (j < n && peaks[j][1] <= peaks[i][1]) {
                j++;
            }
            i = j - 1;
        }
        return res;
    }
};