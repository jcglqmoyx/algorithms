#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int> &arr) {
        int max_count = ((int) arr.size() >> 2) + 1, count = 1;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                count++;
                if (count >= max_count) {
                    return arr[i];
                }
            } else {
                count = 1;
            }
        }
        return arr[0];
    }
};