#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int> &arr) {
        int n = (int) arr.size();
        for (int i = n - 2; ~i; i--) {
            if (arr[i] > arr[i + 1]) {
                int j = i + 1;
                int mx = arr[j], idx = j;
                while (j < n) {
                    if (arr[j] > mx && arr[j] < arr[i]) mx = arr[j], idx = j;
                    j++;
                }
                swap(arr[i], arr[idx]);
                break;
            }
        }
        return arr;
    }
};