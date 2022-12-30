#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool cmp(int a, int b) {
        string m = to_string(a), n = to_string(b);
        return (m + n) > (n + m);
    }

public:
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), &cmp);
        string n;
        for (int num: nums) n += to_string(num);
        if (n[0] == '0') return "0";
        return n;
    }
};