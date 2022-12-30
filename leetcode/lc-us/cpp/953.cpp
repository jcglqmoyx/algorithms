#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string> &words, string order) {
        int n = (int) words.size();
        int map[26] = {};
        for (int i = 0; i < 26; i++) {
            map[order[i] - 'a'] = i;
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (j == (int) words[i + 1].length() || map[words[i][j] - 'a'] > map[words[i + 1][j] - 'a']) {
                    return false;
                }
                if (map[words[i][j] - 'a'] < map[words[i + 1][j] - 'a']) {
                    break;
                }
            }
        }
        return true;
    }
};