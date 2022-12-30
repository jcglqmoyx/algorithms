#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        vector<int> arr(nums);
        sort(arr.begin(), arr.end());
        int n = (int) arr.size();
        int low = 0, high = n - 1;
        int index = 0;
        while (index < n) {
            nums[index++] = arr[low++];
            if (index == n) break;
            nums[index++] = arr[high--];
        }
    }
};