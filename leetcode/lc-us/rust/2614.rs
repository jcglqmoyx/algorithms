use std::cmp::max;

impl Solution {
    fn is_prime(x: i32) -> bool {
        if x < 2 {
            return false;
        }
        let mut i = 2;
        while i * i <= x {
            if x % i == 0 {
                return false;
            }
            i += 1;
        }
        true
    }
    pub fn diagonal_prime(nums: Vec<Vec<i32>>) -> i32 {
        let n = nums.len();
        let mut res = 0;
        for i in 0..n {
            if Solution::is_prime(nums[i][i]) {
                res = max(res, nums[i][i]);
            }
            if Solution::is_prime(nums[i][n - 1 - i]) {
                res = max(res, nums[i][n - 1 - i]);
            }
        }
        res
    }
}