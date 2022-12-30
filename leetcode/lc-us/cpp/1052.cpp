#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
        int n = (int) customers.size();
        int not_satisfied = 0;
        for (int i = 0; i < X; i++) {
            if (grumpy[i] == 1) {
                not_satisfied += customers[i];
            }
        }
        int max_not_satisfied = not_satisfied;
        for (int i = 1; i <= n - X; i++) {
            if (grumpy[i + X - 1] == 1) {
                not_satisfied += customers[i + X - 1];
            }
            if (grumpy[i - 1] == 1) {
                not_satisfied -= customers[i - 1];
            }
            max_not_satisfied = max(max_not_satisfied, not_satisfied);
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                sum += customers[i];
            }
        }
        return sum + max_not_satisfied;
    }
};