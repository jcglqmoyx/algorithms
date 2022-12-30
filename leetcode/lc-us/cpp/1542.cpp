#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int, int> prefix = {{0, -1}};
        int res = 0;
        int sequence = 0;
        for (int i = 0; i < s.size(); i++) {
            int d = s[i] - '0';
            sequence ^= 1 << d;
            if (prefix.count(sequence)) {
                res = max(res, i - prefix[sequence]);
            } else {
                prefix[sequence] = i;
            }
            for (int j = 0; j < 10; j++) {
                if (prefix.count(sequence ^ (1 << j))) {
                    res = max(res, i - prefix[sequence ^ (1 << j)]);
                }
            }
        }
        return res;
    }
};