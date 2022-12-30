class Solution {
    static int rotate(int n) {
        switch (n) {
            case 0:
                return 0;
            case 1:
                return 1;
            case 6:
                return 9;
            case 8:
                return 8;
            case 9:
                return 6;
            default:
                return 0;
        }
    }

    static bool invalid(int n) {
        return n == 2 || n == 3 || n == 4 || n == 5 || n == 7;
    }

public:
    bool confusingNumber(int N) {
        int reversed = 0, bak = N;
        while (N) {
            int digit = N % 10;
            if (invalid(digit)) return false;
            reversed = reversed * 10 + rotate(digit);
            N /= 10;
        }
        return reversed != bak;
    }
};