#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>> &picture) {
        unordered_set<int> row, col;
        int count = 0;
        int len = (int) picture.size(), wid = (int) picture[0].size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < wid; j++) {
                if (picture[i][j] == 'B') {
                    if (row.count(i) || col.count(j)) {
                        break;
                    }
                    bool flag = true;
                    for (int m = i + 1; m < len; m++) {
                        if (picture[m][j] == 'B') {
                            flag = false;
                            break;
                        }
                    }
                    for (int n = j + 1; n < wid; n++) {
                        if (picture[i][n] == 'B') {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        count++;
                    }
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        return count;
    }
};