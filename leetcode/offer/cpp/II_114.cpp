#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string> &words) {
        unordered_map<char, unordered_set<char>> path;
        unordered_map<char, int> degree;
        unordered_set<char> letters;
        for (auto &w: words) {
            for (char c: w) {
                letters.insert(c);
            }
        }
        for (int i = 0; i + 1 < words.size(); i++) {
            string &s = words[i], &t = words[i + 1];
            int k = (int) min(s.size(), t.size());
            for (int j = 0; j < k; j++) {
                if (s[j] != t[j]) {
                    if (!path[s[j]].count(t[j])) {
                        degree[t[j]]++;
                        path[s[j]].insert(t[j]);
                    }
                    break;
                } else if (j == k - 1 && words[i].size() > words[i + 1].size()) {
                    return "";
                }
            }
        }
        string res;
        queue<char> q;
        for (char c: letters) {
            if (!degree.count(c)) {
                q.push(c);
            }
        }
        while (!q.empty()) {
            char t = q.front();
            q.pop();
            res.push_back(t);
            for (char ne: path[t]) {
                if (--degree[ne] == 0) {
                    q.push(ne);
                }
            }
        }
        if (res.size() == letters.size()) return res;
        return "";
    }
};