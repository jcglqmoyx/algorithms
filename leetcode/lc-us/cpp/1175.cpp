#include <bits/stdc++.h>

using namespace std;

class Solution {
    static bool is_prime(int num) {
        if (num == 1) {
            return false;
        } else if (num <= 3) {
            return true;
        }
        for (int i = 2; i <= (int) sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

public:
    int numPrimeArrangements(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (is_prime(i)) {
                count++;
            }
        }
        long product = 1;
        for (int i = 1; i <= count; i++) {
            product *= i;
            product %= 1000000007;
        }
        for (int i = 1; i <= n - count; i++) {
            product *= i;
            product %= 1000000007;
        }
        return (int) product;
    }
};