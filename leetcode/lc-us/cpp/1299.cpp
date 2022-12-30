#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int> &arr) {
        int n = (int) arr.size();
        int max = arr[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            int value = arr[i];
            arr[i] = max;
            if (value > max) {
                max = value;
            }
        }
        arr[n - 1] = -1;
        return arr;
    }
};