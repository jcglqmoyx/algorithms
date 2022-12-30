#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string> &strings) {
        unordered_map<string, vector<string>> map;
        for (string &str: strings) {
            char c = str[0];
            string key;
            for (char ch: str) {
                key.push_back((char) ((ch - c + 26) % 26));
            }
            map[key].push_back(str);
        }
        vector<vector<string>> groups;
        groups.reserve(map.size());
        for (const auto &x: map) {
            groups.push_back(x.second);
        }
        return groups;
    }
};