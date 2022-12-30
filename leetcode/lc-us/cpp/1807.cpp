#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>> &knowledge) {
        unordered_map<string, string> map;
        for (auto &k: knowledge) {
            map[k[0]] = k[1];
        }
        string res;
        int n = (int) s.size();
        for (int i = 0; i < n;) {
            if (s[i] != '(') {
                res.push_back(s[i]);
                i++;
            } else {
                int j = i;
                while (j < n && s[j] != ')') {
                    j++;
                }
                string key = s.substr(i + 1, j - i - 1);
                if (map.find(key) != map.end()) {
                    res += map[key];
                } else {
                    res.push_back('?');
                }
                i = j + 1;
            }
        }
        return res;
    }
};