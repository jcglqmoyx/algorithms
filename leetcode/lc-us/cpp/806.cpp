#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int> &widths, string S) {
        int lines = 1;
        int wid = 100;
        for (char c: S) {
            if (wid >= widths[c - 'a']) {
                wid -= widths[c - 'a'];
            } else {
                lines++;
                wid = 100 - widths[c - 'a'];
            }
        }
        return {lines, 100 - wid};
    }
};