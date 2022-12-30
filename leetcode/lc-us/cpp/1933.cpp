#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isDecomposable(string s) {
        bool flag = false;
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            if ((j - i) % 3 == 2) {
                if (flag) return false;
                flag = true;
            } else if ((j - i) % 3) {
                return false;
            }
            i = j - 1;
        }
        return flag;
    }
};