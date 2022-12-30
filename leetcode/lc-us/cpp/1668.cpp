#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = (int) sequence.size(), m = (int) word.size();
        if (n < m) return 0;
        int max_repeating = 0;
        for (int i = 0; i < n - m + 1; i++) {
            int repeating = 0;
            if (sequence.substr(i, m) == word) {
                for (int j = i; j < n; j += m) {
                    if (sequence.substr(j, m) == word) {
                        repeating++;
                        max_repeating = max(max_repeating, repeating);
                    } else {
                        break;
                    }
                }
            }
        }
        return max_repeating;
    }
};