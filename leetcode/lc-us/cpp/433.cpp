#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool valid(string &s, string &t) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) {
                cnt++;
            }
        }
        return cnt == 1;
    }

    int minMutation(string start, string end, vector<string> &bank) {
        unordered_set<string> visited;
        queue<string> q;
        int step = -1;
        q.push(start);
        bool flag = false;
        while (!q.empty()) {
            if (flag) break;
            step++;
            for (auto it = q.size(); it; it--) {
                string &t = q.front();
                if (t == end) {
                    flag = true;
                    break;
                }
                q.pop();
                for (string &s: bank) {
                    if (visited.find(s) == visited.end() && valid(s, t)) {
                        q.push(s);
                        visited.insert(s);
                    }
                }
            }
        }
        return flag ? step : -1;
    }
};