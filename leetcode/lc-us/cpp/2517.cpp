#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumTastiness(vector<int> &price, int k) {
        int n = (int) price.size();
        sort(price.begin(), price.end());

        auto check = [&](int mid) {
            int cnt = 1;
            for (int i = 0; i < n && cnt < k; i++) {
                int j = i + 1;
                while (j < n && price[j] - price[i] < mid) j++;
                if (j < n) cnt++;
                i = j - 1;
            }
            return cnt >= k;
        };

        int l = 0, r = 1e9;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};