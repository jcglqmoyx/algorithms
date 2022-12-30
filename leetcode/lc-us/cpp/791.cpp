#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        int count[123] = {};
        for (char c: s) count[c]++;
        string res;
        for (char c: order) {
            if (count[c]) {
                for (int i = 0; i < count[c]; i++) {
                    res.push_back(c);
                }
                count[c] = 0;
            }
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (count[c]) {
                for (int i = 0; i < count[c]; i++) {
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};