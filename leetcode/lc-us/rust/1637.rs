use std::cmp::max;

impl Solution {
    pub fn max_width_of_vertical_area(points: Vec<Vec<i32>>) -> i32 {
        let mut res = 0;
        let mut points = points;
        points.sort();
        for i in 1..points.len() {
            res = max(res, points[i][0] - points[i - 1][0])
        }
        res
    }
}