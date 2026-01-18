struct Solution;

impl Solution {
    pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
        let mut res = 0;
        for i in 1..points.len() {
            let p = &points[i - 1];
            let q = &points[i];
            res += (p[0] - q[0]).abs().max((p[1] - q[1]).abs()); // 切比雪夫距离
        }
        res
    }
}
