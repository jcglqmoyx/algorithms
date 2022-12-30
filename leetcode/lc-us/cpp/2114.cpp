#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string> &sentences) {
        int res = 0;
        for (auto &s: sentences) {
            int cnt = (int) count(s.begin(), s.end(), ' ') + 1;
            res = max(res, cnt);
        }
        return res;
    }
};