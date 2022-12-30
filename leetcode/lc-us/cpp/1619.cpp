#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double trimMean(vector<int> &arr) {
        int n = (int) arr.size();
        sort(arr.begin(), arr.end());
        double sum = 0;
        for (int i = n / 20; i < n * 0.95; i++) {
            sum += arr[i];
        }
        return sum / (n * 0.9);
    }
};