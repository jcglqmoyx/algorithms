#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        for (int start = 0, count = 0; count < nums.size(); start++) {
            int cur = start;
            int prev = nums[cur];
            do {
                int next = (cur + k) % (int) nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                cur = next;
                count++;
            } while (start != cur);
        }
    }
};