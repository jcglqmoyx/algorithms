#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string> &words, string pref) {
        int cnt = 0;
        for (auto &w: words) {
            if (w.size() < pref.size()) continue;
            if (w.substr(0, pref.size()) == pref) cnt++;
        }
        return cnt;
    }
};