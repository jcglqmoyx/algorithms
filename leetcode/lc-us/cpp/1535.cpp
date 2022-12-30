#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getWinner(vector<int> &arr, int k) {
        int n = (int) arr.size(), cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (cnt >= k) return arr[i];
            if (arr[i] > arr[i + 1]) {
                cnt++;
                swap(arr[i], arr[i + 1]);
            } else {
                cnt = 1;
            }
        }
        return arr[n - 1];
    }
};