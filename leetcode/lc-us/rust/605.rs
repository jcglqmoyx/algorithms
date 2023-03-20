impl Solution {
    pub fn can_place_flowers(flowerbed: Vec<i32>, n: i32) -> bool {
        let m = flowerbed.len();
        let mut cnt = 0;
        let mut flag = false;
        for i in 0..m {
            if flowerbed[i] == 0 {
                if !flag && (i == m - 1 || flowerbed[i + 1] == 0) {
                    cnt += 1;
                    flag = true;
                } else {
                    flag = false;
                }
            } else {
                flag = true;
            }
        }
        return cnt >= n;
    }
}