#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int> &data) {
        int n = (int) data.size();
        int tot = 0;
        for (int i = 0; i < n; i++) {
            if (data[i] == 1) tot++;
        }
        if (!tot) return 0;
        int cnt = 0;
        int res = n;
        for (int l = 0, r = 0; r < n; r++) {
            if (data[r] == 1) cnt++;
            if (r - l + 1 > tot) {
                if (data[l] == 1) cnt--;
                l++;
            }
            res = min(res, tot - cnt);
        }
        return res;
    }
};