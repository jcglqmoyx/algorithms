#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        int count_diff = 0;
        int count[26] = {};
        bool exist_even_count = false;
        char a, b;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                if (count_diff > 2) {
                    return false;
                }
                if (count_diff == 0) {
                    a = s[i];
                    b = goal[i];
                } else if (s[i] != b || goal[i] != a) {
                    return false;
                }
                count_diff++;
            }
            count[s[i] - 'a']++;
            if (count[s[i] - 'a'] == 2) {
                exist_even_count = true;
            }
        }
        if (count_diff == 0) {
            return exist_even_count;
        }
        return count_diff == 2;
    }
};