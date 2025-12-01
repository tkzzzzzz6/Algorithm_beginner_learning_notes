impl Solution {
    pub fn max_run_time(n: i32, batteries: Vec<i32>) -> i64 {
        // 计算所有电池容量的总和
        let sum: i64 = batteries.iter().map(|&x| x as i64).sum();
        // 将 n 转为 i64 方便计算
        let n = n as i64;
        // 二分查找的左边界，表示最短运行时间
        let mut left: i64 = 0;
        // 二分查找的右边界，最大平均运行时间
        let mut right: i64 = sum / n;
        // 用于记录满足条件的最大运行时间
        let mut ans: i64 = 0;

        // 二分查找，寻找最大的可行运行时间
        while left <= right {
            let mid = (left + right) / 2; // 尝试的运行时间
            let mut total: i64 = 0;
            // 计算所有电池在最多每台电脑运行 mid 分钟时能提供的电量
            for (&cap) in &batteries {
                total += std::cmp::min(cap as i64, mid);
            }
            // 如果总电量可以支持 n 台电脑运行 mid 分钟
            if total >= n * mid {
                ans = mid;             // 更新答案
                left = mid + 1;        // 尝试更大的运行时间
            } else {
                right = mid - 1;       // 尝试更小的运行时间
            }
        }
        ans // 返回最大运行时间
    }
}
