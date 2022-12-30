#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int n = (int) s.size();
        vector<vector<int>> pos(26);
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) pos[s[i] - 'a'].push_back(i);
        for (auto &v: pos) reverse(v.begin(), v.end());
        for (int i = n - 1, j = 0; i >= 0; i--) {
            if (s[i] == letter) j++;
            cnt[i] = j;
        }
        int cur = -1;
        string res;
        while (k--) {
            for (int i = 0; i < 26; i++) {
                while (!pos[i].empty() && pos[i].back() <= cur) pos[i].pop_back();
                if (!pos[i].empty()) {
                    int p = pos[i].back();
                    if (cnt[p] < repetition || n - p <= k) continue;
                    if (i != letter - 'a' && k < repetition) continue;
                    res.push_back((char) (i + 'a'));
                    pos[i].pop_back();
                    if (i == letter - 'a') repetition--;
                    cur = p;
                    break;
                }
            }
        }
        return res;
    }
};