#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        const int N = 10005;
        int n = (int) org.size();
        unordered_set<int> s;
        for (auto &seq: seqs) {
            for (int e: seq) {
                if (e < 1 || e > n) return false;
                s.insert(e);
            }
        }
        if (s.size() != n) return false;

        int degree[N] = {};
        unordered_map<int, vector<int>> ne;
        for (auto &seq: seqs) {
            for (int i = 0; i < seq.size() - 1; i++) {
                degree[seq[i + 1]]++;
                ne[seq[i]].push_back(seq[i + 1]);
            }
        }
        vector<int> res;
        res.reserve(n);
        queue<int> q;
        q.push(org[0]);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            res.push_back(t);
            int cnt = 0;
            for (int i: ne[t]) {
                if (--degree[i] == 0) {
                    q.push(i);
                    cnt++;
                }
                if (cnt > 1) return false;
            }
        }
        return res == org;
    }
};