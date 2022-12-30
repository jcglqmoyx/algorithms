#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string> &operations) {
        int res = 0;
        for (string &op: operations) {
            if (op == "++X" || op == "X++") res++;
            else res--;
        }
        return res;
    }
};