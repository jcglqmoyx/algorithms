with a as (select paid_to as person, sum(amount) as income
           from transactions
           group by paid_to
           union all
           select paid_by as person, -sum(amount) as income
           from transactions
           group by paid_by)
select user_id,
       user_name,
       ifnull(sum(income), 0) + credit                      as credit,
       if(ifnull(sum(income), 0) + credit < 0, 'Yes', 'No') as credit_limit_breached
from a
         right join users on a.person = users.user_id
group by person