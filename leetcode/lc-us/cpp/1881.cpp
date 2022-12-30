#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maxValue(string n, int x) {
        int len = (int) n.size();
        if (n[0] == '-') {
            if (x < n[1] - '0') {
                return "-" + to_string(x) + n.substr(1);
            }
            for (int i = 1; i < len; i++) {
                if (x < n[i] - '0') {
                    return n.substr(0, i) + to_string(x) + n.substr(i);
                }
            }
        } else {
            if (x > n[0] - '0') {
                return to_string(x) + n;
            }
            for (int i = 0; i < len; i++) {
                if (n[i] - '0' < x) {
                    return n.substr(0, i) + to_string(x) + n.substr(i);
                }
            }
        }
        return n + to_string(x);
    }
};