#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        string digits;
        int count[10] = {0};
        int map[128] = {0};
        for (char c: s) map[c]++;

        int zero = map['z'];
        count[0] = zero;
        map['z'] -= zero;
        map['e'] -= zero;
        map['r'] -= zero;
        map['o'] -= zero;

        int two = map['w'];
        count[2] = two;
        map['t'] -= two;
        map['w'] -= two;
        map['o'] -= two;

        int six = map['x'];
        count[6] = six;
        map['s'] -= six;
        map['i'] -= six;

        int seven = map['s'];
        count[7] = seven;
        map['e'] = seven * 2;
        map['v'] -= seven;
        map['n'] -= seven;

        int four = map['u'];
        count[4] = four;
        map['f'] -= four;
        map['o'] -= four;
        map['r'] -= four;

        int five = map['v'];
        count[5] = five;
        map['i'] -= five;
        map['e'] -= five;

        int three = map['r'];
        count[3] = three;
        map['t'] -= three;
        map['e'] -= three * 2;

        int eight = map['t'];
        count[8] = eight;
        map['e'] -= eight;
        map['i'] -= eight;

        int nine = map['i'];
        count[9] = nine;
        map['n'] -= nine * 2;
        map['e'] -= nine;

        int one = map['o'];
        count[1] = one;

        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j < count[i]; j++) {
                digits += to_string(i);
            }
        }
        return digits;
    }
};