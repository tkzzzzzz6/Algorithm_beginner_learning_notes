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

select device_id,gender,age,university from user_profile where age is not null;