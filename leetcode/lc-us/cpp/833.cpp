#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets) {
        unordered_map<int, int> hash;
        int n = (int) s.size();
        for (int i = 0; i < n; i++) hash[i] = i;
        for (int i = 0; i < indices.size(); i++) {
            int idx = indices[i];
            string &src = sources[i], &tgt = targets[i];
            if (s.substr(hash[idx], src.size()) != src) continue;
            s = s.substr(0, hash[idx]) + tgt + s.substr(hash[idx] + src.size());
            int dt = (int) (tgt.size() - src.size());
            for (int j = idx; j < n; j++) hash[j] += dt;
        }
        return s;
    }
};