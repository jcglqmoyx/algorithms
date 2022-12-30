#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int> &nums) {
        int sum = 0;
        for (int num: nums) {
            unordered_set<int> s;
            for (int i = 1; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    s.insert(i);
                    s.insert(num / i);
                }
            }
            if (s.size() == 4) {
                for (int factor: s) {
                    sum += factor;
                }
            }
        }
        return sum;
    }
};