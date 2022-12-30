#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image) {
        for (auto &i: image) {
            flip(i);
            invert(i);
        }
        return image;
    }

private:
    void flip(vector<int> &nums) {
        for (int i = 0; i < nums.size() / 2; i++) {
            int temp = nums[i];
            nums[i] = nums[nums.size() - i - 1];
            nums[nums.size() - i - 1] = temp;
        }
    }

    void invert(vector<int> &nums) {
        for (int &num: nums) {
            num ^= 1;
        }
    }
};