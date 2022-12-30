#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int similarPairs(vector<string> &words) {
        unordered_map<int, int> cnt;
        int n = words.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (char c: words[i]) {
                mask |= 1 << (c - 'a');
            }
            res += cnt[mask];
            cnt[mask]++;
        }
        return res;
    }
};