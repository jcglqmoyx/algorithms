#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        stringstream ss(text);
        string word;
        unordered_map<int, vector<string>> map;
        vector<int> lengths;
        while (ss >> word) {
            int len = (int) word.size();
            if (map.find(len) == map.end()) lengths.push_back(len);
            map[len].push_back(word);
        }
        sort(lengths.begin(), lengths.end());
        map[lengths[0]][0][0] = toupper(map[lengths[0]][0][0]);
        string res;
        for (int len: lengths) {
            for (auto &w: map[len]) {
                res += w + " ";
            }
        }
        res.pop_back();
        return res;
    }
};