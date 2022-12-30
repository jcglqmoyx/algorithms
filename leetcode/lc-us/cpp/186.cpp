#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseWords(vector<char> &s) {
        reverse(s.begin(), s.end());
        int n = (int) s.size();
        for (int i = 0, j = 0; j < n; j++) {
            if (s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            } else if (j == n - 1) {
                reverse(s.begin() + i, s.end());
            }
        }
    }
};