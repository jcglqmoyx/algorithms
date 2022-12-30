#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;

    map<string, int> dfs(string &s, int &u) {
        map<string, int> res;

        while (u < n) {
            if (s[u] == '(') {
                u++;
                auto t = dfs(s, u);
                u++;
                int cnt = 1, k = u;
                while (k < n && isdigit(s[k])) k++;
                if (k > u) cnt = stoi(s.substr(u, k - u));
                u = k;
                for (auto &[atom, num]: t) res[atom] += num * cnt;
            } else if (s[u] == ')') {
                break;
            } else {
                int k = u + 1;
                while (k < n && islower(s[k])) k++;
                string key = s.substr(u, k - u);
                u = k;
                int cnt = 1;
                while (k < s.size() && isdigit(s[k])) k++;
                if (k > u) cnt = stoi(s.substr(u, k - u));
                u = k;
                res[key] += cnt;
            }
        }
        return res;
    }

public:
    string countOfAtoms(string formula) {
        int k = 0;
        n = (int) formula.size();
        auto t = dfs(formula, k);
        string res;
        for (auto &[atom, num]: t) {
            res += atom;
            if (num > 1) res += to_string(num);
        }
        return res;
    }
};