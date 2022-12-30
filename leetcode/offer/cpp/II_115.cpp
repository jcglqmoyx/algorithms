#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        int n = (int) org.size() + 1;
        if (org.size() == 1 && seqs.empty()) return false;

        unordered_set<int> set;
        for (auto &seq: seqs) {
            for (int x: seq) {
                set.insert(x);
            }
        }
        if (set.size() != org.size()) return false;
        for (int x: org) if (!set.count(x)) return false;

        vector<int> res, degree(n);
        vector<vector<int>> g(n, vector<int>());
        for (auto &s: seqs) {
            for (int i = 0; i < s.size() - 1; i++) {
                g[s[i]].push_back(s[i + 1]);
                degree[s[i + 1]]++;
            }
        }
        queue<int> q;
        for (int i = 1; i < n; i++) {
            if (degree[i] == 0) {
                q.push(i);
                res.push_back(i);
            }
        }
        while (!q.empty()) {
            if (q.size() != 1) return false;
            int t = q.front();
            q.pop();
            for (int ne: g[t]) {
                if (--degree[ne] == 0) {
                    q.push(ne);
                    res.push_back(ne);
                }
            }
        }
        return res == org;
    }
};