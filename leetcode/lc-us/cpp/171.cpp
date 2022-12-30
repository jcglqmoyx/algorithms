#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int number = 0;
        for (char c: s) {
            number *= 26;
            number += c - 'A' + 1;
        }
        return number;
    }
};