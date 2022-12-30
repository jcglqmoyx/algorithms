#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dayOfYear(string date) {
        int year = (date[0] - 48) * 1000 + (date[1] - 48) * 100 + (date[2] - 48) * 10 + date[3] - 48;
        int month = (date[5] - 48) * 10 + date[6] - 48;
        int day = (date[8] - 48) * 10 + date[9] - 48;
        int res = 0;
        for (int i = 1; i <= month; i++)
            switch (i) {
                case 1:
                    res += 0;
                    break;
                case 2:
                    res += 31;
                    break;
                case 3:
                    res += year % 400 == 0 || year % 4 == 0 && year % 100 != 0 ? 29 : 28;
                    break;
                case 4:
                    res += 31;
                    break;
                case 5:
                    res += 30;
                    break;
                case 6:
                    res += 31;
                    break;
                case 7:
                    res += 30;
                    break;
                case 8:
                case 9:
                    res += 31;
                    break;
                case 10:
                    res += 30;
                    break;
                case 11:
                    res += 31;
                    break;
                case 12:
                    res += 30;
                    break;
                default:
                    break;
            }
        res += day;
        return res;
    }
};