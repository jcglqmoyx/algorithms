#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long distinctNames(vector<string> &ideas) {
        unordered_set<string> S;
        for (auto &s: ideas) S.insert(s);
        int f[26][26] = {};
        for (auto s: ideas) {
            int a = s[0] - 'a';
            for (int b = 0; b < 26; b++) {
                s[0] = b + 'a';
                if (!S.count(s)) {
                    f[a][b]++;
                }
            }
        }
        long long res = 0;
        for (auto &s: ideas) {
            int b = s[0] - 'a';
            for (int a = 0; a < 26; a++) {
                s[0] = a + 'a';
                if (!S.count(s)) {
                    res += f[a][b];
                }
            }
        }
        return res;
    }
};