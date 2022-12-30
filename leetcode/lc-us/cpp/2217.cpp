#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;

    int get_tot(int len) {
        int res = 9;
        for (int i = 0; i < (len - 1) / 2; i++) res *= 10;
        return res;
    }

public:
    vector<long long> kthPalindrome(vector<int> &queries, int intLength) {
        int tot = get_tot(intLength);
        vector<LL> res;
        int base = 1;
        for (int i = 0; i < (intLength - 1) >> 1; i++) base *= 10;
        for (int q: queries) {
            if (q > tot) res.push_back(-1);
            else {
                int left = base + q - 1;
                vector<int> v;
                while (left) {
                    v.push_back(left % 10);
                    left /= 10;
                }
                reverse(v.begin(), v.end());
                if (intLength >= 2)
                    for (int i = (intLength - 2) / 2; i >= 0; i--) {
                        v.push_back(v[i]);
                    }
                LL x = 0;
                for (int d: v) x = x * 10 + d;
                res.push_back(x);
            }
        }
        return res;
    }
};