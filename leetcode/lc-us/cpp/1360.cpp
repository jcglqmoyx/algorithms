#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        int year1 = get_year(date1), year2 = get_year(date2);
        int month1 = get_month(date1), month2 = get_month(date2);
        int day1 = get_day(date1), day2 = get_day(date2);
        return abs(days_since_the_first_day_of_1971(year1, month1, day1) -
                   days_since_the_first_day_of_1971(year2, month2, day2));
    }

private:
    static int get_year(string date) {
        return (date[0] - 48) * 1000 + (date[1] - 48) * 100 + (date[2] - 48) * 10 + date[3] - 48;
    }

    static int get_month(string date) {
        return (date[5] - 48) * 10 + date[6] - 48;
    }

    static int get_day(string date) {
        return (date[8] - 48) * 10 + date[9] - 48;
    }

    static int days_since_the_first_day_of_1971(int year, int month, int day) {
        int days = 0;
        for (int i = 1971; i < year; i++) {
            days += i % 400 == 0 || i % 4 == 0 && i % 100 != 0 ? 366 : 365;
        }
        for (int i = 1; i <= month; i++) {
            switch (i) {
                case 1:
                    days += 0;
                    break;
                case 2:
                    days += 31;
                    break;
                case 3:
                    days += year % 400 == 0 || year % 4 == 0 && year % 100 != 0 ? 29 : 28;
                    break;
                case 4:
                    days += 31;
                    break;
                case 5:
                    days += 30;
                    break;
                case 6:
                    days += 31;
                    break;
                case 7:
                    days += 30;
                    break;
                case 8:
                case 9:
                    days += 31;
                    break;
                case 10:
                    days += 30;
                    break;
                case 11:
                    days += 31;
                    break;
                case 12:
                    days += 30;
                    break;
                default:
                    break;
            }
        }
        days += day - 1;
        return days;
    }
};