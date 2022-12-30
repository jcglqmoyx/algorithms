#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minElements(vector<int> &nums, int limit, int goal) {
        long sum = 0;
        for (int num: nums) sum += num;
        long diff = abs((long) goal - sum);
        return (int) ((diff + limit - 1) / limit);
    }
};