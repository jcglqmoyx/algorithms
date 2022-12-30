#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string> &words) {
        vector<string> res;
        int map[128] = {0};
        map['a'] = 1;
        map['s'] = 1;
        map['d'] = 1;
        map['f'] = 1;
        map['g'] = 1;
        map['h'] = 1;
        map['j'] = 1;
        map['k'] = 1;
        map['l'] = 1;
        map['A'] = 1;
        map['S'] = 1;
        map['D'] = 1;
        map['F'] = 1;
        map['G'] = 1;
        map['H'] = 1;
        map['J'] = 1;
        map['K'] = 1;
        map['L'] = 1;
        map['z'] = 2;
        map['x'] = 2;
        map['c'] = 2;
        map['v'] = 2;
        map['b'] = 2;
        map['n'] = 2;
        map['m'] = 2;
        map['Z'] = 2;
        map['X'] = 2;
        map['C'] = 2;
        map['V'] = 2;
        map['B'] = 2;
        map['N'] = 2;
        map['M'] = 2;
        for (string word: words) {
            int row = map[word[0]];
            bool flag = true;
            for (int i = 1; i < word.length(); i++) {
                if (map[word[i]] != row) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(word);
            }
        }
        return res;
    }
};