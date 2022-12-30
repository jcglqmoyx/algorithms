#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        int count[101] = {};
        for (int num: nums) {
            count[num]++;
        }
        int prev = 0;
        int index = 0;
        for (int i = 0; i <= 100; i++) {
            if (count[i]) {
                prev = count[i];
                count[i] = 0;
                index = i;
                break;
            }
        }
        for (int i = index + 1; i <= 100; i++) {
            if (count[i]) {
                int cnt = count[i];
                count[i] = prev;
                prev += cnt;
            }
        }
        for (int &num: nums) {
            num = count[num];
        }
        return nums;
    }
};