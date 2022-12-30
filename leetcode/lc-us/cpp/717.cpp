#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        int n = (int) bits.size();
        if (n == 1) return true;
        int i = 0;
        while (i < n - 1) {
            if (bits[i]) i += 2;
            else i++;
        }
        return i == n - 1;
    }
};