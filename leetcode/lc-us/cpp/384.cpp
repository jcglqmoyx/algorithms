#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> original;
    vector<int> arr;

public:
    Solution(vector<int> &nums) {
        arr = nums;
        original = vector<int>(nums);
    }

    vector<int> reset() {
        arr = vector<int>(original);
        return arr;
    }

    vector<int> shuffle() {
        for (int i = 1; i < arr.size(); i++) {
            int random_index = rand() % (i + 1);
            swap(arr[random_index], arr[i]);
        }
        return arr;
    }
};