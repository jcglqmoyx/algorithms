#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int> &nums) {
        vector<int> arr = {0};
        for (int num: nums) {
            if (arr.empty() || arr.back() != num) {
                arr.push_back(num);
            }
        }
        arr.push_back(0);

        int n = (int) arr.size() - 1;
        long long sum = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                sum += arr[i];
            }
            if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                sum -= arr[i];
            }
        }
        return sum;
    }
};