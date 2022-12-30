#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfStrings(vector<string> &patterns, string word) {
        int cnt = 0;
        for (string &p: patterns) {
            if (word.find(p) != -1) cnt++;
        }
        return cnt;
    }
};