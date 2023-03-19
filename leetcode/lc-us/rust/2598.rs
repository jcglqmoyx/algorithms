impl Solution {
    pub fn find_smallest_integer(nums: Vec<i32>, value: i32) -> i32 {
        let mut cnt = [0; 100001];
        for &num in nums.iter() {
            cnt[(((num % (value as i32)) + value) % value) as usize] += 1;
        }
        let mut mex = 0;
        while cnt[(mex % value) as usize] > 0 {
            cnt[(mex % value) as usize] -= 1;
            mex += 1;
        }
        return mex as i32;
    }
}