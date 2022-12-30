#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                for (int j = i + 1; j < n; j++) {
                    if (s[j] == 'a') {
                        return false;
                    }
                }
                break;
            }
        }
        return true;
    }
};