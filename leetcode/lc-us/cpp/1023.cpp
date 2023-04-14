#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern) {
        auto n = queries.size();
        vector<bool> res(n, true);
        for (int i = 0; i < n; i++) {
            int p = 0;
            for (char c: queries[i]) {
                if (p < pattern.size() && c == pattern[p]) p++;
                else if (isupper(c)) {
                    res[i] = false;
                    break;
                }
            }
            if (p < pattern.size()) res[i] = false;
        }
        return res;
    }
};