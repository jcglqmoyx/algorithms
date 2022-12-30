#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int> &v) {
        sort(v.begin(), v.end());
        unordered_set<long long> S;
        for (int x: v) S.insert(x);
        int res = -1;
        for (long long x: v) {
            int len = 1;
            while (S.count(x * 1LL * x)) {
                len++;
                x = x * 1LL * x;
            }
            if (len > 1) res = max(res, len);
        }
        return res;
    }
};