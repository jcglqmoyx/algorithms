class MountainArray {
public:
    int get(int index);

    int length();
};

class Solution {
    static int get_peek(MountainArray &api, int len) {
        int l = 1, r = len - 2;
        while (l < r) {
            int mid = (l + r) >> 1;
            int val = api.get(mid);
            int left_val = api.get(mid - 1), right_val = api.get(mid + 1);
            if (val > left_val && val > right_val) return mid;
            else if (val > left_val) l = mid + 1;
            else if (val > right_val) r = mid - 1;
        }
        return l;
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int peek = get_peek(mountainArr, len);
        int l = 0, r = peek;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (mountainArr.get(mid) <= target) l = mid;
            else r = mid - 1;
        }
        if (mountainArr.get(l) == target) return l;
        l = peek + 1, r = len - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (mountainArr.get(mid) >= target) l = mid;
            else r = mid - 1;
        }
        if (mountainArr.get(l) == target) return l;
        return -1;
    }
};