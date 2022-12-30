#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        int i = 1;
        while (i < str.length() && str[i - 1] <= str[i]) {
            i++;
        }
        if (i < str.length()) {
            while (i > 0 && str[i - 1] > str[i]) {
                str[i - 1]--;
                i--;
            }
            for (i++; i < str.length(); i++) {
                str[i] = '9';
            }
        }
        return stoi(str);
    }
};