#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNumberOfApples(vector<int> &arr) {
        int count = 0;
        int total = 5000;
        sort(arr.begin(), arr.end());
        for (int weight: arr)
            if (total >= weight) {
                total -= weight;
                count++;
            } else break;
        return count;
    }
};