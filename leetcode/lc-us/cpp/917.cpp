#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int low = 0, high = s.length() - 1;
        while (low < high) {
            while (low < high && !isalpha(s[low])) {
                low++;
            }
            while (low < high && !isalpha(s[high])) {
                high--;
            }
            char temp = s[low];
            s[low] = s[high];
            s[high] = temp;
            low++;
            high--;
        }
        return s;
    }
};