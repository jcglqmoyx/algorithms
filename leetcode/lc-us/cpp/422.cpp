#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string> &words) {
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                if (j >= words.size() || words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};