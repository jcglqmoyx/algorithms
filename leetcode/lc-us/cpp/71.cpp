#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> p;
        stringstream ss(path);
        string temp;
        while (getline(ss, temp, '/')) {
            if (temp.empty() || temp == ".") {
                continue;
            } else if (temp == ".." && !p.empty()) {
                p.pop_back();
            } else if (temp != "..") {
                p.emplace_back(temp);
            }
        }
        string res;
        for (string &str: p) res += "/" + str;
        return res.empty() ? "/" : res;
    }
};