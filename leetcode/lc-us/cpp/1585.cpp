#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isTransformable(string s, string t) {
        deque<int> idx[10];
        int n = (int) s.size();
        for (int i = 0; i < n; ++i) {
            idx[s[i] - '0'].push_back(i);
        }

        int rec_idx[10];
        memset(rec_idx, -1, sizeof(rec_idx));

        for (int i = 0; i < n; ++i) {
            int num = t[i] - '0';
            if (idx[num].empty()) return false;
            rec_idx[num] = idx[num].front();
            idx[num].pop_front();
            for (int j = num + 1; j < 10; ++j) {
                if (rec_idx[j] != -1 && rec_idx[j] > rec_idx[num]) return false;
            }
        }
        return true;
    }
};