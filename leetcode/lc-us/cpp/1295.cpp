#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int> &nums) {
        int res = 0;
        for (int num: nums) {
            if (has_even_number_of_digits(num)) {
                res++;
            }
        }
        return res;
    }

private:
    bool has_even_number_of_digits(int num) {
        int count = 0;
        while (num) {
            num /= 10;
            count++;
        }
        return count % 2 == 0;
    }
};