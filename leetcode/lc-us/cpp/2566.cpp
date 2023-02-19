#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = s;
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != '9') {
                char c = s[i];
                for (int j = 0; j < n; j++) {
                    if (s[j] == c) s[j] = '9';
                }
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (t[i] != '0') {
                char c = t[i];
                for (int j = 0; j < n; j++) {
                    if (t[j] == c) t[j] = '0';
                }
                break;
            }
        }
        return stoi(s) - stoi(t);
    }
};