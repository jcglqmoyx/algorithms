#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countElements(vector<int> &nums) {
        int mn = *min_element(nums.begin(), nums.end()), mx = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        for (int x: nums) {
            if (x > mn && x < mx) cnt++;
        }
        return cnt;
    }
};