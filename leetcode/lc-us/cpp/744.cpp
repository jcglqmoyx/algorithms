#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        char res = 'z' + 1;
        for (char letter: letters) {
            if (letter > target && letter < res) {
                res = letter;
            }
        }
        if (res == 'z' + 1) {
            res = 'z';
            for (char letter: letters) {
                res = min(res, letter);
            }
        }
        return res;
    }
};