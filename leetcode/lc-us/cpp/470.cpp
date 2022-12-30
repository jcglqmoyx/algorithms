// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int x = rand7();
        int y = rand7();
        int z = (x - 1) * 7 + y;
        if (z > 40) {
            return rand10();
        }
        return (z + 3) / 4;
    }
};