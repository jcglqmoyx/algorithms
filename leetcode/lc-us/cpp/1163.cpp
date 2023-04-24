#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
        int i = 0, j = 1, n = (int) s.size();
        while (j < n) {
            int k = 0;
            while (j + k < n && s[i + k] == s[j + k]) k++;
            if (j + k < n && s[i + k] < s[j + k]) {
                int t = i;
                i = j;
                j = max(j + 1, t + k + 1);
            } else {
                j = j + k + 1;
            }
        }
        return s.substr(i);
    }
};