#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        int cnt[26] = {};
        for (char c: s) cnt[c - 'a']++;
        unordered_set<int> freq;
        int res = 0;
        for (int x: cnt) {
            if (x) {
                if (freq.find(x) != freq.end()) {
                    int y = x - 1;
                    while (y && freq.find(y) != freq.end()) {
                        y--;
                    }
                    res += x - y;
                    freq.insert(y);
                } else {
                    freq.insert(x);
                }
            }
        }
        return res;
    }
};