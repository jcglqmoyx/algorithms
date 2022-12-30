#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes) {
        unordered_set<int> set;
        for (int candy: bobSizes) {
            set.insert(candy);
        }
        int sum_a = get_sum(aliceSizes), sum_b = get_sum(bobSizes);
        int diff = (sum_a - sum_b) / 2;
        for (int candy: aliceSizes) {
            if (set.count(candy - diff)) {
                return {candy, candy - diff};
            }
        }
        return {};
    }

private:
    int get_sum(const vector<int> &arr) {
        int sum = 0;
        for (int num: arr) {
            sum += num;
        }
        return sum;
    }
};