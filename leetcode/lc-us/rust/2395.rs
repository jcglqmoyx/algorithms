use std::collections::HashSet;

impl Solution {
    pub fn find_subarrays(nums: Vec<i32>) -> bool {
        let mut hash: HashSet<i32> = HashSet::new();
        for i in 1..nums.len() {
            let diff = nums[i] + nums[i - 1];
            if hash.contains(&diff) {
                return true;
            }
            hash.insert(diff);
        }
        false
    }
}