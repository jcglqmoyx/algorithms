use std::cmp::{max, min};

impl Solution {
    pub fn check_arithmetic_subarrays(nums: Vec<i32>, l: Vec<i32>, r: Vec<i32>) -> Vec<bool> {
        let m = l.len();
        let mut res = vec![false; m];
        for i in 0..m {
            let left = l[i];
            let right = r[i];
            let mut mn = 1e5 as i32;
            let mut mx = -1e5 as i32;
            for j in left..right + 1 {
                mn = min(mn, nums[j as usize]);
                mx = max(mx, nums[j as usize]);
            }
            if (mx - mn) % (right - left) != 0 {
                continue;
            } else if mn == mx {
                res[i] = true;
            } else {
                let diff = (mx - mn) / (right - left);
                let mut st = vec![false; (mx - mn + 1) as usize];
                for j in left..right + 1 {
                    st[(nums[j as usize] - mn) as usize] = true;
                }
                let mut flag = true;
                let mut x = mn + diff;
                while x < mx {
                    if !st[(x - mn) as usize] {
                        flag = false;
                        break;
                    }
                    x += diff;
                }
                res[i] = flag;
            }
        }
        res
    }
}