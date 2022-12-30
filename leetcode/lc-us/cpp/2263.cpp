#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int convertArray(vector<int> &nums) {
        int t = get(nums);
        reverse(nums.begin(), nums.end());
        return min(get(nums), t);
    }

private:
    int get(vector<int> &nums) {
        int res = 0;
        priority_queue<int> heap;
        for (int x: nums) {
            if (!heap.empty() && heap.top() > x) {
                res += heap.top() - x;
                heap.pop();
                heap.push(x);
            }
            heap.push(x);
        }
        return res;
    }
};