#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int> &bulbs, int k) {
        const int INF = 1e9;
        int n = (int) bulbs.size(), res = INF;
        int day[n];
        for (int i = 0; i < n; i++) {
            day[bulbs[i] - 1] = i + 1;
        }
        int l = 0;
        while (true) {
            int r = l + k + 1;
            if (r >= n) break;
            bool flag = true;
            for (int i = l + 1; i < r; i++) {
                if (day[i] < day[l] || day[i] < day[r]) {
                    flag = false;
                    l = i;
                    break;
                }
            }
            if (!flag) continue;
            if (l + k + 1 < n) res = min(res, max(day[l], day[l + k + 1]));
            l++;
        }
        return res == INF ? -1 : res;
    }
};