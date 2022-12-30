#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        vector<string> res;
        for (string &word: words) {
            if (match(pattern, word)) {
                res.push_back(word);
            }
        }
        return res;
    }

private:
    bool match(string &a, string &b) {
        char map_a[128] = {}, map_b[128] = {};
        for (int i = 0; i < a.length(); i++) {
            if (map_a[a[i]] == 0 && map_b[b[i]] == 0) {
                map_a[a[i]] = b[i];
                map_b[b[i]] = a[i];
            } else if (map_a[a[i]] != b[i] || map_b[b[i]] != a[i]) {
                return false;
            }
        }
        return true;
    }
};