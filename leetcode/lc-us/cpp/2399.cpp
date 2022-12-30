#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int> &distance) {
        int pos[26] = {};
        memset(pos, -1, sizeof pos);
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            if (pos[idx] >= 0) {
                if (i - pos[idx] - 1 != distance[idx]) {
                    return false;
                }
            } else {
                pos[idx] = i;
            }
        }
        return true;
    }
};