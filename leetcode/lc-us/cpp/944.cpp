#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string> &strs) {
        int deletion = 0;
        int len = (int) strs.size(), wid = (int) strs[0].size();
        for (int i = 0; i < wid; i++) {
            for (int j = 0; j < len - 1; j++) {
                if (strs[j][i] > strs[j + 1][i]) {
                    deletion++;
                    break;
                }
            }
        }
        return deletion;
    }
};