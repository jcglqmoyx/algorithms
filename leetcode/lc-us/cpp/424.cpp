#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {};
        int max_freq = 0;
        int left = 0, right = 0;
        for (; right < s.length(); right++) {
            count[s[right] - 'A']++;
            max_freq = max(max_freq, count[s[right] - 'A']);
            if (right - left + 1 - max_freq > k) {
                count[s[left] - 'A']--;
                left++;
            }
        }
        return right - left;
    }
};