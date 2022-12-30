#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string dict = " ";
        for (char c = 'a'; c <= 'z'; c++) dict.push_back(c);
        string res(n, '0');
        for (int i = n - 1; i >= 0; i--) {
            int left = k - i;
            if (left > 26) {
                k -= 26;
                res[i] = 'z';
            } else {
                k -= left;
                res[i] = dict[left];
            }
        }
        return res;
    }
};