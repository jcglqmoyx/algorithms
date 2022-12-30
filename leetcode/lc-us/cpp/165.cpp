#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while (true) {
            int v1, v2;
            int m = i, n = j;
            while (m < version1.length()) {
                if (version1[m] == '.') {
                    break;
                }
                m++;
            }
            while (n < version2.length()) {
                if (version2[n] == '.') {
                    break;
                }
                n++;
            }
            if (m > version1.length() && n > version2.length()) break;
            v1 = m > version1.length() ? 0 : stoi(version1.substr(i, m - i));
            v2 = n > version2.length() ? 0 : stoi(version2.substr(j, n - j));
            if (v1 < v2) return -1;
            else if (v1 > v2) return 1;
            i = m + 1;
            j = n + 1;
        }
        return 0;
    }
};