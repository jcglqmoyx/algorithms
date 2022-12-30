#include <bits/stdc++.h>

using namespace std;

class ProductOfNumbers {
    vector<int> nums;
public:
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) nums.clear();
        else {
            if (nums.empty()) nums.push_back(num);
            else nums.push_back(nums.back() * num);
        }
    }

    int getProduct(int k) {
        if (k > nums.size()) return 0;
        else if (k == nums.size()) return nums.back();
        else return nums.back() / nums[nums.size() - k - 1];
    }
};