#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int max_digit = 1;
        for (char c: n) {
            max_digit = max(max_digit, c - 48);
        }
        return max_digit;
    }
};