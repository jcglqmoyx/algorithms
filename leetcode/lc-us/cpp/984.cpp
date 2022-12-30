#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res;
        int a_written = 0, b_written = 0;
        while (a > 0 || b > 0) {
            if (a > b) {
                if (a_written < 2) {
                    res += 'a';
                    a_written++;
                    b_written = 0;
                    a--;
                } else {
                    res += 'b';
                    b_written++;
                    a_written = 0;
                    b--;
                }
            } else {
                if (b_written < 2) {
                    res += 'b';
                    b_written++;
                    a_written = 0;
                    b--;
                } else {
                    res += 'a';
                    a_written++;
                    b_written = 0;
                    a--;
                }
            }
        }
        return res;
    }
};