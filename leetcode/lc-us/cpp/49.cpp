#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> map;
        for (const string &str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }
        anagrams.reserve(map.size());
        for (auto &x: map) {
            anagrams.push_back(x.second);
        }
        return anagrams;
    }
};