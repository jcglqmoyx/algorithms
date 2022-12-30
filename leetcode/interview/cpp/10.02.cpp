#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> map;
        for (string &str: strs) {
            string s = str;
            sort(s.begin(), s.end());
            map[s].push_back(str);
        }
        for (auto &x: map) anagrams.push_back(x.second);
        return anagrams;
    }
};