#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = (int) s.size(), count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i + 1] == s[i]) {
                count++;
                if (s[i + 1] == '1') {
                    s[i + 1] = '0';
                } else {
                    s[i + 1] = '1';
                }
            }
        }
        return min(count, n - count);
    }
};