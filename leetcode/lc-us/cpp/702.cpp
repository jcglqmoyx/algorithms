class ArrayReader {
public:
    int get(int index);
};

class Solution {
public:
    int search(const ArrayReader &reader, int target) {
        int low = 0, high = 9999;
        const int INF = 2147483647;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int query = reader.get(mid);
            if (query == target) return mid;
            else if (query < target) low = mid + 1;
            else high = mid;
        }
        return reader.get(low) == target ? low : -1;
    }
};