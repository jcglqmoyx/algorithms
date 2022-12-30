#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long largestEvenSum(vector<int> &nums, int k) {
        using LL = long long;
        int n = (int) nums.size();
        sort(nums.begin(), nums.end(), greater<>());
        LL sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        if (sum & 1) {
            int flag = 0;
            LL t1 = sum, t2 = sum;
            for (int i = k - 1; ~i; i--) {
                if (nums[i] & 1) {
                    flag++;
                    t1 -= nums[i];
                    break;
                }
            }
            if (flag) {
                for (int i = k; i < n; i++) {
                    if (nums[i] % 2 == 0) {
                        t1 += nums[i];
                        flag++;
                        break;
                    }
                }
            }
            if (flag != 2) t1 = 1;
            flag = 0;
            for (int i = k - 1; ~i; i--) {
                if (nums[i] % 2 == 0) {
                    flag++;
                    t2 -= nums[i];
                    break;
                }
            }
            if (flag) {
                for (int i = k; i < n; i++) {
                    if (nums[i] & 1) {
                        t2 += nums[i];
                        flag++;
                        break;
                    }
                }
            }
            if (flag != 2) t2 = 1;
            if (t1 & 1 && t2 & 1) return -1;
            else if (t1 & 1) return t2;
            else if (t2 & 1) return t1;
            else return max(t1, t2);
        } else {
            return sum;
        }
    }
};