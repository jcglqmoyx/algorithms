#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string findContestMatch(int n) {
        vector<string> v(n);
        for (int i = 0; i < n; i++) v[i] = to_string(i + 1);
        while (n > 1) {
            for (int i = 0; i < n >> 1; i++) {
                v[i] = '(' + v[i] + ',' + v[n - 1 - i] + ')';
            }
            n >>= 1;
        }
        return v[0];
    }
};