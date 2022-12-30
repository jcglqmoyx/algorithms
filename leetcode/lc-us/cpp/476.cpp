class Solution {
public:
    int findComplement(int num) {
        int temp = 1;
        while (temp < num) {
            temp = (temp << 1) + 1;
        }
        return temp ^ num;
    }
};