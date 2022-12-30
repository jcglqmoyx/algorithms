#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int> &arr) {
        int n = (int) arr.size();
        if (n == 1) return 1;
        int res = 1;
        int len = 1;
        bool greater = arr[0] > arr[1];
        for (int i = 0; i < n - 1; i++) {
            if (greater && arr[i] < arr[i + 1] || !greater && arr[i] > arr[i + 1]) {
                len++;
                greater = !greater;
            } else {
                res = max(res, len);
                if (arr[i] == arr[i + 1]) len = 1;
                else len = 2;
                greater = arr[i] > arr[i + 1];
            }
            res = max(res, len);
        }
        return res;
    }
};