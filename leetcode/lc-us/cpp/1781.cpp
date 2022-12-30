#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int res = 0, n = (int) s.size();
        for (int i = 0; i < n; i++) {
            vector<int> cnt(26);
            int max_freq = 0;
            for (int j = i; j < n; j++) {
                cnt[s[j] - 'a']++;
                max_freq = max(max_freq, cnt[s[j] - 'a']);
                int min_freq = n;
                for (int k = 0; k < 26; k++) {
                    if (cnt[k] > 0) {
                        min_freq = min(min_freq, cnt[k]);
                    }
                }
                res += max_freq - min_freq;
            }
        }
        return res;
    }
};