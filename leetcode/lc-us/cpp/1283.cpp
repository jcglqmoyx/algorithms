#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int> &nums, int threshold) {
        int l = 1, r = 1e6;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(mid, nums, threshold)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    static bool check(int x, vector<int> &nums, int threshold) {
        int sum = 0;
        for (int num: nums) {
            sum += (x + num - 1) / x;
        }
        return sum <= threshold;
    }
};