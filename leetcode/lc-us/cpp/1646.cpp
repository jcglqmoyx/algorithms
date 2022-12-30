#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n <= 1) return n;
        vector<int> arr(n + 1);
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i < n + 1; i += 2) {
            arr[i] = arr[i / 2];
            if (i < n) {
                arr[i + 1] = arr[i / 2] + arr[i / 2 + 1];
            }
        }
        int max_num = 0;
        for (int num: arr) {
            max_num = max(max_num, num);
        }
        return max_num;
    }
};