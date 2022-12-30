#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string generateTheString(int n) {
        string res;
        for (int i = 0; i < n - 1; i++) {
            res += 'a';
        }
        if (n % 2 == 0) {
            res += 'b';
        } else {
            res += 'a';
        }
        return res;
    }
};