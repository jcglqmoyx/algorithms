#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bestSeqAtIndex(vector<int> &height, vector<int> &weight) {
        using PII = pair<int, int>;
        int n = (int) height.size();
        vector<PII> v(n);
        for (int i = 0; i < (int) height.size(); i++) {
            v[i] = {height[i], weight[i]};
        }
        sort(v.begin(), v.end(), [&](const PII &a, const PII &b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });
        vector<int> seq;
        for (auto &p: v) {
            int w = p.second;
            if (seq.empty() || seq.back() < w) {
                seq.push_back(w);
            } else {
                auto it = lower_bound(seq.begin(), seq.end(), w);
                *it = w;
            }
        }
        return (int) seq.size();
    }
};