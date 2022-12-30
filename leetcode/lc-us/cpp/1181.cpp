#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string> &phrases) {
        unordered_map<string, vector<int>> start_with, end_with;
        vector<string> res;
        for (int i = 0; i < phrases.size(); i++) {
            string &s = phrases[i];
            int idx = (int) s.find(' ');
            if (idx == -1) start_with[s].push_back(i), end_with[s].push_back(i);
            else {
                string start = s.substr(0, idx);
                start_with[start].push_back(i);
                idx = (int) s.rfind(' ');
                string end = s.substr(idx + 1);
                end_with[end].push_back(i);
            }
        }
        for (auto &[s, indices]: end_with) {
            if (start_with.count(s)) {
                for (int i: indices) {
                    for (int j: start_with[s]) {
                        if (i == j) continue;
                        res.push_back(phrases[i] + phrases[j].substr(s.size()));
                    }
                }
            }
        }
        unordered_set<string> set;
        for (auto &s: res) set.insert(s);
        res.clear();
        for (auto &s: set) res.push_back(s);
        sort(res.begin(), res.end());
        return res;
    }
};