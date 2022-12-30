#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int> &target, int n) {
        vector<string> operations;
        int cur = 1;
        for (int num: target) {
            while (cur++ < num) {
                operations.emplace_back("Push");
                operations.emplace_back("Pop");
            }
            operations.emplace_back("Push");
        }
        return operations;
    }
};