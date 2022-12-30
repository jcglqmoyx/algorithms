#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int transportationHub(vector<vector<int>> &path) {
        int in[1005], out[1005];
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        unordered_set<int> S;
        for (auto &p: path) {
            int x = p[0], y = p[1];
            out[x]++;
            in[y]++;
            S.insert(x);
            S.insert(y);
        }
        int n = (int) S.size();
        for (int i = 0; i < 1005; i++) {
            if (in[i] == n - 1 && out[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};