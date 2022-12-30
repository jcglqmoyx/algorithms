#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        for (; i < word.size(); i++) {
            if (word[i] != abbr[j]) {
                if (abbr[j] == '0') return false;
                int num = abbr[j] - 48;
                j++;
                while (j < abbr.length() && isdigit(abbr[j])) {
                    num = num * 10 + abbr[j] - 48;
                    j++;
                }
                i += num - 1;
                if (i >= word.size()) return false;
            } else j++;
        }
        return j == abbr.length();
    }
};