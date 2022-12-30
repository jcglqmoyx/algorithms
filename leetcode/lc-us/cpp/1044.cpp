#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestDupSubstring(string s) {
        using ULL = unsigned long long;
        const int P = 131;

        int n = (int) s.size();
        vector<ULL> h(n + 1), p(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + s[i - 1];
        }
        string res;
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            unordered_set<ULL> set;
            bool exist = false;
            for (int i = 1; i + mid - 1 <= n; i++) {
                ULL hash = h[i + mid - 1] - h[i - 1] * p[mid];
                if (set.count(hash)) {
                    if (mid > (int) res.size()) {
                        res = s.substr(i - 1, mid);
                        exist = true;
                    }
                }
                set.insert(hash);
            }
            if (exist) l = mid;
            else r = mid - 1;
        }
        return res;
    }
};