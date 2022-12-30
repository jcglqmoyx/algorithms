#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int> &nums, int diff) {
        int cnt = 0;
        unordered_map<int, int> M;
        for (int x: nums) {
            cnt += M[x - diff] * M[x - diff * 2];
            M[x]++;
        }
        return cnt;
    }
};