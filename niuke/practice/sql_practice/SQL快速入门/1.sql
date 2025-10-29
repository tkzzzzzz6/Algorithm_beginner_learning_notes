select * from user_profile;

select device_id,gender,age,university from user_profile;

select distinct university from user_profile;

select device_id from user_profile limit 2;

select device_id as user_infos_example from user_profile limit 2;

select device_id,university from user_profile where university = '北京大学';

select device_id,gender,age,university from user_profile where age > 24;

-- 8
select device_id,gender,age from user_profile where age between 20 and 23;

select device_id,gender,age,university from user_profile where university != '复旦大学';

-- 10
select device_id,gender,age,university from user_profile where age is not null;

-- 11
select device_id,gender,age,university,gpa from user_profile where gpa > 3.5 and gender = 'male';

-- 12
select device_id,gender,age,university,gpa from user_profile where university = "北京大学" or gpa > 3.7;

-- 13
select device_id,gender,age,university,gpa from user_profile where university in ('北京大学','复旦大学','山东大学');

--14

select device_id,gender,age,university,gpa from user_profile 
where (university = '山东大学' and gpa > 3.5) 
or (university = '复旦大学' and gpa > 3.8) 
order by device_id ;

--15
select device_id,age,university from user_profile where university like '%北京%';

--16
select gpa from user_profile where university = '复旦大学' order by gpa desc limit 1;

--17
select count(*) as male_num,avg(gpa) as avg_gpa from user_profile where gender = 'male';

-- 18
select gender,university,count(*) as user_num,round(avg(active_days_within_30),1) as avg_active_day,round(avg(question_cnt),1) as avg_question_cnt from user_profile group by gender,university order by gender,university;