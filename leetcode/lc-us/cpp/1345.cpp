#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minJumps(vector<int> &arr) {
        int n = (int) arr.size();
        if (n == 1) return 0;
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < n; i++) g[arr[i]].push_back(i);
        vector<bool> st(n);
        unordered_set<int> used;
        st[n - 1] = true;
        queue<int> q;
        int step = -1;
        q.push(n - 1);
        while (!q.empty()) {
            step++;
            for (auto it = q.size(); it; it--) {
                int t = q.front();
                q.pop();
                if (t == 0) return step;
                if (!st[t - 1]) {
                    st[t - 1] = true;
                    q.push(t - 1);
                }
                if (t + 1 < n && !st[t + 1]) {
                    st[t + 1] = true;
                    q.push(t + 1);
                }
                if (!used.count(arr[t])) {
                    used.insert(arr[t]);
                    for (int idx: g[arr[t]]) {
                        if (!st[idx]) {
                            q.push(idx);
                            st[idx] = true;
                        }
                    }
                }
            }
        }
        return n;
    }
};