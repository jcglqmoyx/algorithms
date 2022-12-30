#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(vector<int> &nums) {
        int min_num = INT32_MAX;
        for (int num: nums) {
            min_num = min(min_num, num);
        }
        int moves = 0;
        for (int num: nums) {
            moves += num - min_num;
        }
        return moves;
    }
};