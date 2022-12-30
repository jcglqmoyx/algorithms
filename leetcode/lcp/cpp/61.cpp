#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get(int x, int y) {
        if (x == y) return 0;
        if (x < y) return -1;
        return 1;
    }

public:
    int temperatureTrend(vector<int> &a, vector<int> &b) {
        int res = 0;
        int n = (int) a.size();
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && get(a[j - 1], a[j]) == get(b[j - 1], b[j])) j++;
            res = max(res, j - i - 1);
            i = j - 1;
        }
        return res;
    }
};