#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[128] = {};
        int len = (int) s.size();
        for (int i = 0; i < len; i++) {
            count[s[i]]++;
            count[t[i]]--;
        }
        count[t[len]]--;
        for (char c = 'a'; c <= 'z'; c++) {
            if (count[c] != 0) {
                return c;
            }
        }
        return 'a';
    }
};