select id from Weather as W1
where Temperature > (select Temperature from Weather where recordDate = date_sub(W1.recordDate, interval 1 day));

-- 解法2
-- select w2.id
-- from Weather w1, Weather w2
-- where datediff(w2.recordDate, w1.recordDate) = 1 and w2.Temperature > w1.Temperature

-- 解法3
-- select w2.Id from Weather w1 
-- join Weather w2 on datediff(w2.recordDate, w1.recordDate) = 1 
-- where w2.Temperature > w1.Temperature;
