#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        unordered_map<string, vector<string>> map;
        for (string &p: paths) {
            stringstream ss(p);
            string root;
            ss >> root;

            string file;
            while (ss >> file) {
                size_t l = file.find('(');
                string content = file.substr(l + 1, file.size() - l);
                map[content].push_back(root + "/" + file.substr(0, l));
            }
        }
        vector<vector<string>> res;
        for (auto[x, y]: map) if (y.size() > 1) res.push_back(y);
        return res;
    }
};