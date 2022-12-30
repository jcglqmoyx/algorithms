#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int i = 0, j = 0;
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        while (i < pattern.length()) {
            int end = j;
            while (end < s.length() && !isspace(s[end])) {
                end++;
            }
            string word = s.substr(j, end - j);
            if (map1.count(pattern[i]) && map1[pattern[i]] != word ||
                map2.count(word) && map2[word] != pattern[i]) {
                return false;
            }
            map1[pattern[i]] = word;
            map2[word] = pattern[i];
            i++;
            j = end + 1;
            if (i < pattern.length() && j >= s.length() || i >= pattern.length() && j <= s.length()) {
                return false;
            }
        }
        return true;
    }
};