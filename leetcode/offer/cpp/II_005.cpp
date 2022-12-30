#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string> &words) {
        int n = (int) words.size(), res = 0;
        vector<int> mask(n);
        for (int i = 0; i < n; i++) {
            int m = 0;
            for (char c: words[i]) {
                m |= 1 << (c - 'a');
            }
            mask[i] = m;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if ((mask[i] & mask[j]) == 0) res = max(res, (int) words[i].size() * (int) words[j].size());
                }
            }
        }
        return res;
    }
};