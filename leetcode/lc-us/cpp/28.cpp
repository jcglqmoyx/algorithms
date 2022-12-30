#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = (int) haystack.size(), m = (int) needle.size();
        if (n < m) return -1;
        vector<int> ne(m, -1);
        for (int i = 1, j = -1; i < m; i++) {
            while (j != -1 && needle[i] != needle[j + 1]) j = ne[j];
            if (needle[i] == needle[j + 1]) j++;
            ne[i] = j;
        }
        for (int i = 0, j = -1; i < n; i++) {
            while (j != -1 && haystack[i] != needle[j + 1]) j = ne[j];
            if (haystack[i] == needle[j + 1]) j++;
            if (j == m - 1) return i - m + 1;
        }
        return -1;
    }
};