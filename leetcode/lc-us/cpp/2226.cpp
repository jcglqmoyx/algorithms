#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;

    bool check(vector<int> &candies, int mid, LL k) {
        LL cnt = 0;
        for (int c: candies) {
            cnt += c / mid;
        }
        return cnt >= k;
    }

public:
    int maximumCandies(vector<int> &candies, long long k) {
        int l = 0, r = 1e7;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(candies, mid, k)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};