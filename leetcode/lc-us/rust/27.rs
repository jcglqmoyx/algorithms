impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut i: i32 = 0;
        for j in 0..nums.len() {
            if nums[j] == val {
                continue;
            }
            nums[i as usize] = nums[j];
            i += 1;
        }
        i
    }
}