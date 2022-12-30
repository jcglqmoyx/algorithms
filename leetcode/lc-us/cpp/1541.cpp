#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = (int) s.size(), left = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') left++;
            else {
                if (i < n - 1 && s[i + 1] == ')') i++;
                else res++;
                if (left) left--;
                else res++;
            }
        }
        if (left) res += left * 2;
        return res;
    }
};