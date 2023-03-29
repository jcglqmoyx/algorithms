impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        let mut res: Vec<String> = Vec::new();
        if nums.is_empty() {
            return res;
        }
        let mut i: usize = 0;
        let mut j: usize = 1;
        while j < nums.len() {
            if nums[j] as i64 - nums[j - 1] as i64 > 1 {
                let len = nums[j - 1] as i64 - nums[i] as i64;
                if len > 0 {
                    res.push(nums[i].to_string() + "->" + &nums[j - 1].to_string());
                } else {
                    res.push(nums[i].to_string());
                }
                i = j;
            }
            j += 1;
        }
        let len = nums[j - 1] as i64 - nums[i] as i64;
        if len > 0 {
            res.push(nums[i].to_string() + "->" + &nums[nums.len() - 1].to_string());
        } else {
            res.push(nums[i].to_string());
        }
        res
    }
}