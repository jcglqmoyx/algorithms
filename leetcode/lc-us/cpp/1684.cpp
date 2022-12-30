#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string> &words) {
        int count = 0;
        int map[26] = {};
        for (char c: allowed) {
            map[c - 97]++;
        }
        for (const string &word: words) {
            bool flag = true;
            for (char c: word) {
                if (!map[c - 97]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                count++;
            }
        }
        return count;
    }
};