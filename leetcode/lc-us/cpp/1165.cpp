#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int map[26] = {};
        for (int i = 0; i < 26; i++) {
            map[keyboard[i] - 'a'] = i;
        }
        int time = 0;
        int prev = 0;
        for (char c: word) {
            time += abs(map[c - 'a'] - prev);
            prev = map[c - 'a'];
        }
        return time;
    }
};