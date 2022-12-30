#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool check(vector<int> &ribbons, int len, int k) {
        int cnt = 0;
        for (int r: ribbons) {
            cnt += r / len;
            if (cnt >= k) break;
        }
        return cnt >= k;
    }

public:
    int maxLength(vector<int> &ribbons, int k) {
        long long sum = 0;
        int mx = 0;
        for (int r: ribbons) {
            sum += r;
            mx = max(mx, r);
        }
        if (sum < k) return 0;
        int l = 1, r = mx;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(ribbons, mid, k)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};