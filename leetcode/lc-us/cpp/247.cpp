#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return dfs(n, n);
    }

private:
    vector<string> dfs(int n, int m) {
        if (m == 0) return {""};
        else if (m == 1) return {"0", "1", "8"};
        vector<string> prev = dfs(n, m - 2);
        vector<string> res;
        for (string &str: prev) {
            res.push_back("1" + str + "1");
            res.push_back("8" + str + "8");
            res.push_back("6" + str + "9");
            res.push_back("9" + str + "6");
            if (m < n) res.push_back("0" + str + "0");
        }
        return res;
    }
};