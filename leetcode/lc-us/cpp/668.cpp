#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool check(int m, int n, int mx, int k) {
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            cnt += min(n, mx / i);
        }
        return cnt >= k;
    }

public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = k;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(m, n, mid, k)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};