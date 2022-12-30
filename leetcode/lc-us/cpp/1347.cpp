#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int count1[26] = {}, count2[26] = {};
        for (int i = 0; i < s.size(); i++) {
            count1[s[i] - 'a']++;
            count2[t[i] - 'a']++;
        }
        int step = 0;
        for (int i = 0; i < 26; i++) {
            if (count1[i] > count2[i]) {
                step += count1[i] - count2[i];
            }
        }
        return step;
    }
};