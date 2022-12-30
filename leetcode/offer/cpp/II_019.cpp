#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int low = 0, high = (int) s.length() - 1;
        while (low < high) {
            if (s[low] != s[high]) {
                return is_palindrome(s, low + 1, high) || is_palindrome(s, low, high - 1);
            }
            low++;
            high--;
        }
        return true;
    }

    static bool is_palindrome(string s, int low, int high) {
        while (low < high) {
            if (s[low] != s[high]) {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
};