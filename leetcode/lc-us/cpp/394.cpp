#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int u = 0;
        return dfs(s, u);
    }

private:
    string dfs(string &s, int &u) {
        string res;
        while (u < s.size() && s[u] != ']') {
            if (isalpha(s[u])) res.push_back(s[u++]);
            else if (isdigit(s[u])) {
                int k = u;
                while (isdigit(s[k])) k++;
                int x = stoi(s.substr(u, k));
                u = k + 1;
                string y = dfs(s, u);
                u++;
                for (int i = 0; i < x; i++) {
                    res += y;
                }
            }
        }
        return res;
    }
};