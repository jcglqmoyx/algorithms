#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int magicTower(vector<int> &nums) {
        int n = (int) nums.size();
        long sum = 1;
        for (int num: nums) {
            sum += (long) num;
        }
        if (sum <= 0) return -1;
        int count = 0;
        sum = 1;
        priority_queue<long, vector<long>, greater<>> q;
        for (int i = 0; i < n; i++) {
            sum += (long) nums[i];
            if (nums[i] < 0) q.push(nums[i]);
            while (sum <= 0) {
                long top = q.top();
                q.pop();
                sum -= top;
                count++;
            }
        }
        return count;
    }
};