#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string> &array) {
        int max_len = 0, start = -1, end = -1;
        unordered_map<int, int> hash;
        int count_letter = 0, count_digit = 0;
        for (int i = 0; i < (int) array.size(); i++) {
            if (isalpha(array[i][0])) count_letter++;
            else count_digit++;
            int diff = count_letter - count_digit;
            if (diff == 0) {
                max_len = i + 1;
                start = 0, end = i;
            } else {
                if (hash.count(diff)) {
                    int len = i - hash[diff];
                    if (len > max_len) {
                        max_len = len;
                        start = hash[diff] + 1;
                        end = i;
                    }
                }
            }
            if (!hash.count(diff)) hash[diff] = i;
        }
        vector<string> res;
        if (max_len) {
            for (int i = start; i <= end; i++) {
                res.push_back(array[i]);
            }
        }
        return res;
    }
};