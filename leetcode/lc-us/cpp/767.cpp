#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> cnt;
        int n = (int) s.size();
        int max_cnt = 0;
        for (char c: s) {
            cnt[c]++;
            if (cnt[c] > max_cnt) max_cnt = cnt[c];
        }
        if (max_cnt > (n + 1) / 2) return "";
        string res(n, ' ');
        int i = 1, j = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (cnt[c] <= n / 2) {
                while (cnt[c] && i < n) {
                    res[i] = c;
                    cnt[c]--;
                    i += 2;
                }
            }
            while (cnt[c]) {
                res[j] = c;
                cnt[c]--;
                j += 2;
            }
        }
        return res;
    }
};