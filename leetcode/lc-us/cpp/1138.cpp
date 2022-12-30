#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string alphabetBoardPath(string target) {
        int x = 0, y = 0;
        vector<pair<int, int>> map(27);
        for (int i = 0; i < 26; i++) {
            map[i] = {i / 5, i % 5};
        }
        string res;
        for (char c: target) {
            auto &[a, b] = map[c - 'a'];
            if (x < a) {
                while (y != b) {
                    if (y < b) {
                        res.push_back('R');
                        y++;
                    } else if (y > b) {
                        res.push_back('L');
                        y--;
                    }
                }
                while (x != a) {
                    if (x < a) {
                        res.push_back('D');
                        x++;
                    } else if (x > a) {
                        res.push_back('U');
                        x--;
                    }
                }
            } else {
                while (x != a) {
                    if (x < a) {
                        res.push_back('D');
                        x++;
                    } else if (x > a) {
                        res.push_back('U');
                        x--;
                    }
                }
                while (y != b) {
                    if (y < b) {
                        res.push_back('R');
                        y++;
                    } else if (y > b) {
                        res.push_back('L');
                        y--;
                    }
                }
            }
            res.push_back('!');
        }
        return res;
    }
};