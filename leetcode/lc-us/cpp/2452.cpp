#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary) {
        vector<string> res;
        for (auto &q: queries) {
            bool flag = false;
            for (auto &s: dictionary) {
                int diff = 0;
                for (int i = 0; i < q.size(); i++) {
                    if (q[i] != s[i]) {
                        diff++;
                    }
                }
                if (diff <= 2) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                res.push_back(q);
            }
        }
        return res;
    }
};