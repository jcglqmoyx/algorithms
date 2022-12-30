#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

struct Event {
    int start, end, value;

    bool operator<(const Event &p) const {
        return end < p.end;
    }
} v[N];

class Solution {
public:
    int maxValue(vector<vector<int>> &events, int k) {
        int n = (int) events.size();
        for (int i = 1; i <= n; i++) {
            v[i] = {events[i - 1][0], events[i - 1][1], events[i - 1][2]};
        }
        sort(v + 1, v + n + 1);
        int f[n + 1][k + 1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                f[i][j] = f[i - 1][j];
                int l = 0, r = i - 1;
                while (l < r) {
                    int mid = (l + r + 1) >> 1;
                    if (v[i].start > v[mid].end) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                f[i][j] = max(f[i][j], f[l][j - 1] + v[i].value);
            }
        }
        return f[n][k];
    }
};