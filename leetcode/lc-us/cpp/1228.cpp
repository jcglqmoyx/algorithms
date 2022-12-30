#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &arr) {
        int n = (int) arr.size();
        int sum = 0, expected_sum = (arr.front() + arr.back()) * (n + 1) / 2;
        for (int num: arr) sum += num;
        return expected_sum - sum;
    }
};