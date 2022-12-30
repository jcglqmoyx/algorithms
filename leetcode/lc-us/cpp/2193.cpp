#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = (int) s.size();
        int res = 0;
        int cnt[123] = {};
        for (char c: s) cnt[c]++;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                bool flag = false;
                if (cnt[s[i]] & 1) {
                    if (cnt[s[i]] > 1) {
                        cnt[s[i]] -= 2;
                    } else {
                        flag = true;
                    }
                }
                if (flag) {
                    int k = i + 1;
                    while (k < j && s[k] != s[j]) k++;
                    res += k - i;
                    while (k > i) swap(s[k], s[k - 1]), k--;
                } else {
                    int k = j - 1;
                    while (k > i && s[k] != s[i]) k--;
                    res += j - k;
                    while (k < j) swap(s[k], s[k + 1]), k++;
                }
            }
            cnt[s[i]]--, cnt[s[j]]--;
        }
        return res;
    }
};