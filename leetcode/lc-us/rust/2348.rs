impl Solution {
    pub fn zero_filled_subarray(nums: Vec<i32>) -> i64 {
        let mut res: i64 = 0;
        let mut i = 0;
        while i < nums.len() {
            if nums[i] == 0 {
                let mut j = i + 1;
                while j < nums.len() && nums[j] == 0 {
                    j += 1;
                }
                let len: i64 = (j - i) as i64;
                res += (len + 1) * len / 2;
                i = j - 1;
            }
            i += 1;
        }
        return res;
    }
}