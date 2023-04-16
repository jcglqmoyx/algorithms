#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int addMinimum(string word) {
        int res = 1, n = (int) word.size();
        for (int i = 1; i < n; i++) {
            if (word[i] <= word[i - 1]) res++;
        }
        return res * 3 - n;
    }
};