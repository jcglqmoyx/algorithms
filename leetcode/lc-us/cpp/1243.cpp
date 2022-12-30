#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int> &arr) {
        int n = (int) arr.size();
        vector<int> res(arr);
        while (true) {
            vector<int> temp(arr);
            for (int i = 1; i < n - 1; i++) {
                if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                    temp[i]--;
                } else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                    temp[i]++;
                }
            }
            if (temp == arr) {
                res = arr;
                break;
            }
            arr = temp;
        }
        return res;
    }
};