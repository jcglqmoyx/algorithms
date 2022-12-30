#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = (int) palindrome.size();
        if (n == 1) return "";
        int cnt = 0;
        for (int i = 0; i < n / 2; i++) {
            if (palindrome[i] == 'a') cnt++;
        }
        if (cnt == n / 2) {
            palindrome.back() = 'b';
            return palindrome;
        } else {
            for (int i = 0; i < n / 2; i++) {
                if (palindrome[i] != 'a') {
                    palindrome[i] = 'a';
                    return palindrome;
                }
            }
        }
        return "";
    }
};