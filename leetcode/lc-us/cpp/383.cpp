#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[128] = {};
        for (char c: magazine) {
            count[c]++;
        }
        for (char c: ransomNote) {
            count[c]--;
        }
        for (int i = 'a'; i <= 'z'; i++) {
            if (count[i] < 0) {
                return false;
            }
        }
        return true;
    }
};