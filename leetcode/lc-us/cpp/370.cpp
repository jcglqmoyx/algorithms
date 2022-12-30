#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector<int> arr(length);
        for (auto &u: updates) {
            arr[u[0]] += u[2];
            if (u[1] + 1 < length) {
                arr[u[1] + 1] -= u[2];
            }
        }
        for (int i = 1; i < length; i++) {
            arr[i] += arr[i - 1];
        }
        return arr;
    }
};