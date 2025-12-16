-- 计算每台机器的平均处理时间（end - start），LeetCode 1661
-- 修复点：
-- 1) machine_id 拼写错误（meachine_id）
-- 2) SQL 赋值语法错误，需使用 SELECT 列表达式
-- 3) 比较操作符使用 = 而非 ==
-- 4) 需要对相同 process_id 的 start/end 配对
-- 5) 使用 AVG 聚合并按 machine_id 分组


-- 注意：四舍五入应在聚合之后进行，否则是“先四舍五入每行再求平均”，与题意不符
-- MySQL/LeetCode 推荐写法：ROUND(AVG(diff), 3)
SELECT 
    a1.machine_id AS machine_id,
    ROUND(AVG(a2.timestamp - a1.timestamp), 3) AS processing_time
FROM Activity AS a1
JOIN Activity AS a2
  ON a1.machine_id = a2.machine_id
 AND a1.process_id = a2.process_id
 AND a1.activity_type = 'start'
 AND a2.activity_type = 'end'
GROUP BY a1.machine_id;

-- PostgreSQL 写法（同上）：ROUND(AVG(a2.timestamp - a1.timestamp)::numeric, 3)
-- SQL Server 写法：ROUND(AVG(DATEDIFF(SECOND, a1.timestamp, a2.timestamp)*1.0), 3)
