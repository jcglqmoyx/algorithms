#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = (int) s1.size(), m = (int) s2.size();
        int start = 0, end = max(n, m);
        int i = 0, j = 0;
        while (i < n) {
            if (s1[i] == s2[j]) {
                j++;
                if (j == m) {
                    int r = i;
                    j--;
                    while (~j) {
                        if (s1[i] == s2[j]) {
                            j--;
                        }
                        i--;
                    }
                    i++;
                    int l = i;
                    if (r - l < end - start) {
                        start = l;
                        end = r;
                    }
                    j = 0;
                }
            }
            i++;
        }
        if (end - start + 1 > n) return "";
        return s1.substr(start, end - start + 1);
    }
};