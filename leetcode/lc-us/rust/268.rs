impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let n = nums.len() + 1;
        let mut sum = n * (n - 1) / 2;
        for &x in nums.iter() {
            sum -= x as usize;
        }
        sum as i32
    }
}
