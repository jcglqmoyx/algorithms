#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int longest_distance = 0;
        int flag = -1;
        for (int i = 0; i < 32; i++) {
            if ((n & 1)) {
                if (flag != -1) {
                    longest_distance = max(longest_distance, i - flag);
                }
                flag = i;
            }
            n >>= 1;
        }
        return longest_distance;
    }
};