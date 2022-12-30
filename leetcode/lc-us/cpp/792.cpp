#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string> &words) {
        int cnt = 0;
        vector<vector<int>> pos(26, vector<int>());
        for (int i = 0; i < (int) s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        for (auto &w: words) {
            if (valid(pos, w)) {
                cnt++;
            }
        }
        return cnt;
    }

private:
    bool valid(vector<vector<int>> &pos, string &w) {
        int f[26] = {};
        int prev = -1;
        for (char c: w) {
            int idx = c - 'a';
            if (f[idx] >= (int) pos[idx].size()) return false;
            int l = f[idx], r = (int) pos[idx].size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (pos[idx][mid] > prev) r = mid;
                else l = mid + 1;
            }
            if (l == (int) pos[idx].size()) return false;
            prev = pos[idx][l];
            f[idx] = l + 1;
        }
        return true;
    }
};