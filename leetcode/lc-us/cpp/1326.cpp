#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int> &ranges) {
        using PII = pair<int, int>;
        vector<PII> v;
        v.reserve(n + 1);
        for (int i = 0; i < n + 1; i++) {
            v.emplace_back(max(0, i - ranges[i]), min(n, i + ranges[i]));
        }
        sort(v.begin(), v.end());
        if (v.begin()->first) return -1;
        int cnt = 0;
        int end = 0;
        for (int i = 0; i < n + 1 && end < n; i++) {
            cnt++;
            int right_most = end;
            int j = i;
            while (j < n + 1 && v[j].first <= end) {
                right_most = max(right_most, v[j].second);
                j++;
            }
            if (j == i) return -1;
            end = right_most;
            i = j - 1;
        }
        if (end < n) return -1;
        return cnt;
    }
};