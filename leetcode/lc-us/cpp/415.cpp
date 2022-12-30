#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int i = (int) num1.length() - 1, j = (int) num2.length() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            if (i >= 0 && j >= 0) {
                int x = num1[i] - 48, y = num2[j] - 48;
                int sum = x + y + carry;
                res += to_string(sum % 10);
                carry = sum / 10;
                i--;
                j--;
            } else if (i >= 0) {
                int x = num1[i] - 48;
                int sum = x + carry;
                res += to_string(sum % 10);
                carry = sum / 10;
                i--;
            } else {
                int y = num2[j] - 48;
                int sum = y + carry;
                res += to_string(sum % 10);
                carry = sum / 10;
                j--;
            }
        }
        if (carry) {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};