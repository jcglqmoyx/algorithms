#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        arr = nums;
        int n = (int) nums.size();
        return max(f(0, n - 2), f(1, n - 1));
    }

private:
    vector<int> arr;

    int f(int start, int end) {
        int a = arr[start], b = max(arr[start], arr[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int c = max(a + arr[i], b);
            a = b, b = c;
        }
        return max(a, b);
    }
};