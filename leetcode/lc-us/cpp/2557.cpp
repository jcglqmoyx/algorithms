#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCount(vector<int> &banned, int n, long long maxSum) {
        sort(banned.begin(), banned.end());
        int m = (int) banned.size();
        long long s[m + 1];
        memset(s, 0, sizeof s);
        for (int i = 1; i <= m; i++) {
            s[i] = s[i - 1] + banned[i - 1];
        }

        auto get = [&](int x) {
            int l = -1, r = m - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (banned[mid] <= x) l = mid;
                else r = mid - 1;
            }
            return l;
        };

        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if ((1 + mid) * 1LL * mid / 2 - s[get(mid) + 1] <= maxSum) l = mid;
            else r = mid - 1;
        }
        return l - get(l) - 1;
    }
};