class Solution {
public:
    long long coloredCells(int n) {
        return (long long) n * n * 2 - (n * 2 - 1);
    }
};