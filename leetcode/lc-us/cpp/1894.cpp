#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int> &chalk, int k) {
        int n = (int) chalk.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (k >= chalk[i]) k -= chalk[i];
            else return i;
            sum += chalk[i];
        }
        k %= sum;
        for (int i = 0; i < n; i++) {
            if (k >= chalk[i]) k -= chalk[i];
            else return i;
        }
        return 0;
    }
};