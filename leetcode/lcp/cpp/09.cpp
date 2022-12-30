#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minJump(vector<int> &jump) {
        int n = (int) jump.size();
        vector<int> st(n);
        st[0] = true;
        int idx = 1;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto[pos, step] = q.front();
            q.pop();
            int r = pos + jump[pos];
            if (r >= n) return step + 1;
            if (!st[r]) {
                q.emplace(r, step + 1);
                st[r] = true;
            }
            while (idx < pos) {
                q.emplace(idx, step + 1);
                st[idx] = true;
                idx++;
            }
        }
        return -1;
    }
};