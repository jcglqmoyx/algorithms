#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            n--;
            res.push_back((char) ('A' + n % 26));
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};