#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;
        for (char c: s) {
            if (isdigit(c)) {
                int num = c - '0';
                if (num > second) {
                    if (num > first) {
                        second = first;
                        first = num;
                    } else if (num < first) {
                        second = num;
                    }
                }
            }
        }
        return second;
    }
};