#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int magicalString(int n) {
        vector<int> arr = {1, 2, 2, 1, 1, 2};
        arr.reserve(n);
        int index = 4;
        while (arr.size() <= n) {
            if (arr[index] == 1) {
                if (arr.back() == 1) {
                    arr.push_back(2);
                } else {
                    arr.push_back(1);
                }
            } else {
                if (arr.back() == 1) {
                    arr.push_back(2);
                    arr.push_back(2);
                } else {
                    arr.push_back(1);
                    arr.push_back(1);
                }
            }
            index++;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                count++;
            }
        }
        return count;
    }
};