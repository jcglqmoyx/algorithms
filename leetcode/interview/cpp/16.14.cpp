#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool on_same_line(const vector<int> &a, const vector<int> &b, const vector<int> &c) const {
        return (long long) (a[0] - b[0]) * (b[1] - c[1]) == (long long) (a[1] - b[1]) * (b[0] - c[0]);
    }

public:
    vector<int> bestLine(vector<vector<int>> &points) {
        int n = (int) points.size();
        vector<int> res;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (n - i <= mx) break;
            unordered_set<int> S;
            for (int j = i + 1; j < n; j++) {
                if (S.count(j)) {
                    continue;
                }
                int cnt = 2;
                for (int k = j + 1; k < n; k++) {
                    if (on_same_line(points[i], points[j], points[k])) {
                        S.insert(k);
                        cnt++;
                    }
                }
                if (cnt > mx) {
                    mx = cnt;
                    res = {i, j};
                }
            }
        }
        return res;
    }
};