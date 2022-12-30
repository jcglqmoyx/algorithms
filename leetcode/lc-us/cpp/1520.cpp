#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        const int INF = 1e8;
        int n = (int) s.size();
        vector<vector<int>> range(26, {INF, -INF});
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            range[idx][0] = min(range[idx][0], i);
            range[idx][1] = max(range[idx][1], i);
        }
        for (int i = 0; i < 26; i++) {
            if (range[i][0] != INF) {
                for (int j = range[i][0]; j < range[i][1]; j++) {
                    int idx = s[j] - 'a';
                    int a = range[idx][0], b = range[idx][1];
                    if (range[i][0] <= a && b <= range[i][1]) continue;
                    range[i][0] = min(range[i][0], a);
                    range[i][1] = max(range[i][1], b);
                    j = range[i][0];
                }
            }
        }
        sort(range.begin(), range.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        vector<string> res;
        for (int i = 0, end = -1; i < 26; i++) {
            int l = range[i][0], r = range[i][1];
            if (l == INF) continue;
            if (l > end) {
                end = r;
                res.emplace_back(s.substr(l, r - l + 1));
            }
        }
        return res;
    }
};