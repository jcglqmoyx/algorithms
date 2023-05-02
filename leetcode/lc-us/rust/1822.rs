impl Solution {
    pub fn array_sign(nums: Vec<i32>) -> i32 {
        let mut cnt_minus_1 = 0;
        for x in nums {
            if x == 0 {
                return 0;
            } else if x < 0 {
                cnt_minus_1 += 1;
            }
        }
        return if cnt_minus_1 & 1 == 0 { 1 } else { -1 };
    }
}