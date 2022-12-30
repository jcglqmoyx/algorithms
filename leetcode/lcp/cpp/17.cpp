#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int x = 1, y = 0;
        for (char c: s) {
            switch (c) {
                case 'A':
                    x = 2 * x + y;
                    break;
                case 'B':
                    y = 2 * y + x;
                    break;
                default:
                    break;
            }
        }
        return x + y;
    }
};