#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        for (int i = 1;; i++) {
            if (i <= memory1 && memory1 >= memory2) {
                memory1 -= i;
            } else if (i <= memory2 && memory2 > memory1) {
                memory2 -= i;
            } else {
                return {i, memory1, memory2};
            }
        }
    }
};