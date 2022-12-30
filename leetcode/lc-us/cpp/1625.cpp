#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = (int) s.size();
        string res = s;
        queue<string> q;
        unordered_set<string> vis;
        q.push(s);
        while (!q.empty()) {
            string t = q.front();
            q.pop();
            res = min(res, t);
            string x = t;
            for (int i = 1; i < n; i += 2) {
                x[i] = '0' + (x[i] + a - '0') % 10;
            }
            if (vis.find(x) == vis.end()) {
                q.push(x);
                vis.insert(x);
            }
            string y = t;
            y = y.substr(n - b) + y.substr(0, n - b);
            if (vis.find(y) == vis.end()) {
                q.push(y);
                vis.insert(y);
            }
        }
        return res;
    }
};