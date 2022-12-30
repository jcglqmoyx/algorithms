#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = (int) s.size();
        vector<int> ne(n, -1);
        for (int i = 1, j = -1; i < n; i++) {
            while (j != -1 && s[i] != s[j + 1]) j = ne[j];
            if (s[i] == s[j + 1]) j++;
            ne[i] = j;
        }
        return s.substr(0, ne[n - 1] + 1);
    }
};