class ArrayReader {
public:
    // Compares the sum of arr[l..r] with the sum of arr[x..y]
    // return 1 if sum(arr[l..r]) > sum(arr[x..y])
    // return 0 if sum(arr[l..r]) == sum(arr[x..y])
    // return -1 if sum(arr[l..r]) < sum(arr[x..y])
    int compareSub(int l, int r, int x, int y);

    // Returns the length of the array
    int length();
};

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int n = (int) reader.length();
        int l = 0, r = n - 1;
        while (l <= r) {
            if (l == r) return l;
            int mid = (l + r) >> 1;
            int len = r - l + 1;
            if (len & 1) {
                int result = reader.compareSub(l, mid - 1, mid + 1, r);
                if (!result) return mid;
                else if (result == 1) r = mid - 1;
                else l = mid + 1;
            } else {
                int result = reader.compareSub(l, mid, mid + 1, r);
                if (result == 1) r = mid;
                else l = mid + 1;
            }
        }
        return l;
    }
};