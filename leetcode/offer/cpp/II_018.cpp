#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int low = 0, high = (int) s.length() - 1;
        while (low < high) {
            while (low < high && !isalnum(s[low])) {
                low++;
            }
            while (low < high && !isalnum(s[high])) {
                high--;
            }
            if (toupper(s[low]) != toupper(s[high])) {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
};