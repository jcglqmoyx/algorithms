#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsPattern(vector<int> &arr, int m, int k) {
        for (int i = 0; i <= (int) arr.size() - m * k; i++) {
            bool flag = true;
            for (int j = i; j < i + m; j++) {
                for (int count = 0; count < k; count++) {
                    if (arr[j] != arr[j + m * count]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
};