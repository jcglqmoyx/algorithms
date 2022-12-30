#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 > s2) return checkIfCanBreak(s2, s1);
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] > s2[i]) return false;
        }
        return true;
    }
};