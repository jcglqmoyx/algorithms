#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int left = 0, max_depth = 0;
        for (char c: s) {
            if (c == '(') {
                left++;
                max_depth = max(max_depth, left);
            } else if (c == ')') {
                left--;
            }
        }
        return max_depth;
    }
};