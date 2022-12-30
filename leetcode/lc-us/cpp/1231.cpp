#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximizeSweetness(vector<int> &sweetness, int k) {
        int n = (int) sweetness.size();
        auto check = [&](int tot) {
            int cnt = 0;
            int i = 0;
            while (i < n) {
                int j = i, s = 0;
                while (j < n && s < tot) {
                    s += sweetness[j];
                    j++;
                }
                if (s >= tot) cnt++;
                i = j;
            }
            return cnt >= k + 1;
        };
        int l = 0, r = 1e9;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};