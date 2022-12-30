#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double average(vector<int> &salary) {
        int maximum = 1000, minimum = 1000000;
        double sum = 0;
        for (int num: salary) {
            if (num > maximum) {
                maximum = num;
            }
            if (num < minimum) {
                minimum = num;
            }
            sum += num;
        }
        return (sum - minimum - maximum) / ((int) salary.size() - 2);
    }
};