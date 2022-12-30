#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int cnt1[123] = {}, cnt2[123] = {};
        for (char c: s) cnt1[c]++;
        for (char c: target) cnt2[c]++;
        int res = 1e8;
        for (char c: target) res = min(res, cnt1[c] / cnt2[c]);
        return res;
    }
};