#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool is_leap_year(int year) {
        return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
    }

public:
    string dayOfTheWeek(int day, int month, int year) {
        string days[7] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
        int diff = 0;
        for (int i = 1970; i < year; i++) {
            diff += is_leap_year(i) ? 366 : 365;
        }
        for (int i = 1; i <= month; i++) {
            switch (i) {
                case 1:
                    diff += 0;
                    break;
                case 2:
                    diff += 31;
                    break;
                case 3:
                    diff += year % 400 == 0 || year % 4 == 0 && year % 100 != 0 ? 29 : 28;
                    break;
                case 4:
                    diff += 31;
                    break;
                case 5:
                    diff += 30;
                    break;
                case 6:
                    diff += 31;
                    break;
                case 7:
                    diff += 30;
                    break;
                case 8:
                case 9:
                    diff += 31;
                    break;
                case 10:
                    diff += 30;
                    break;
                case 11:
                    diff += 31;
                    break;
                case 12:
                    diff += 30;
                    break;
                default:
                    break;
            }
        }
        diff += day - 1;
        return days[diff % 7];
    }
};