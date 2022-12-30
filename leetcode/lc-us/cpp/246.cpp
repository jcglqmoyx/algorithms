#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = (int) num.size();
        for (int i = 0; i < n; i++) {
            if (rotated(num[n - i - 1] - '0') + '0' != num[i]) return false;
        }
        return true;
    }

private:
    int rotated(int n) {
        if (n == 0 || n == 1 || n == 8) return n;
        if (n == 6) return 9;
        if (n == 9) return 6;
        return -1;
    }
};