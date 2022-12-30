#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        int map[128] = {};
        for (char c: s) {
            map[c]++;
        }
        for (char c: s) {
            if (map[c] == 1) return c;
        }
        return ' ';
    }
};