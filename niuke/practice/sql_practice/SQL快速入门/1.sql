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