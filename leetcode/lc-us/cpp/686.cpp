#include <bits/stdc++.h>

using namespace std;

class Solution {
    static const int N = 10010;
    int ne[N + 1];
public:
    int repeatedStringMatch(string a, string b) {
        int m = (int) a.size(), n = (int) b.size();
        b = " " + b;
        for (int i = 2, j = 0; i <= n; i++) {
            while (j && b[i] != b[j + 1]) j = ne[j];
            if (b[i] == b[j + 1]) j++;
            ne[i] = j;
        }
        int i = 0, j = 0;
        while (i - j < m) {
            while (j && b[j + 1] != a[i % m]) j = ne[j];
            if (a[i % m] == b[j + 1]) j++;
            i++;
            if (j == n) break;
        }
        if (j == n) {
            return (i % m == 0) ? i / m : i / m + 1;
        } else return -1;
    }
};