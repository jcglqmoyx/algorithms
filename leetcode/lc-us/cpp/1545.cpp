#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 1; i < n; i++) {
            string t = s;
            for (char &c: t) {
                if (c == '0') c = '1';
                else c = '0';
            }
            reverse(t.begin(), t.end());
            s = s + '1' + t;
        }
        return s[k - 1];
    }
};