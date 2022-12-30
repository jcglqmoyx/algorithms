#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = (int) s.size(), m = (int) t.size();
        int i = 0, j = 0;
        while (j < n) {
            while (i < n && s[i] != t[j]) i++;
            if (i == n) return m - j;
            i++, j++;
        }
        return 0;
    }
};