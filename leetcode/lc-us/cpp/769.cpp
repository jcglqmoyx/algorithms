#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        int count = 0;
        int max_value = 0;
        for (int i = 0; i < arr.size(); i++) {
            max_value = max(max_value, arr[i]);
            if (max_value == i) count++;
        }
        return count;
    }
};