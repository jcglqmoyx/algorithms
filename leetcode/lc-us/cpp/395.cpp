#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0;
        for (int num = 1; num <= 26; num++) {
            int cnt[123] = {0};
            int tot = 0, less = 0;
            for (int i = 0, j = 0; j < (int) s.size(); j++) {
                cnt[s[j]]++;
                if (cnt[s[j]] == 1) tot++, less++;
                if (cnt[s[j]] == k) less--;
                while (tot > num) {
                    cnt[s[i]]--;
                    if (cnt[s[i]] == 0) tot--, less--;
                    else if (cnt[s[i]] == k - 1) less++;
                    i++;
                }
                if (!less) res = max(res, j - i + 1);
            }
        }
        return res;
    }
};