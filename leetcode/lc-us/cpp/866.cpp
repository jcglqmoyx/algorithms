#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int primePalindrome(int n) {
        int arr[] = {2, 2, 2, 3, 5, 5, 7, 7, 11, 11, 11, 11};
        if (n <= 11) return arr[n];
        for (int num = n;; num++) {
            if (num > 1000) {
                string str = to_string(num);
                if ((str.length() & 1) == 0) {
                    num = (int) pow(10, str.length()) + 1;
                }
            }
            if (is_palindrome(num) && is_prime(num)) {
                return num;
            }
        }
    }

private:
    bool is_prime(int num) {
        if (num == 1) return false;
        int remainder = num % 6;
        if (remainder == 0 || remainder == 2 || remainder == 3 || remainder == 4) return false;
        for (int i = 5; i <= sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    bool is_palindrome(int num) {
        int x = 0;
        while (x < num) {
            int digit = num % 10;
            x = x * 10 + digit;
            num /= 10;
        }
        return x == num || x / 10 == num;
    }
};