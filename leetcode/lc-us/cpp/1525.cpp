#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSplits(string s) {
        int n = (int) s.size();
        int res = 0;
        int l[26] = {}, r[26] = {};
        l[s[0] - 'a']++;
        for (int i = 1; i < n; i++) {
            r[s[i] - 'a']++;
        }
        if (valid(l, r)) res++;
        for (int i = 1; i < n - 1; i++) {
            l[s[i] - 'a']++;
            r[s[i] - 'a']--;
            if (valid(l, r)) res++;
        }
        return res;
    }

private:
    static bool valid(const int *l, const int *r) {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < 26; i++) {
            if (l[i]) cnt1++;
            if (r[i]) cnt2++;
        }
        return cnt1 == cnt2;
    }
};