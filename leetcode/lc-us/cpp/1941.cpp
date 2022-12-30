#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> map;
        for (char c: s) map[c]++;
        int cnt = 0;
        for (auto[k, v]: map) {
            if (cnt == 0) cnt = v;
            else if (cnt != v) return false;
        }
        return true;
    }
};