class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int dx = x1 > x_center ? x1 - x_center : x2 > x_center ? 0 : x_center - x2;
        int dy = y1 > y_center ? y1 - y_center : y2 > y_center ? 0 : y_center - y2;
        return dx * dx + dy * dy <= radius * radius;
    }
};