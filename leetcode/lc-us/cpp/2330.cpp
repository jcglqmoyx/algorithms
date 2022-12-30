#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool makePalindrome(string s) {
        int cnt = 0;
        int i = 0, j = (int) s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                cnt++;
            }
            i++, j--;
        }
        return cnt <= 2;
    }
};