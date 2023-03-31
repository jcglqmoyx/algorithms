impl Solution {
    pub fn arithmetic_triplets(nums: Vec<i32>, diff: i32) -> i32 {
        let mut cnt: Vec<i32> = vec![0; 201];
        for x in nums {
            cnt[x as usize] += 1;
        }
        let mut res = 0;
        for i in 2..201 {
            if i - diff * 2 >= 0 && cnt[i as usize] > 0 && cnt[(i - diff) as usize] > 0 && cnt[(i - diff * 2) as usize] > 0 {
                res += cnt[(i - diff * 2) as usize] * cnt[(i - diff) as usize] * cnt[i as usize];
            }
        }
        res
    }
}