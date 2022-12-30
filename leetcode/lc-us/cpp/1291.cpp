#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int num = 1;
        for (int i = 2; i <= 9; i++) {
            num = num * 10 + i;
            if (num >= low && num <= high) res.push_back(num);
            int temp = num;
            int plus = 1;
            while (plus * 10 + 1 < num) {
                plus = plus * 10 + 1;
            }
            for (int j = 0; j < 9 - i; j++) {
                temp += plus;
                if (temp >= low && temp <= high) res.push_back(temp);
            }
        }
        return res;
    }
};