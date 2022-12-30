#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long numberOfSubstrings(string s) {
        int cnt[26] = {};
        long long res = 0;
        for (char c: s) {
            cnt[c - 'a']++;
            res += cnt[c - 'a'];
        }
        return res;
    }
};