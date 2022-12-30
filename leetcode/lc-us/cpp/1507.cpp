#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reformatDate(string date) {
        string year, month, day;
        day = isdigit(date[1]) ? date.substr(0, 2) : date.substr(0, 1);
        int space = (int) date.find(' ');
        month = date.substr(space + 1, 3);
        if (month == "Jan") {
            month = "01";
        } else if (month == "Feb") {
            month = "02";
        } else if (month == "Mar") {
            month = "03";
        } else if (month == "Apr") {
            month = "04";
        } else if (month == "May") {
            month = "05";
        } else if (month == "Jun") {
            month = "06";
        } else if (month == "Jul") {
            month = "07";
        } else if (month == "Aug") {
            month = "08";
        } else if (month == "Sep") {
            month = "09";
        } else if (month == "Oct") {
            month = "10";
        } else if (month == "Nov") {
            month = "11";
        } else {
            month = "12";
        }
        year = date.substr(date.size() - 4, 4);
        return year + '-' + month + '-' + (day.size() == 1 ? '0' + day : day);
    }
};