#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string toHexspeak(string num) {
        string hex;
        long long n = stoll(num);
        while (n) {
            int digit = (int) (n % 16);
            switch (digit) {
                case 0:
                    hex += 'O';
                    break;
                case 1:
                    hex += 'I';
                    break;
                case 10:
                    hex += 'A';
                    break;
                case 11:
                    hex += 'B';
                    break;
                case 12:
                    hex += 'C';
                    break;
                case 13:
                    hex += 'D';
                    break;
                case 14:
                    hex += 'E';
                    break;
                case 15:
                    hex += 'F';
                    break;
                default:
                    return "ERROR";
            }
            n /= 16;
        }
        reverse(hex.begin(), hex.end());
        return hex;
    }
};