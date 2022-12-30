#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) {
            return 0;
        }
        int end = (int) s.length();
        int high = end - 1;
        while (s[high] == ' ') {
            high--;
            end--;
        }
        while (high >= 0 && s[high] != ' ') {
            high--;
        }
        return end - high - 1;
    }
};