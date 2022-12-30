#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool check(string &query, string &pattern) {
        int m = (int) query.size(), n = (int) pattern.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            while (i < m && query[i] != pattern[j]) {
                if (isupper(query[i])) {
                    return false;
                }
                i++;
            }
            i++;
            j++;
        }
        if (i > m || j < n) return false;
        while (i < m) {
            if (isupper(query[i++])) return false;
        }
        return true;
    }

public:
    vector<bool> camelMatch(vector<string> &queries, string pattern) {
        int n = (int) queries.size();
        vector<bool> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = check(queries[i], pattern);
        }
        return res;
    }
};