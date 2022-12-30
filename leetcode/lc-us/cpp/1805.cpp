#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> nums;
        int n = (int) word.size();
        for (int i = 0; i < n; i++) {
            if (!isdigit(word[i])) {
                word[i] = ' ';
            }
        }
        stringstream ss(word);
        string num;
        while (ss >> num) {
            reverse(num.begin(), num.end());
            while (!num.empty() && num.back() == '0') {
                num.pop_back();
            }
            nums.insert(num);
        }
        return (int) nums.size();
    }
};