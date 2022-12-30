#include <bits/stdc++.h>

using namespace std;

int read4(char *buf4);

class Solution {
public:
    int read(char *buf, int n) {
        int res = 0;
        for (int i = 0; i < n; i += 4) {
            int count = read4(buf + i);
            res += min(count, n - i);
        }
        return res;
    }
};