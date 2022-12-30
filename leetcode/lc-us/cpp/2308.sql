with t as (select 'female'                                 gender
                , 1                                        num1
                , user_id
                , row_number() over (order by user_id asc) num2
           from Genders
           where gender = 'female'
           union all
           select 'other'                                  gender
                , 2                                        num1
                , user_id
                , row_number() over (order by user_id asc) num2
           from Genders
           where gender = 'other'
           union all
           select 'male'                                   gender
                , 3                                        num1
                , user_id
                , row_number() over (order by user_id asc) num2
           from Genders
           where gender = 'male')
select user_id
     , gender
from t
order by num2, num1