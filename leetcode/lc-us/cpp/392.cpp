#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0, m = (int) s.size(), n = (int) t.size();
        while (i < m && j < n) {
            if (s[i] == t[j]) i++;
            j++;
        }
        return i == m;
    }
};