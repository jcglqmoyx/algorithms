#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int res = 0, n = (int) word.size();
        string p = "aeiou";
        for (int i = 0; i < n; i++) {
            if (word[i] != 'a') continue;
            int j = i, k = 0;
            while (j < n) {
                if (word[j] == p[k]) j++;
                else {
                    if (k == 4 || word[j] != p[k + 1]) break;
                    else j++, k++;
                }
            }
            if (k == 4) res = max(res, j - i);
            i = j - 1;
        }
        return res;
    }
};