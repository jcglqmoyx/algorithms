#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int> &nums) {
        bitset<101> st = 0;
        int cnt = 0;
        for (int x: nums) {
            if (x) {
                if (!st[x]) {
                    cnt++;
                    st[x] = true;
                }
            }
        }
        return cnt;
    }
};