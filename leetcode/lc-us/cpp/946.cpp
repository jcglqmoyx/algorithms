#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        vector<int> arr;
        int j = 0;
        int n = (int) pushed.size();
        for (int num: pushed) {
            arr.push_back(num);
            while (!arr.empty() && j < n && arr.back() == popped[j]) {
                arr.pop_back();
                j++;
            }
        }
        return j == n;
    }
};