#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSize(vector<int> &nums, int maxOperations) {
        sort(nums.begin(), nums.end(), greater<>());
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(nums, mid, maxOperations)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    static bool check(vector<int> &nums, int max_num, int max_operations) {
        int count_operation = 0;
        for (int num: nums) {
            if (num > max_num) {
                count_operation += (num - 1) / max_num;
                if (count_operation > max_operations) return false;
            } else {
                break;
            }
        }
        return true;
    }
};